#include <iostream>
#include <typeinfo>
#include <vector>

/**********************************
 * deltype作用：
 * 1. typedef/using联合使用定义别名
 * 2. 对于匿名对象，可再次定义一个对象
 * 3. 扩大模板的泛型能力
 * 4. 实现了result_of模板类（返回一个函数的返回值类型）
 *********************************/
template <typename T1, typename T2>
void Sum(T1& t1, T2& t2, decltype(t1 + t2)& s)
{
    s = t1 + t2;
}
int main()
{
    // 1. 别名
    using size_t = decltype(sizeof(0));
    std::cout << typeid(size_t).name() << std::endl;
    
    using nullptr_t = decltype(nullptr);
    std::cout << typeid(nullptr_t).name() << std::endl;

    std::vector<int> v{1,2,3,4,5};
    typedef decltype(v.begin()) vtype;

    for (vtype i = v.begin(); i != v.end(); i++)
        std::cout << *i << " ";
    std::cout << '\n';
    
    for (decltype(v)::iterator i = v.begin(); i != v.end(); i++)
        std::cout << *i << " ";
    std::cout << '\n';

    // 2. 匿名对象
    enum {K1, K2, K3}anon_e;

    union 
    {
        decltype(anon_e) key;
        char* name;
    }anon_u;

    struct 
    {
        int d;
        decltype(anon_u) id;
    }anon_s[100];
    
    decltype(anon_s) as;
    as[0].id.key = decltype(anon_e)::K1;

    // 3. 扩大泛化能力

    int a = 3;
    long b = 5;
    float c = 1.0f, d = 2.3f;
    long e;
    float f;

    Sum(a, b, e);
    Sum(c, d, f);
    std::cout << "e : f" << '\n' << e << ":" << f << std::endl;

    return 0;
}

/**********************************
 * decltype：类型推导(编译时期进行)
 * 参数只能是表达式
 *********************************/ 
/*
int main()
{
    int i;
    decltype(i) j = 0;
    std::cout << typeid(j).name() << std::endl; // i:表示int
    
    float a;
    double b;
    decltype(a + b) c;
    std::cout << typeid(c).name() << std::endl; // d:表示double
    return 0;
}
*/ 
/*******************运行结果****************************/
/*
 * $ ./decltype
 * i
 * d
 */ 

/**********************************
 * typeid类返回type_info信息类，类中含有name(),hash_code()两个成员函数
 *********************************/ 
/* 
class left
{};

class right
{};

int main()
{
    left l;
    right r;
    std::cout << typeid(l).name() << std::endl;
    std::cout << typeid(r).name() << std::endl;
    std::cout << typeid(l).hash_code() << std::endl;
    std::cout << typeid(r).hash_code() << std::endl;
    
    left ll;
    std::cout << typeid(ll).hash_code() << std::endl;
    return 0;
}
*/ 

/*****************运行结果******************/
/*
 * $ ./decltype
 * 4left
 * 5right
 * 13725887568528914307
 * 13539930504524871122
 * 13725887568528914307
 */ 
