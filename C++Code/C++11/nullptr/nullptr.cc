#include <iostream>
#include <cstddef>  // 使用nullptr
#include <typeinfo> // 使用typeid

using namespace std;

/******************************
 * nullptr_t对象取地址
 * nullptr不能取地址
 *****************************/ 
/*
int main()
{
    nullptr_t my_null;
    printf("%x\n", &my_null);

    //printf("%x\n", &nullptr); // 无法编译通过
    printf("%d\n", my_null == nullptr);

    const nullptr_t&& default_nullptr = nullptr; // 右值引用
    printf("%x\n", &default_nullptr);

    return 0;
}
*/   
/******************运行结果************************/
/* 
 * 56c25338
 * 1
 * 56c25340
 */ 


/******************************
 * nullptr_t应用于模板
 *****************************/ 
/*
template<typename T>
void g(T* t){}

template<typename T>
void h(T t){}

int main()
{
    g(nullptr); // 编译失败，nullptr的类型是nullptr_t而不是指针
    g((float*)nullptr); // 推导出T = float 

    h(0); // 推导出 T = int
    h(nullptr); // 推导出 T = nullptr_t 
    h((float*)nullptr); // 推导出 T = float*
    return 0;
}
*/ 

/******************************
 * nullptr_t类型规则：
 * 1. 所有定义为nullptr_t类型的数据都是等价的
 * 2. nullptr_t类型的数据可以隐式转换为任意一个指针类型
 * 3. nullptr_t类型的数据不能强制转换为非指针类型
 * 4. nullptr_t类型的数据不能进行算术运算
 * 5. nullptr_t类型的数据可以进行关系运算，但仅可以与指针类型数据进行比较。仅能使用==,>=,<=等运算符为true
 *****************************/ 
/*
int main()
{
    nullptr_t nul;
    if (nul == nullptr)
        std::cout << "nullptr_t数据一致性" << std::endl; 

    //隐式类型转换
    int* ip = nullptr;
    char* cp = nullptr;
    float* fp = nullptr;
    
    //算术运算：无法通过编译
    //nullptr + 1;
    //nullptr * 5;
    
    //不能强制类型转换为非指针类型
    //编译出错，不能进行类型转换
    //int i  = nullptr;
    //int j = reinterpret_cast<int>(nullptr);
    
    //关系运算 
    if (nul == nullptr)
        std::cout << "nul==nullptr" << std::endl;
    
    std::cout << sizeof(nullptr) << std::endl; 
    //不能访问type_info中的信息，这是不完整的
    //typedef (decltype)(nullptr) nullptr_t
    //这是在使用nullptr才使用decltype定义nullptr_t，RTTI(运行时类型识别)
    typeid(nullptr);

    return 0;
}
*/ 

/******************************
 * nullptr：指针空值，仅仅只是对于一个空指针，可以隐式类型转换为要赋值的指针类型
 * NULL：0 or ((void*)0)
 * 常量0 or 无类型指针
 *****************************/ 
/*
void Func(int i) 
{
    std::cout << i << "FuncInt" << std::endl;
}

void Func(void* p)
{
    std::cout << p << "FuncPoint" << std::endl;
}

int main()
{
    Func(0);
    //产生二义性问题，不知道调用上面重载的哪一个函数
    Func(NULL);
    Func(nullptr);
    return 0;
}
*/ 
