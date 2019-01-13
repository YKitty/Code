#include <iostream>
#include <vector>

using namespace std;

double Division(int x, int y)
{
  if (y == 0)
  {
    throw "Divison by zero condition";
  }

  return (double)x / (double)y;
}

void Func()
{
  int* array = new int[10];
  try 
  {
    int x, y;
    std::cin >> x >> y;
    std::cout << Division(x, y) << std::endl;
  }
  catch(...)
  {
    cout << "delete[]" << array << std::endl; 
    delete[] array;
    throw;
  }
  
  std::cout << "delete[]" << array << std::endl;
  delete[] array;
}

int main()
{
  try 
  {
    Func();
  }
  catch(const char* errmsg)
  {
    std::cout << errmsg <<std::endl;
  }
  return  0;
}

//using namespace std;
//
//int main() throw(exception)
//{
//  try 
//  {
//    vector<int> v(10, 5);
//    v.reserve(1000000);
//    v.at(10);
//  }
//  catch (const exception& e)
//  {
//    cout << e.what() << endl;;
//  }
//  catch (...)
//  {
//    cout << "unkown exception!" << endl;
//  }
//  return 0;
//}


//double Division(int x, int y) throw(const char*)
//{
//  if (y == 0)
//  {
//    throw "Division by zero condition!";
//  }
//  return (double)x / (double)y;
//}
//
//void Func()
//{
//  int x;
//  int y;
//  std::cin >> x >> y;
//  std::cout << Division(x, y) << std::endl;
//}
//
//int main()
//{
//  try 
//  {
//    Func();
//  }
//  catch (const char* errmsg)
//  {
//    std::cout << errmsg << std::endl;
//  }
//  catch (...)
//  {
//    std::cout << "unkown " << std::endl;
//  }
//
//  return 0;
//}
