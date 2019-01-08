#include "TcpServer.hpp"
#include <unordered_map>

std::unordered_map<std::string, std::string> g_dict;

void Translate(const std::string& req, std::string* resp)
{
  auto it = g_dict.find(req);
  if (it == g_dict.end())
  {
    *resp = "未查到";
    return ;
  }
  *resp = it->second;
}
void InitDict()
{
  g_dict.insert(std::make_pair("hello", "你好"));
  g_dict.insert(std::make_pair("fairy", "小仙女"));
  g_dict.insert(std::make_pair("ISorry", "我错了"));
  g_dict.insert(std::make_pair("DKloveDY", "大凯爱大祎"));
  g_dict.insert(std::make_pair("DK", "大凯"));
  g_dict.insert(std::make_pair("DY", "大祎"));
  g_dict.insert(std::make_pair("love", "爱"));
}

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

  InitDict();
  
  TcpServer* sp = new TcpServer(argv[1], atoi(argv[2]));
  sp->InitServer();
  sp->Start(Translate);
  delete sp;
  return 0;
}
