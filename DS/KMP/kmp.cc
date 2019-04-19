#include <iostream>
#include <string>

void GetNext(std::string str, int* next)
{
    if (str.size() == 0)
        return;

    int len = str.size();
    //进行数据初始化
    int j = 0;
    int k = -1;
    next[0] = -1;

    //不需要到达下标为len - 1的位置
    //由于在循环里面每次设置的都是下一个的位置
    while (j < len - 1)
    {
        // 此处是找到一个前面的前缀等于j+1前面的一个元素j时
        if (k == -1 || str[j] == str[k])
            //此处直接对于下标为1的数据设置为0
            next[++j] = ++k;
        else 
            //对于k一直向前寻找
            k = next[k];
    }
}

int Search(std::string sourceString, std::string searchString, int* next)
{
    int sourceLen = sourceString.size();
    int searchLen = searchString.size();
    if ((sourceLen < searchLen) || \
        (sourceLen == 0) || \
        (searchLen == 0))
        return -1;

    int i = 0, j = 0;
    while (i < sourceLen && j < searchLen)
    {
        if (j == -1 || sourceString[i] == searchString[j])
        {
            i++;
            j++;
        }
        else 
            j = next[j];
    }

    if (j == searchLen)
        return i - j;
    else 
        return -1;
}

int main()
{
    std::string sourceString = "abcd";
    std::string searchString = "cd";
    int next[10] = { 0 };
    GetNext(searchString, next);
    int ret = Search(sourceString, searchString, next);
    if (ret)
        std::cout << "Search Success index:" << ret << std::endl;
    else 
        std::cout << "Search fail" << std::endl;
    return 0;
}
