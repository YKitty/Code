#include "TcpServer.hpp"

void Usage(std::string proc_)
{
  std::cout << "Usage: " << proc_ << "ip  port" << std::endl;
}

int main(int argc, char* argv[])
{
  if (argc != 3)
  {
    Usage(argv[0]);
    exit(1);
  }
  
  TcpServer* sp = new TcpServer(argv[1], atoi(argv[2]));
  sp->InitServer();
  sp->Start(NULL);
  delete sp;
  return 0;
}
