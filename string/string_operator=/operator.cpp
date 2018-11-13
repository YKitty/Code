#include <iostream>
using namespace std;

int main()
{
  string s1, s2, s3;
  s1 = "hello world";//字符串
  s2 = 'x';//字符
  s3 = s2;//引用

  //注意
  //string s = "hello world";//这是进行拷贝构造，不是运用了string容器的赋值运算符

  cout << s1 << endl; 
  cout << s2 << endl;
  cout << s3 << endl; 
  return 0;
}
