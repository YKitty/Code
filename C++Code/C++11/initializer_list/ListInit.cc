#include <iostream>
#include <vector>
#include <map>

int main()
{
    //内置类型
    int x = {10};
    int x1{11};
    int x2 = {1 + 2};
    char c{'y'};
    char c1{'k'};
    
    //动态数组
    int* arr = new int[5]{1, 2, 3, 4, 5};

    //容器
    std::vector<int> v{1, 2, 3, 4, 5};
    std::map<int, int> mp{{1,2}};
    return 0;
}
