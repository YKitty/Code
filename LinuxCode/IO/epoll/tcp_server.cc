#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <arpa/inet.h>

void Usage(char* proc)
{
  std::cout << proc << " port" << std::endl;
}

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    Usage(argv[0]);
    exit(1);
  }
  int lst_fd, cli_fd;
  //用来存放所要bind结构体大小
  socklen_t len;
  //ep_fd是一个句柄，用来控制epoll的;nfds表示的是每次等待之后就绪的文件描述符的个数
  int ep_fd, nfds;
  struct sockaddr_in lst_addr, cli_addr;
  //evs用来存放的是每次准备就绪的文件描述符
  struct epoll_event evs[1024], ev;
  //创建监听套接字
  lst_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (lst_fd < 0)
  {
    std::cerr << "socket error!" <<std::endl;
    exit(2);
  }
  //绑定套接字
  lst_addr.sin_family = AF_INET;
  lst_addr.sin_port = htons(atoi(argv[1]));
  //表示监听的是这个局域网上所有的IP地址
  lst_addr.sin_addr.s_addr = INADDR_ANY;
  len = sizeof(lst_addr);
  if (bind(lst_fd, (struct sockaddr*)&lst_addr, len) < 0)
  {
    std::cerr << "bind error!" << std::endl;
    exit(3);
  }

  //监听套接字
  if (listen(lst_fd, 5) < 0)
  {
    std::cerr << "listen error!" << std::endl;
    exit(4);
  }

  //创建epoll
  ep_fd = epoll_create(1024);
  if (ep_fd < 0)
  {
    std::cerr << "epoll_create error!" << std::endl;
    exit(5); 
  }
  //创建epoll结点
  ev.events = EPOLLIN;
  ev.data.fd = lst_fd;
  //将结点加入到epoll中，直接加到内核当中，也就是那个红黑树
  if (epoll_ctl(ep_fd, EPOLL_CTL_ADD, lst_fd, &ev) < 0)
  {
    std::cerr << "epoll_ctl error!" << std::endl;
    exit(6);
  }

  for ( ; ; )
  {
    //1024表示最大可同时等待多少个事件，evs用来存放等待成功的事件的
    nfds = epoll_wait(ep_fd, evs, 1024, 3000);
    if (nfds < 0)
    {
      std::cerr << "epoll_wait error!" << std::endl;
      continue;
    }

    else if (nfds == 0)
    {
      std::cout << "timeout!" << std::endl;
      continue;
    }

    //到这里表示等待成功了
    for (int i = 0; i < nfds; i++)
    {
      //表示等待的是监听描述符
      if (evs[i].data.fd == lst_fd)
      {
        //进行连接
        cli_fd = accept(lst_fd, (struct sockaddr*)&cli_addr, &len); 
        if (cli_fd < 0)
        {
          std::cerr << "accept error!" << std::endl;
          continue;
        }
        //创建客户端结点事件，并且加入到epoll中
        ev.events = EPOLLIN;
        ev.data.fd = cli_fd;
        if (epoll_ctl(ep_fd, EPOLL_CTL_ADD, cli_fd, &ev) < 0)
        {
          std::cerr << "epoll_ctl error!" << std::endl;
          continue;
        }
      }
      //表示等待的是可读事件
      else if (evs[i].events & EPOLLIN)
      {
        //接收消息并且发送消息给客户端
        char buf[1024] = { 0 };
        if (recv(evs[i].data.fd, buf, 1023, 0) < 0)
        {
          //接收失败就从epoll集合中取出这个事件，将这个时间放在ev中
          epoll_ctl(ep_fd, EPOLL_CTL_DEL, evs[i].data.fd, &ev);
          close(evs[i].data.fd);
          continue;
        }

        std::cout << "client say# " << buf << std::endl;
        send(evs[i].data.fd, "what???", 7, 0);
      }
    }
  }



  

  return 0;
}

