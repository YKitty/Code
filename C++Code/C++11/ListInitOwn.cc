#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>

using namespace std;

/*********************************************
 * 类和结构体成员函数使用初始化列表
 ********************************************/ 
/*
class Vector 
{
public:
    Vector& operator[](initializer_list<int> li)
    {
        for (auto i = li.begin(); i != li.end(); i++)
        {
            iv.push_back(*i);
        }

        return *this;
    }

    Vector& operator=(int x)
    {
        if (iv.empty() != true)
        {
            for (auto i = iv.begin(); i != iv.end(); i++)
            {
                //加1 => 使用下标进行赋值
                data.resize(((*i > data.size()) ? *i : data.size()) + 1);
                data[*i] = x;
            }
            //必须将下标进行置空，为了下次进来时是从新开始
            iv.clear();
        }
        return *this;
    }

    void Show()
    {
        for (auto i = data.begin(); i != data.end(); i++)
            std::cout << *i << " ";
        std::cout << std::endl;
    }
private:
    //记录下标
    vector<int> iv;
    vector<int> data;
};

int main()
{
    Vector v;
    v[{1,2,3,4}] = 7;
    v.Show();
    v[{2,8}] = 11;
    v.Show();
    return 0;
}
*/ 

/*****************运行结果****************/
/*
# yk @ localhost in ~/test [10:05:58] 
$ ./ListInitOwn
0 7 7 7 7 
0 7 11 7 7 0 0 0 11 
*/

/***********************************************
 * 使用initialzer_list<T>作为函数的参数列表
 **********************************************/ 
/*
void TestFunction(initializer_list<int> li)
{
    for (auto e : li)
    {
        std::cout << e << "--";
    }
    std::cout << std::endl;;
}

int main()
{
    TestFunction({1, 2, 3, 4, 5});
    return 0;
}
*/

/********运行**************/
/*
# yk @ localhost in ~/test [9:40:13] 
$ ./ListInitOwn
1--2--3--4--5--
*/




/***********************************************
 * 使用initializer_list<T>模板类作为构造函数的参数
 * 实现列表初始化
 **********************************************/
/*
enum Gender 
{
    boy,
    girl
};

class Vector
{
public:
    //只能使用使用大括号每次初始化一个，根本没有用到初始化列表
    //Vector(pair<string, Gender> l)
    //{
    //    data.push_back(l);
    //}

    Vector(initializer_list<pair<string, Gender>> l)
    {
        for (auto e : l)
        {
            data.push_back(e);
        }
    }

    void Show()
    {
        for (auto e : data)
        {
            std::cout << e.first << "--" << e.second << std::endl;
        }
    }
private:
    vector<pair<string, Gender>> data;
};

int main()
{
    //初始化一个数据.{"yk", boy} => pair("yk", boy)
    //Vector v{{"yk", boy}};
    Vector v{{"yk", boy}, {"yq", girl}};
    v.Show();
    return 0;
}
*/

/******************************************
 *本质：将{}转化为pair或者数据而已，没有列表初始化
 *****************************************/
/*
//自定义类型的列表初始化
class Base
{
private:
    int a = 0;
    int b = 0;

public:
    Base(int _a = 0, int _b = 0)
        : a(_a)
        , b(_b)
    {}

    void Show()
    {
        std::cout << "a:" << a << '\n' << "b:" << b << std::endl;
    }
};

int main()
{
    Base a{1, 2};
    a.Show();
    return 0;
}
*/

