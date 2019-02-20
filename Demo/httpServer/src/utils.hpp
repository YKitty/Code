#ifndef __M_UTILLS_H__
#define __M_UTILLS_H__

#include <iostream>
#include <string.h>
#include <time.h>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/stat.h>

#define LOG(...) do{\
        fprintf(stdout, __VA_ARGS__);\
    }while(0)

#define MAX_HTTPHDR 4096
#define WWWROOT "www"
#define MAX_PATH 256

std::unordered_map<std::string, std::string> g_err_desc = {
  {"200", "OK"};
  {"400", ""}
}

class Utils 
{
public:
  static int Split(std::string& src, const std::string& seg, std::vector<std::string>& list)
  {
    //分割成了多少数据
    int num = 0;
    size_t idx = 0;
    size_t pos;
    while (idx < src.length())
    {
      pos = src.find(seg, idx);
      if (pos == std::string::npos)
      {
        break;
      }
      list.push_back(src.substr(idx, pos - idx));
      num++;
      idx = pos + seg.length();
    }

    //最后还有一条
    if (idx < src.length())
    {
      list.push_back(src.substr(idx, pos - idx));
      num++;
    }
    return num;
  }

  static const std::string GetErrDesc(std::string &code)
  {

    auto it = g_err_desc.find(code);
    if (it == g_err_desc.end())
    {
      return "Unknown Error";
    }

    return it->second;
  }

  //gmtime 将一个时间戳转换为一个结构体
  //shifttime 将一个时间转为一个格式
  static void TimeToGmt(time_t t, std::string& gmt)
  {
    struct tm *mt = gmtime(&t);
    char tmp[128] = { 0 };
    int len;
    len = strftime(tmp, 127, "%a, %d %b %Y %H:%M:%S GMT", mt);
    gmt.assign(tmp, len);
  }

  static void DigitToStr(int64_t num, std::string& str)
  {
    std::stringstream ss;
    ss << num;
    str = ss.str();
  }

  static int64_t StrToDigit(std::string& str)
  {
    int64_t num;
    std::stringstream ss;
    ss << str;
    ss >> num;
  }
  static void MakeETag(int64_t size, int64_t ino, int64_t mtime, std::string& etag)
  {
    //"ino-size-mtime"
    std::stringstream ss;
    ss << "\"" << std::hex << ino << "-" << std::hex << size << "-" << std::hex << mtime << "\"";
    etag = ss.str();
  }
};

//包含HttpRequest解析出来的请求信息
class RequestInfo
{
public:
  //请求方法
  std::string _method;
  //协议版本
  std::string _version;
  //资源路径
  std::string _path_info;
  //资源实际路径
  std::string _path_phys;
  //查询字符串
  std::string _query_string;
  //头部当中的键值对
  std::unordered_map<std::string, std::string> _hdr_list;
  //获取文件信息
  struct stat _st;
public:
  std::string _err_code;
public:
  void SetError(const std::string& code)
  {
    _err_code = code;
  }

  bool RequestIsCGI()
  {
    if ((_method == "GET" && !_query_string.empty()) || (_method == "POST"))
    {
      return  true;
    }
    return false;
  }
};

//http数据的接收接口
//http数据的解析接口
//对外提供能够获取处理结构的接口
class HttpRequest
{
private:
  int _cli_sock;
  std::string _http_header;
  RequestInfo _req_info;

public:
  HttpRequest(int sock)
    : _cli_sock(sock)
  {}

  //接收http请求头
  bool RecvHttpHeader(RequestInfo& info)
  {
    //定义一个设置http头部最大值
    char tmp[MAX_HTTPHDR];
    while (1)
    {
      //预先读取，不从缓存区中把数据拿出来
      int ret = recv(_cli_sock, tmp, MAX_HTTPHDR, MSG_PEEK);
      //读取出错，或者对端关闭连接
      if (ret <= 0)
      {
        //EINTR表示这次操作被信号打断，EAGAIN表示当前缓存区没有数据
        if (errno == EINTR || errno == EAGAIN)
        {
          continue;
        }
        info.SetError("500");
        return false;
      }
      //ptr为NULL表示tmp里面没有\r\n\r\n
      char* ptr = strstr(tmp, "\r\n\r\n");
      //当读了MAX_HTTPHDR这么多的字节，但是还是没有把头部读完，说明头部过长了
      if ((ptr == NULL) && (ret == MAX_HTTPHDR))
      {
        info.SetError("413");
        return false;
      }
      //当读的字节小于这么多，并且没有空行出现，说明数据还没有从发送端发送完毕，所以接收缓存区，需要等待一下再次读取数据
      else if ((ptr == NULL) && (ret < MAX_HTTPHDR))
      {
        usleep(1000);
        continue;
      }

      int hdr_len = ptr - tmp;
      _http_header.assign(tmp, hdr_len);
      recv(_cli_sock, tmp, hdr_len + 4, 0);
      LOG("header:%s\n", _http_header.c_str());
      break;
    }

    return true;
  }
  
