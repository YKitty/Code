#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <arpa/inet.h>

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
  
  std::string message;
  char buf[1024];
  for ( ; ; )
  {
    std::cout << "Please Enter# ";
    std::cin >> message;
    send(sock, message.c_str(), message.size(), 0);
    ssize_t s = recv(sock, buf, sizeof(buf), 0);
    buf[s] = 0;
    std::cout << "server echo# " << buf << std::endl;
  }


}
