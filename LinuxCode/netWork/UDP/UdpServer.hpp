#pragma once 
#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

class Sock
{
private:
  int sock;
  std::string ip;
  int port;

public:
  Sock(std::string& ip_, int& port_)
    : ip(ip_)
    , port(port_)
  {}

  void Socket()
  {
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0)
    {
      std::cerr << "socket error!" << std::endl;
      exit(2);
    }
  }

  void Bind()
  {
    struct sockaddr_in local_;
    local_.sin_family = AF_INET;
    local_.sin_port = htons(port);//将对于端口号本机字节序改为网络字节序
    local_.sin_addr.s_addr = inet_addr(ip.c_str());
    if (bind(sock, (struct sockaddr*)&local_, sizeof(local_)) < 0)
    {
      std::cerr << "bind error" << std::endl;
      exit(3);
    }
  }

  void Recv(std::string& str_, struct sockaddr_in& peer, socklen_t& len)
  {
    char buf[1024];
    len = sizeof(sockaddr_in);
    ssize_t s = recvfrom(sock, buf, sizeof(buf), 0, (struct sockaddr*)&peer, &len);
    if (s > 0)
    {
      buf[s] = 0;
      str_ = buf;
    }
  }
  
  void Send(std::string& str_, struct sockaddr_in& peer, socklen_t& len)
  {
    sendto(sock, str_.c_str(), str_.size(), 0, (struct sockaddr*)&peer, len);
  }

  ~Sock()
  {
    close(sock);
  }
};

//c语言写法
//typedef void (*Handler)(const std::string& req, std::string* resp);
//c++的写法，可以能够兼容函数指针，仿函数和lamda
#include <functional>
typedef std::function<void (const std::string&, std::string*) > Handler;

class UdpServer 
{
private:
  Sock sock;

public:
  UdpServer(std::string ip_, int port_)
    : sock(ip_, port_)
  {}
  
  //完成对于socket的创建以及绑定
  void InitServer()
  {
    sock.Socket();
    sock.Bind();
  }

  void Start(Handler handler)
  {
    struct sockaddr_in peer;
    socklen_t len;
    std::string message;
    for ( ; ; )
    {
      sock.Recv(message, peer, len);
      std::cout << "client# " << message << std::endl;
      std::cout << "[" << inet_ntoa(peer.sin_addr) << ":" << ntohs(peer.sin_port) << "]#" << message << std::endl;
      //message += " server";
      //完成对于单词的翻译
      std::string resp ;
      handler(message, &resp);
      sock.Send(resp, peer, len);
      std::cout << "server echo success!" << std::endl;
    }
  }

  ~UdpServer()
  {

  }
};
