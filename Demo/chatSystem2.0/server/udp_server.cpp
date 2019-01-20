#include "udp_server.h"
#include "data.h"

udp_server::udp_server(int _port)
  : port(_port)
{}

void udp_server::init_server()
{
  sock = socket(AF_INET, SOCK_DGRAM, 0);
  if (sock < 0)
  {
    std::cerr << "socket error!" << std::endl;
    return;
  }
  
  struct sockaddr_in local;
  local.sin_family = AF_INET;
  local.sin_port = htons(port);
  local.sin_addr.s_addr = htonl(INADDR_ANY);
  if (bind(sock, (struct sockaddr*)&local, sizeof(local)) < 0)
  {
    std::cerr << "bind error!" << std::endl;
    return;
  }
}

void udp_server::recv_data(std::string& out_string)
{
  char buf[SIZE];
  struct sockaddr_in peer;
  socklen_t len = sizeof(peer);
  ssize_t s =recvfrom(sock, buf, SIZE, 0, (struct sockaddr*)&peer, &len);
  if (s > 0)
  {
    buf[s] = 0;
    out_string = buf;
    pool.put_message(out_string);
    data d;
    d.unserialize(out_string);

    online_key key;
    key += inet_ntoa(peer.sin_addr.s_addr);
    key += ()peer.sin_port;
    //根据key值删除，该ip地址（客户端）
    if (d.type == "quit")
    {
      std::map<online_key,struct sockaddr_in>::iterator iter = online.find(value);
      if(iter != online.end())

        online.erase(iter->first);
      }

    }
    else 
    {
      online.insert(std::pair<online_key, struct sockaddr_in>(value, peer));
    }
  }
  else 
  {
  }
}

void udp_server::send_data(const std::string& in_string,\
    const struct sockaddr_in &peer)
{
  sendto(sock, in_string.c_str(), in_string.size(), 0,\
      (struct sockaddr*)&peer, sizeof(peer));
}

void udp_server::broadcast()//广播
{
  std::string message;
  pool.get_message(message);
  
  std::map<online_key, struct sockaddr_in>::iterator iter = online.begin();
  for (; iter != online.end(); iter++)
  {
    send_data(message, iter->second);
  }
      
}

udp_server::~udp_server()
{
  close(sock);
  port = -1;
}
