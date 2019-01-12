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

      std::unordered_map<std::string, std::string> dict;
      dict.insert(std::make_pair("hello", "你好"));
      dict.insert(std::make_pair("apple", "苹果"));
      dict.insert(std::make_pair("world", "世界"));
      dict.insert(std::make_pair("xust", "西安科技大学"));
      for ( ; ; )
      {
        char buf[1024];
        int s;
        std::string req;
        //一直在接收请求，如果没有接收到就跳出循环
        if ((s = recv(sock, buf, sizeof(buf), 0)) > 0)
        {
          buf[s] = 0;
          req = buf; 
          std::cout << "client# " << req << std::endl;
          std::string resp;
          resp = dict[req];
          if (resp.empty())
          {
            resp = "null";
          }
          //req += "server";
          send(sock, resp.c_str(), resp.size(), 0);
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
      
      //这里对于服务器与客户端进行通信的时候，只需要一次就好了，所以就不需要进行死循环
      char buf[10240];
      memset(buf, 0, sizeof(buf));
      if (recv(new_sock, buf, sizeof(buf), 0) < 0)
      {
        std::cerr << "recv error!" << std::endl;
      }
      std::cout << "requst: " << buf << std::endl;
      
      char ouput_buf[1024];
      memset(ouput_buf, 0, sizeof(ouput_buf));
      const char* hello = "<h1>hello world</h1>";
      sprintf(ouput_buf, "HTTP/1.0 200 OK\nContent-Length:%lu\n\n%s", strlen(hello), hello);
      send(new_sock, ouput_buf, sizeof(ouput_buf), 0);
    }
  }
  
  ~TcpServer()
  {
  }

};
