#pragma once 

#include <iostream>
#include <string>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <arpa/inet.h>
#include <signal.h>

class Sock 
{
private:
  int sock;
  std::string ip;
  int port;

public:
  Sock()
    : ip("yk")
    , port(0)
  {}

  Sock(const std::string& ip_, const int& port_)
    : ip(ip_)
    , port(port_)
  {}

  ~Sock()
  {
    close(sock);
  }

  void Close()
  {
    close(sock);
  }

  void Socket()
  {
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
      std::cerr << "socket error!" << std::endl;
      exit(2);
    }
  }

  void Bind()
  {
    sockaddr_in local;
    bzero(&local, sizeof(local));
    local.sin_family = AF_INET;
    local.sin_addr.s_addr = inet_addr(ip.c_str());
    local.sin_port = htons(port);
    if (bind(sock, (sockaddr*)&local, sizeof(local)) < 0)
    {
      std::cerr << "bind error!" << std::endl;
      exit(3);
    }
  }

  void Listen()
  {
    //这里的5是为了，连接服务器的时候
    //该服务器只可以被一个客户端连接
    //这个5就是等待队列，对于无法连接到服务器的上的客户端进行等待的
    if (listen(sock, 5) < 0)
    {
      std::cerr << "listen error" <<std::endl;
      exit(4);
    }
  }

  bool Accept(Sock* new_sock)
  {
    sockaddr_in addr;
    socklen_t len = sizeof(addr);
    int newSock = accept(sock, (sockaddr*)&addr, &len);
    if (newSock < 0)
    {
      std::cerr << "accept error!" << std::endl;
      exit(5);
    }
    new_sock->sock = newSock;
    //new_sock.ip = inet_ntoa(addr.sin_addr);
    //new_sock.port = ntohs(addr.sin_port);
    return true;
  }

  bool Recv(std::string& str_)
  {
    char buf[1024];
    ssize_t s = recv(sock, buf, sizeof(buf), 0);
    if (s > 0)
    {
      buf[s] = 0;
      str_ = buf;
      return true;
    }
    else if (s <= 0)
    {
      //std::cerr << "recv error!" << std::endl;
      return false;
    }
    return true;
  }

  void Send(std::string& str_)
  {
    send(sock, str_.c_str(), str_.size(), 0); 
  }
};

#include <functional>
typedef std::function<void (const std::string&, std::string*)> Handler;

class TcpServer 
{
private:
  Sock sock;

public:
  TcpServer(std::string ip_, int port_)
    : sock(ip_, port_)
  {
    //完成父进程对于子进程退出时发送的信号SIGCHLD，如何来处理
    signal(SIGCHLD, SIG_IGN);
  }

  void InitServer()
  {
    sock.Socket();
    sock.Bind();
    sock.Listen();
  }
  
  void ProcessConnect(Sock new_sock, Handler handler)
  {
    int id = fork();
    if (id > 0)
    {
      //parent
      //对于父进程要关闭自己所拥有的socket文件描述符
      new_sock.Close();
      return;
    }
    else 
    {
      //child
      for ( ; ; )
      {
        std::string req;
        //一直在接收请求，如果没有接收到就跳出循环
        new_sock.Recv(req);
        std::cout << "client# " << req << std::endl;
        std::string resp;
        handler(req, &resp);
        //req += "server";
        new_sock.Send(resp);
        std::cout << "server echo success!" << std::endl;
      }
      
    }
  }

  void Start(Handler handler)
  {
    //进行accept
    for ( ; ; )
    {
      Sock new_sock;

      //如果没有接受到请求就重新开始循环
      if (!sock.Accept(&new_sock))
        continue;
      std::cout << "clinet connect successed!" << std::endl;
      ProcessConnect(new_sock, handler);
    }
  }
  
  ~TcpServer()
  {
  }

};
