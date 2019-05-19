#include <iostream>

/************************************
 * 初始化列表可以检测类型收窄
 * 类型收窄：无法通过编译
 ************************************/ 
int main()
{
    const int x = 1024;
    const int y = 10;
    
    char a = x; //类型收窄，但可以通过编译
    char* b = new char(1024);//类型收窄，但可以通过编译

    char c = { x }; //类型收窄，无法通过编译
    char d = { y }; //可以通过编译，无类型收窄
    unsigned char e { -1 }; //收窄，无法通过编译
    
    float f { 7 }; //可以通过编译
    int g { 2.0f }; // 收窄，无法通过编译
    float* h = new float{1e48}; // 收窄，无法通过编译
    float i = 1.2l; // 可以通过编译

    return 0;
}
