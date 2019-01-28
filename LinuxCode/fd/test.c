#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
  const char* msg = "hello printf\n";
  const char* msg1 = "hello fprintf\n";
  const char* msg2 = "hello write\n";

  printf("%s", msg);
  fwrite(msg1, strlen(msg1), 1, stdout);
  write(1, msg2, strlen(msg2));

  fork();
  return 0;
}