  //判断地址是否合法,并且将相对路径信息转换为绝对路径信息
  bool PathIsLegal(std::string& path, RequestInfo &info)
  {
    std::string file = WWWROOT + path;
    //文件不存在
    if (stat(file.c_str(), &(info._st)) < 0)
    {
      info._err_code = "404";
      return false;
    }
    
    char tmp[MAX_PATH] = { 0 };
    realpath(file.c_str(), tmp);

    info._path_phys = tmp;
    if (info._path_phys.find(WWWROOT) == std::string ::npos)
    {
      info._err_code = "403";
      return false;
    }
    return true;
  }

  bool ParseFirstLine(std::string& line, RequestInfo& info)
  {
    ////请求方法
    //std::string _method;
    ////协议版本
    //std::string _version;
    ////资源路径
    //std::string _path_info;
    ////资源实际路径
    //std::string _path_phys;
    ////查询字符串
    //std::string _query_string;
    std::vector<std::string> line_list;
    if (Utils::Split(line, " ", line_list) != 3)
    {
      info._err_code = "400";
      return false;
    }

    std::string url;
    //方法
    info._method = line_list[0];
    url = line_list[1];
    info._version = line_list[2];

    if (info._method != "GET" && info._method != "POST" && info._method != "HEAD")
    {
      info._err_code = "405";
      return false;
    }
    if (info._version != "HTTP/0.9" && info._version != "HTTP/1.0" && info._version != "HTTP/1.1")
    {
      info._err_code = "400";
      return false;
    }
    //解析URL
    //url : /upload?key=val&key=val
    size_t pos;
    pos = url.find("?");
    //没有?说明没有参数
    if (pos == std::string::npos)
    {
      info._path_info = url;
    }
    else 
    {
      info._path_info = url.substr(0, pos);
      info._query_string = url.substr(pos + 1);
    }

    PathIsLegal(info._path_info, info);
    //realpath()将相对路径转换为绝对路径，如果不存在直接崩溃
    //info._path_phys = WWWROOT + info._path_info;
    return true;
  }

  //解析http请求头
  bool ParseHttpHeader(RequestInfo& info)
  {
    //http请求头解析
    //请求方法 URL 协议版本\r\n
    //key: val\r\nkey: val
    std::vector<std::string> hdr_list;//头信息的数组
    Utils::Split(_http_header, "\r\n", hdr_list);
    
    //测试将请求头进行分割到hdr_list中
    //for (size_t i = 0; i < hdr_list.size(); i++)
    //{
    //  std::cout << hdr_list[i] << std::endl;
    //  //size_t pos = hdr_list[i].find(": ");
    //  //info._hdr_list[hdr_list[i].substr(pos, pos)] = hdr_list[i].substr(pos + 2);
    //}
    //std::cout << std::endl << "\n\n\n\n\n\n";

    ParseFirstLine(hdr_list[0], info);
    //将首行删除
    //hdr_list.erase(hdr_list.begin());
    //将所有的头部key: val进行存放
    for (size_t i = 1; i < hdr_list.size(); i++)
    {
      size_t pos = hdr_list[i].find(": ");
      info._hdr_list[hdr_list[i].substr(0, pos)] = hdr_list[i].substr(pos + 2);
    }

    for (auto it = info._hdr_list.begin(); it != info._hdr_list.end(); it++)
    {
      std::cout << "[ " << it->first << "] = [" << it->second << "]" << std::endl;
    }

    return true;
  }

  //向外提供解析结果
  RequestInfo& GetRequestInfo(); 
};

//文件请求接口(完成文件下载/列表功能)接口
//CGI请求接口
class HttpResponse
{
private:
  int _cli_sock;
  //表明这个文件是否是源文件，是否修改过
  //Etag: "inode-fsize-mtime"\r\n
  std::string _etag;
  //文件最后一次修改时间
  std::string _mtime;
  //系统响应时间
  std::string _date;

public:
  HttpResponse(int sock)
    : _cli_sock(sock)
  {}

