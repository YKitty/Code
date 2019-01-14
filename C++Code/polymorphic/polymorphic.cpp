#include <iostream>

class A
{
public:
  virtual ~A()
  {
    std::cout << "A destructor!" << std::endl;
  }
};


class B : public A
{
public:
  virtual ~B()
  {
    std::cout << "B destructor!" << std::endl;
  }
};

int main()
{
  A* a = new A();
  A* b = new B();

  delete a;
  delete b;
  return 0;
}

//class A
//{};
//
//class B : public A
//{};
//
//class Person
//{
//public:
//  virtual A* f()
//  {
//    std::cout << "In Person!" << std::endl;
//    return new A;
//  }
//};
//
//class Student : public Person 
//{
//public:
//  virtual B* f()
//  {
//    std::cout << "In Student!" << std::endl;
//    return new B;
//  }
//};
//
//void Func(Person& p)
//{
//  p.f();
//}
//
//int main()
//{
//  Person p;
//  Student stu;
//  Func(p);
//  Func(stu);
//  return 0;
//}
//


//class Person
//{
//public:
//  virtual void BuyTicket()
//  {
//    std::cout << "买票全价" << std::endl;
//  }
//};
//
//class Student : public Person 
//{
//public:
//  virtual void BuyTicket()
//  {
//    std::cout << "买票半价" << std::endl;
//  }
//};
//
//
//void Func(Person& p)
//{
//  p.BuyTicket();
//}
//
//int main()
//{
//  Person ps;
//  Student st;
//  Func(ps);
//  Func(st);
//  return 0;
//}
