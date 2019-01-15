#include <iostream>


//通过二维数组访问虚函数表
class Base1
{
public:
  virtual void func1()
  {
    std::cout << "Base1::func1" << std::endl;
  }
  virtual void func2()
  {
    std::cout << "Base1::func1" << std::endl;
  }
  virtual void func3()
  {
    std::cout << "Base1::func1" << std::endl;
  }
};


class Base2
{
public:
  virtual void func1()
  {
    std::cout << "Base2::func1" << std::endl;
  }
  virtual void func2()
  {
    std::cout << "Base2::func2" << std::endl;
  }
  virtual void func3()
  {
    std::cout << "Base2::func3" << std::endl;
  }
};

class Base3
{
public:
  virtual void func1()
  {
    std::cout << "Base3::func1" << std::endl;
  }
  virtual void func2()
  {
    std::cout << "Base3::func2" << std::endl;
  }
  virtual void func3()
  {
    std::cout << "Base3::func3" << std::endl;
  }
};


class Derive : public Base1, public Base2, public Base3 
{
public:
  virtual void func1()
  {
    std::cout << "Derive::func1" << std::endl;
  }

  virtual void func4()
  {
    std::cout << "Derive::func4" << std::endl;
  }
};

typedef void(* VFPTR)();

int main()
{
  VFPTR pFun = nullptr;
  Derive d;
  int** vTable = (int**)&d;
  
  //Base1 vtable 
  //pFun = (Fun)*((int*)(*(int*)((int*)&d+0)+0))
  pFun = (VFPTR)vTable[0][0];
  pFun();

  //pFun = (Fun)*((int*)(*(int*)((int*)&d+0)+1))
  pFun = (VFPTR)vTable[0][1];
  pFun();

  //pFun = (Fun)*((int*)(*(int*)((int*)&d+0)+2))
  pFun = (VFPTR)vTable[0][2];
  pFun();

  //pFun = (Fun)*((int*)(*(int*)((int*)&d+0)+3))
  pFun = (VFPTR)vTable[0][3];
  pFun();

  //Base2 vtable 
  //pFun = (Fun)*(int*)(*(int*)((int*)&b + 1)+0);
  pFun = (VFPTR)vTable[1][0];
  pFun();

  //pFun = (Fun)*(int*)(*(int*)((int*)&b + 1)+0);
  pFun = (VFPTR)vTable[1][1];
  pFun();

  //pFun = (Fun)*(int*)(*(int*)((int*)&b + 1)+0);
  pFun = (VFPTR)vTable[1][2];
  pFun();

  //pFun = (Fun)*(int*)(*(int*)((int*)&b + 1)+0);
  pFun = (VFPTR)vTable[1][3];
  pFun();

  //Base3 vtable 
  //pFun = (Fun)*(int*)(*(int*)((int*)&b + 2)+0);
  pFun = (VFPTR)vTable[2][0];
  pFun();

  //pFun = (Fun)*(int*)(*(int*)((int*)&b + 2)+0);
  pFun = (VFPTR)vTable[2][1];
  pFun();

  //pFun = (Fun)*(int*)(*(int*)((int*)&b + 2)+0);
  pFun = (VFPTR)vTable[2][2];
  pFun();

  //pFun = (Fun)*(int*)(*(int*)((int*)&b + 2)+0);
  pFun = (VFPTR)vTable[2][3];
  pFun();
  return 0;
}
//子类对象访问父类私有虚函数
//class Base
//{
//private:
//  virtual void f()
//  {
//    std::cout << "Base::f" << std::endl;
//  }
//};
//
//class Derive : public Base 
//{
//};
//
//typedef void(*VFPTR)();
//
//int main()
//{
//  Derive d;
//  VFPTR vf = (VFPTR)*(int*)(*(int*)&d);
//  vf();
//  return 0;
//}

//多继承的虚函数表
//typedef void (*VFPTR) ();
//class A
//{
//public:
//  virtual void func1()
//  {}
//
//  virtual void func2()
//  {}
//};
//
//class B 
//{
//public:
//  virtual void func1()
//  {}
//
//  virtual void func2()
//  {}
//};
//
//class C : public A
//{
//public:
//  virtual void func1()
//  {}
//
//  virtual void func3()
//  {}
//};
//
//void PrintVFPTR(VFPTR* vftable)
//{
//  std::cout << "虚函数地址:" << vftable << std::endl;
//
//  for (int i = 0; vftable[i] != (VFPTR)0; i++)
//  {
//    printf("第%d个虚函数表地址:0X%x,->", i, vftable[0]);
//    VFPTR f = vftable[0];
//    f();
//  }
//  std::cout << std::endl;
//}
//
//int main()
//{
//  C c;
//  VFPTR* vf = (VFPTR*)(*(int*)&c);
//  PrintVFPTR(vf);
//  return 0;
//}
//



//虚函数表指针
//class Person 
//{
//public:
//  virtual void Show()
//  {
//    std::cout << "HAHA!" << std::endl;
//  }
//
//private:
//  int num;
//};
//
//int main()
//{
//  Person p;
//  p.Show();
//  std::cout << sizeof(p) << std::endl;
//  return 0;
//}


//final和override
//class Person 
//{
//public:
//  virtual void Say() = 0;//纯虚函数
//  virtual void View() final
//  {
//    std::cout << "View You!" << std::endl;
//  }
//};
//
//class Student : public Person 
//{
//  //使用override强制重写之后但是没有重写就会出错
//  virtual void Say() override;
//  //{
//  //  std::cout << "In Student" << std::endl;
//  //}
//
//};
//
//int main()
//{
//  Person* p = new Student();
//  p->Say();
//  p->View();
//  return 0;
//}


//抽象类
//class A
//{
//public:
//  virtual void Show() = 0;//纯虚函数
//};
//
//class B : public A
//{
//public:
//  virtual void Show() override
//  {
//    std::cout << "In Class B" << std::endl;
//  }
//};
//
//class C : public A
//{
//public:
//  virtual void Show() override//完成虚函数的强制重写
//  {
//    std::cout << "In Class C" << std::endl;
//  }
//};
//
//int main()
//{
//  A* a1 = new B();
//  A* a2 = new C();
//  a1->Show();
//  a2->Show();
//}


//构造函数为虚函数
//class A
//{
//public:
//  virtual ~A()
//  {
//    std::cout << "A destructor!" << std::endl;
//  }
//};
//
//
//class B : public A
//{
//public:
//  virtual ~B()
//  {
//    std::cout << "B destructor!" << std::endl;
//  }
//};
//
//int main()
//{
//  A* a = new A();
//  A* b = new B();
//
//  delete a;
//  delete b;
//  return 0;
//}
//
//协变（重写之后返回值类型不一样）
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

//重写
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
