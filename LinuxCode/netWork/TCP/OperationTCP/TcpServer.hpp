#pragma once 

#include <iostream>
#include <string>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <arpa/inet.h>
#include "ThreadPool.hpp"
#include <unordered_map>
#include "Comm.hpp"
#include <string.h>

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

  int GetSock()
  {
    return sock;
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

  bool Accept(int* new_sock)
  {
    sockaddr_in addr;
    socklen_t len = sizeof(addr);
    *new_sock = accept(sock, (sockaddr*)&addr, &len);
    if (*new_sock < 0)
    {
      std::cerr << "accept error!" << std::endl;
      exit(5);
    }
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
//typedef std::function<void (const std::string&, std::string*)> Handler;

class TcpServer 
{
private:
  Sock sock;

public:
  TcpServer(std::string ip_, int port_)
    : sock(ip_, port_)
  {}

  void InitServer()
  {
    sock.Socket();
    sock.Bind();
    sock.Listen();
  }
  
  //service函数必须只能有一个成员变量
  static void Service(int sock)
  {
    for ( ; ; )
    {
      int s;
      response resp;
      request req;
      resp.status = 0;
      memset(&req, 0, sizeof(req));
      memset(&resp, 0, sizeof(resp));
      //一直在接收请求，如果没有接收到就跳出循环
      if ((s = recv(sock, &req, sizeof(req), 0)) > 0)
      {
        std::cout << "recv client!" << std::endl;
        switch(req.cal)
        {
          case 0:
            resp.result = req.x + req.y;
            break;
          case 1:
            resp.result = req.x - req.y;
            break;
          case 2:
            resp.result = req.x * req.y;
            break;
          case 3:
            resp.result = req.x / req.y;
            if ((req.y < 0.0000000001) && (req.y > -0.0000000001))
            {
              resp.status = 1;
            }
            break;
          case 4:
            resp.result = (int)req.x % (int)req.y;
            break;
          default:
            resp.status = 2;
            std::cout << "cal error!" << std::endl;
            break;
        }
        send(sock, &resp, sizeof(resp), 0);//对于send和recv是从当前地址开始发送sizeof(resp)大小的数据
        std::cout << "server echo success!" << std::endl;
      }
      else if (s == 0)
      {
        std::cout << "client quit!" << std::endl;
      }
      else 
      {
        std::cerr << "recv error!" << std::endl;
      }
    }
    close(sock);
  }

  void Start()
  {
    //进行accept
    for ( ; ; )
    {
      int new_sock;
      //如果没有接受到请求就重新开始循环
      if (!sock.Accept(&new_sock))
        continue;
      std::cout << "clinet connect successed!" << std::endl;      

      //创建任务并增加到线程池
      Task* t = new Task(new_sock, TcpServer::Service);
      Pool* p = new Pool(5);
      p->InitPool();
      p->AddTask(*t);
    }
  }
  
  ~TcpServer()
  {
  }

};
