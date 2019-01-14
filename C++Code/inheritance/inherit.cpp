#include <iostream>
#include <string>


class A
{
public:
friend void Display(const A& a);
public:
  void Show()
  {
    std::cout << "_count" << _count << std::endl;
  }

  A()
  {
    _count++;
  }

private:
  int _num = 34;

public:
  static int _count;
};

int A::_count = 0;


class B : public A
{
public:
  void Show()
  {
    std::cout << "In B!" << std::endl;
  }

private:
  std::string _name = "yk";
};

class C : public A
{

private:
  int _c = 0;
};

void Display(const A& a)
{
  std::cout << "Freind function In A!" << "_count" << a._count << std::endl; 
  //std::cout << "Freind function In A!" << "_num" << b._name << std::endl; 
}

int main()
{
  B b1;
  B b2;
  B b3;
  Display(b3);

  C c;
  c.Show();

  return 0;
}


//class Person 
//{
//public:
//  Person(std::string name)
//    : _name(name)
//  {
//    std::cout << "In Person Construction!" << std::endl;
//  }
//
//  Person(const Person& p)
//    : _name(p._name)
//  {
//    std::cout << "In Person Construction=!" << std::endl;
//  }
//
//  Person& operator=(const Person& p)
//  {
//    if (this != &p)
//    {
//      _name = p._name;
//      std::cout << "In Person operator=!" << std::endl;
//    }
//
//    return *this;
//  }
//
//  ~Person()
//  {
//    std::cout << "In Person Destruction!" << std::endl;
//  }
//
//private:
//  std::string _name;
//};
//
//
//class Student : public Person 
//{
//public:
//  Student(std::string name)
//    : Person(name)
//    , _name(name)
//  {
//    std::cout << "In Student Construction!" << std::endl;
//  }
//
//  Student(const Student& p)
//    : Person(p)
//    , _name(p._name)
//  {
//    std::cout << "In Student Construction=!" << std::endl;
//  }
//
//  Student& operator=(const Student& p)
//  {
//    if (this != &p)
//    {
//      //必须先对基类的成员进行拷贝构造
//      Person::operator=(p);
//      _name = p._name;
//      std::cout << "In Student operator=!" << std::endl;
//    }
//
//    return *this;
//  }
//
//  ~Student()
//  {
//    std::cout << "In Student Destruction!" << std::endl;
//  }
//
//private:
//  std::string _name;
//};
//
//int main()
//{
//  Student s1 ("jack");
//  Student s2 (s1);
//  Student s3 ("rose");
//  s1 = s3 ;
//  return 0;
//}
//
//class A
//{
//public:
//  void Show()
//  {
//    std::cout << "In A!" << std::endl;
//  }
//};
//
//class B : public A
//{
//public:
//  void Show(int i)
//  {
//    std::cout << "In B!" << std::endl;
//  }
//};
//
//int main()
//{
//  //A和B中的Show函数构成了隐藏，因为不在同一个作用域中所以不是重载
//  B b;
//  b.Show(3);
//  b.A::Show();
//  return 0;
//}

//class Person
//{
//protected:
//  int _num = 111;
//  std::string _name = "yk";
//};
//
//class Student : public Person 
//{
//public:
//  void Show()
//  {
//    std::cout << "_num: " << _num << std::endl;
//    std::cout << "_name: " << _name << std::endl;
//  }
//
//private:
//  int _num = 999;
//  std::string _name = "oodk";
//};
//
//int main()
//{
//  Student stu;
//  stu.Show();
//  return 0;
//}


//class Person 
//{
//public:
//  void Show()
//  {
//    std::cout << "In Basci!" << std::endl;
//  }
//
////private:
//  std::string _name;
//  int _age;
//};
//
//class Student : public Person 
//{
//public:
//  void Display()
//  {
//    std::cout << "In Derived!" << std::endl;
//  }
//
////private:
//  int _num;
//};
//
//int main()
//{
//  //派生类的对象可以赋值给基类的对象，引用，指针
//  Student stu;
//  Person p = stu;
//  Person& p1 = stu;
//  Person* p2 = &stu;
//
//  //基类的对象不可以赋值给派生类
//  //stu = p;
//  
//  //基类的指针（指向派生类对象）可以赋值给派生类,必须要进行强制类型转换
//  Student* pStu = (Student*)p2;
//  pStu->_num = 10;
//  std::cout << "ok" << std::endl;
//
//  //基类的指针（指向基类的对象）可以赋值给派生类，但是会发生越界问题
//  Person pp;
//  pStu = (Student*)&pp;
//  pStu->_num = 10;//发生越界问题，访问了不可访问到的数据
//  std::cout << "odk?" << std::endl;
//  return 0;
//}
