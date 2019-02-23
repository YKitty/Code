#include "utils.hpp"

enum _boundry_type
{
  BOUNDARY_NO = 0,
  BOUNDARY_FIRST,
  BOUNDARY_MIDDLE,
  BOUNDARY_LAST,
  BOUNDARY_PART  //部分boundary
};

class Upload
{
private:
  int _file_fd;
  int64_t content_len;
  std::string _file_name;
  std::string _f_boundary;//first
  std::string _m_boundary;//middle
  std::string _l_boundary;//last

private:
  //只要匹配带一个\r\n都假设他有可能是middle_boundary，blen(buffer的长度)匹配的长度
  int MatchBoundary(char* buf, size_t blen, int* boundary_pos)
  {
    //----boundary 
    //first_boundary:   ------boundary 
    //middle_boundary:  \r\n------boundary\r\n 
    //last_boundary:    \r\n------boundary--
    //middle_boundary和last_boundary的长度是一样的
    //从起始位置匹配first_bounday，如果匹配成功的话，这个boundary的位置就是开始位置，下标为0
    if (!memcpy(buf, _f_boundary.c_str(), _f_boundary.length()))
    {
      *boundary_pos = 0;
      return BOUNDARY_FIRST;
    }

    for (size_t i = 0; i < blen; i++)
    {
      //如果剩余的长度大于boundary的长度就进行完全匹配，否则进行部分匹配
      if ((blen - i) > _m_boundary.length())
      {
        if (!memcmp(buf + i, _m_boundary.c_str(), _m_boundary.length()))
        {
          *boundary_pos = i;
          return BOUNDARY_MIDDLE;
        }
        else if (!memcmp(buf + i, _l_boundary.c_str(), _l_boundary.length()))
        {
          *boundary_pos = i;
          return BOUNDARY_LAST;
        }
      }
      else 
      {
        //剩余长度小于boundary，防止出现半个boundary,所以进行部分匹配
        int cmp_len = (blen - i) > _m_boundary.length() ? _m_boundary.length() : (blen - i);
        if (!memcmp(buf + i, _m_boundary.c_str(), cmp_len))
        {
          *boundary_pos = i;
          return BOUNDARY_PART;
        }
        else if (!memcmp(buf + i, _l_boundary.c_str(), cmp_len))
        {
          *boundary_pos = i;
          return BOUNDARY_PART;
        }
      }
    }

    return BOUNDARY_NO;
  }

  bool GetFileName(char* buf, int* content_pos)
  {
    char* ptr = NULL;
    ptr = strstr(buf, "\r\n\r\n");
    if (ptr == NULL)
    {
      *content_pos = 0;
      return false;
    }
    *content_pos = ptr - buf + 4;
    std::string header;
    header.assign(buf, ptr - buf);
    std::string file_sep = "filename=\"";
    size_t pos = header.find(file_sep);
    if (pos == std::string::npos)
    {
      return false;
    }
    std::string file;
    file = header.substr(pos + file_sep.length());
    pos = file.find("\"");
    if (pos == std::string::npos)
    {
      return false;
    }
    file.erase(pos);
    _file_name = WWWROOT;
    _file_name += file;
    fprintf(stderr, "upload file:[%s]\n", _file_name.c_str());
    return true;
  }

  bool CreateFile()
  {
    _file_fd = open(_file_name.c_str(), O_CREAT | O_WRONLY);
    if (_file_fd < 0)
    {
      fprintf(stderr, "open error:%s\n", strerror(errno));
      return false;
    }
    return true;
  }
  
  bool CloseFile()
  {
    if (_file_fd != -1)
    {
      close(_file_fd);
      _file_fd = -1;
    }
    return true;
  }

  bool WriteFile(char* buf, int len)
  {
    if (_file_fd != -1)
    {
      write(_file_fd, buf, len);
    }
    return true;
  }
  

public:
  Upload()
    : _file_fd(-1)
  {}
  //初始化boundary信息
  bool InitUploadInfo()
  {
    umask(0);
    char* ptr = getenv("Conetent-Length");
    if (ptr == nullptr)
    {
      fprintf(stderr, "have no content-length!!\n");
      return false;
    }
    content_len = Utils::StrToDigit(ptr);

    ptr = getenv("Conetent-Length");
    if (ptr == nullptr)
    {
      fprintf(stderr, "have no content-length!!\n");
      return false;
    }
    std::string boundary_sep = "boundary=";
    std::string content_type = ptr;
    size_t pos = content_type.find(boundary_sep);
    if (pos == std::string::npos)
    {
      fprintf(stderr, "content type have no boundary!!\n");
      return false;
    }
    std::string boundary;
    boundary = content_type.substr(pos + boundary_sep.length());
    _f_boundary = "--" + boundary;
    _m_boundary = "\r\n" + _f_boundary + "\r\n";
    _l_boundary = "\r\n" + _f_boundary + "--";

    return true;
  }