  //初始化的一些请求响应信息
  bool InitResponse(RequestInfo req_info)
  {
    req_info._st.st_size;
    req_info._st.st_ino;
    req_info._st.st_mtime;
    //Last-Modified
    Utils::DigitToStr(req_info._st.st_mtime, _mtime);
    //ETag
    Utils::MakeETag(req_info._st.st_size, req_info._st.st_ino, req_info._st.st_mtime, _etag);
    //Date
    time_t t = time(NULL);
    Utils::TimeToGmt(t, _date);
    return true;
  }

  bool SendData(std::string buf)
  {
    if (send(_cli_sock, buf.c_str(), buf.length(), 0) < 0)
    {
      return false;
    }
    return true;
  }

  bool SendCData(const std::string& buf)
  {
    //发送hello 
    //05\r\n
    //hello\r\n
    //最后一个分块
    //0\r\n\r\n
    if (buf.empty())
    {
      SendData("0\r\n\r\n");
    }
    std::stringstream ss;
    ss << std::hex << buf.length() << "\r\n";
    SendData(ss.str());
    ss.clear();
    SendData(buf);
    SendData("\r\n");
  }

  //文件下载功能
  bool ProcessFile(RequestInfo& info)
  {
    return true;
  }
  //文件列表功能
  bool ProcessList(RequestInfo& info)
  {
    //组织头部信息：
    //首行
    //COntent-Length: text/html\r\n
    //ETag:
    //Date:
    //Connection: close\r\n\r\n
    //Transfer-Encoding: chunked\r\n  分块传输
    //正文：
    //每一个目录下的文件都要阻止一个html标签信息
    std::string rsp_header;
    rsp_header = info._version + " 200 OK\r\n";
    rsp_header += "Connection: close\r\n";
    if (info._version == "HTTP/1.1")
    {
      rsp_header += "Transfer-Encoding: chunked\r\n";
    }
    rsp_header += "ETag: " + _etag + "\r\n";
    rsp_header += "Last-Modified: " + _mtime + "\r\n\r\n";
    rsp_header += "Date: " + _date + "\r\n\r\n";
    SendData(rsp_header);

    std::string rsp_body;
    rsp_body = "<html><head>";
    rsp_body += "<title>" + info._path_info + "</title>";
    rsp_body += "<meta charset='UTF-8'>";
    rsp_body += "</head><body>";
    rsp_body += "<h1>" + info._path_info + "</h1><hr />";
    SendCData(rsp_body);
    {
      //scandir函数
      //获取目录下的每一个文件，组织出html信息，chunk传输
      std::string file_html;
      SendCData(file_html);
    }
    rsp_body = "</body></html>";
    SendCData(rsp_body);
    SendData("");

    return true;
  }
  //cgi请求的处理
  bool ProcessCGI(RequestInfo& info)
  {
    return true;
  }
  //处理出错响应
  bool ErrHandler(RequestInfo& info)
  {
    std::string rsp_header;
    //首行 协议版本 状态码 状态描述\r\n
    //头部 Content-Length Date 
    //空行 
    //正文 rsp_body = "<html><body><h1>404<h1></body></html"
    rsp_header = info._version + " " + info._err_code + " ";
    rsp_header += Utils::GetErrDesc(info._err_code) + "\r\n";

    time_t t = time(NULL);
    std::string gmt;
    Utils::TimeToGmt(t, gmt);
    rsp_header += "Date: " + gmt + "\r\n";
    std::string rsp_body;
    rsp_body = "<html><body><h1>" + info._err_code + "<h1></body></html>";

    std::string cont_len;
    Utils::DigitToStr(rsp_body.length(), cont_len);
    rsp_header += "Content-Length: " + cont_len + "\r\n\r\n";

    send(_cli_sock, rsp_header, );
    return true;
  }
  
  bool CGIHandler(RequestInfo& info)
  {
    //初始化CGI信息
    InitResponse(info);
    //执行CGI响应
    ProcessCGI(info);
    return true;
  }

  bool FileIsDir(RequestInfo& info)
  {
    if (info._st.st_mode & S_IFDIR)
    {
      return true;
    }
    return false;
  }

  bool FileHandler(RequestInfo& info)
  {
    //初始化文件响应信息
    InitResponse(info);
    //执行文件列表展示响应
    if (FileIsDir(info))
    {
      ProcessList(info);
    }
    //执行文件下载响应
    else 
    {
      ProcessFile(info);
    }
    return true;
  }
};


#endif //__M_UTILLS_H__