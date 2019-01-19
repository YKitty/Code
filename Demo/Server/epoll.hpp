#define __EPOLL_H__
#ifdef __EPOLL_H__ 

#include "common.hpp"

class EpollServer
{
public:
  EpollServer(int port = 8000)
    : _port(port)
    , _listenfd(-1)
    , _eventfd(-1)
  {

  }

  ~EpollServer()
  {
    if (_listenfd)
    {
      close(_listenfd);
    }
  }

  void Start();//绑定套接字
  void EventLoop();//epoll的事件循环


protected:
  int _port; //端口，ip是本机
  int _listenfd; //监听描述符
  int _eventfd; //事件描述符
};





#endif //__EPOLL_H__ 
