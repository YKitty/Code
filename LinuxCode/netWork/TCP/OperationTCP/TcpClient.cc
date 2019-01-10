#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <arpa/inet.h>
#include <string.h>
#include "Comm.hpp"

void Usage(std::string proc_)
{
  std::cout << "Usage: " << proc_ << "ip port" << std::endl;
}

int main(int argc, char* argv[])
{
  if (argc != 3)
  {
    Usage(argv[0]);
    exit(1);
  }

  int sock;
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0)
  {
    std::cerr << "socket error!" << std::endl;
    exit(2);
  }

  sockaddr_in addr;
  bzero(&addr, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = inet_addr(argv[1]);
  addr.sin_port = htons(atoi(argv[2]));
  if (connect(sock, (sockaddr*)&addr, sizeof(addr)) < 0)
  {
    std::cout << "connect error!" << std::endl;
    exit(3);
  }
  std::cout << "client connnect succesed!" << std::endl;
  
  request req;
  response resp;
  
  memset(&req, 0, sizeof(req));
  memset(&resp, 0, sizeof(resp));
  for ( ; ; )
  {
    std::cout << "Please Enter(x, y, operation:01234 +-*/%)# ";
    std::cin >> req.x >> req.y >> req.cal;
    send(sock, &req, sizeof(req), 0);//序列化:采用指针的方式
    recv(sock, &resp, sizeof(resp), 0);
    std::cout << "status: " << resp.status << std::endl;
    std::cout << "result: " << resp.result << std::endl;
  }


}