  //对正文进行处理，将文件数据进行存储(处理文件上传)
  bool ProcessUpload()
  {
    //tlen : 每次开始处理的位置 
    //blen : buffer长度
    int64_t tlen = 0, blen = 0;
    char buf[MAX_BUFF];
    while (tlen < content_len)
    {
      int len = read(0, buf + blen, MAX_BUFF - blen);
      blen += len;//当前buff中数据的长度
      int boundary_pos;
      int content_pos;

      int flag = MatchBoundary(buf, blen, &boundary_pos);
      if (flag == BOUNDARY_FIRST)
      {
        //1.从boundary头中获取文件名
        //2.若获取文件名成功，则创建文件，打开文件
        //3.将文件信息从buf中移除，剩下的数据进行下一步匹配
        if (GetFileName(buf, &content_pos))
        {
          CreateFile();
          blen -= content_pos;
          //匹配到了就把内容去除
          memmove(buf, buf + content_pos, blen - content_pos);
        }
        else 
        {
          //没有匹配成功就把boundary去除
          blen -= (_f_boundary.length());
          memmove(buf, buf + _f_boundary.length(), blen);
        }
      }
      while (1)
      {
        flag = MatchBoundary(buf, blen, &boundary_pos);
        if (flag != BOUNDARY_MIDDLE)
        {
          break;
        }
        //匹配middle_boundary成功
        //1.将boundary之前的数据写入文件，将数据从buf中移除
        //2.关闭文件
        //3.看middle_boundary是否有文件名--剩下的流程都是一样的和first_boundary
        WriteFile(buf, boundary_pos);
        CloseFile();
        blen -= (boundary_pos);
        memmove(buf, buf + content_pos, blen);
        if (GetFileName(buf, &content_pos))
        {
          CreateFile();
          blen -= content_pos;
          //匹配到了就把内容去除
          memmove(buf, buf + content_pos, blen);
        }
        else 
        {
          //头信息不全跳出循环
          if (content_pos == 0)
          {
            break;
          }
          //没有匹配成功就把boundary去除
          blen -= (_m_boundary.length());
          memmove(buf, buf + _f_boundary.length(), blen);
        }
      }
      while (1)
      {
        flag = MatchBoundary(buf, blen, &boundary_pos);
      }
      flag = MatchBoundary(buf, blen, &boundary_pos);
      if (flag == BOUNDARY_LAST)
      {
        //last_boundary匹配成功
        //1.将boundary之前的数据写入文件
        //2.关闭文件
        //3.上传文件处理完毕，退出
        WriteFile(buf, boundary_pos);
        CloseFile();
        return true;
      }
      flag = MatchBoundary(buf, blen, &boundary_pos);
      if (flag == BOUNDARY_PART)
      {
        //1.将类似boundary位置之前的数据写入文件
        //2.移除之前的数据
        //3.剩下的数据不动，重新继续接收数据，补全后匹配
        WriteFile(buf, boundary_pos);
        blen -= boundary_pos;
        memmove(buf, buf + content_pos, blen);
      }
      flag = MatchBoundary(buf, blen, &boundary_pos);
      if (flag == BOUNDARY_NO)
      {
        //将所有数据写入文件
        WriteFile(buf, boundary_pos);
        blen = 0;
      }

      tlen += len;
    }

    return true;
  }
};

int main()
{
  //要将管道中的数据都读取完毕，这个时候，父进程才可以将html页面中的数据发送给浏览器
  Upload upload;
  std::string rsp_body;
  if (upload.InitUploadInfo() == false)
  {
    return 0;
  }
  if (upload.ProcessUpload() == false)
  {
    rsp_body = "<html><body><h1>FALSE</h1></body></html>";
  }
  if (upload.ProcessUpload() == false)
  {
    rsp_body = "<html><body><h1>SUCCESS</h1></body></html>";
  }
  std::cout << rsp_body;
  fflush(stdout);
  return 0;
}
