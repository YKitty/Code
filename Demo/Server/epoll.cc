#include "epoll.hpp"


void EpollServer::Start()//绑定套接字
{
  _listenfd = socket(PF_INET, SOCK_STREAM, 0);
  if (_listenfd == -1)
  {
    std::cerr  << 
  }
}

void EventLoop();//epoll的事件循环
