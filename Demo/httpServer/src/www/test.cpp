#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
  struct stat st;
  stat("/home/yk/LinuxDir/Demo/httpServer/src/www/test.txt", &st);
  std::cout << "inode" << st.st_ino << std::endl;
  std::cout << "size" << st.st_size << std::endl;
  return 0;
}
