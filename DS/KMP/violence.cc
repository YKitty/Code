#include <iostream>
#include <string>

int Search(std::string sourceString, std::string searchString)
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
        if (sourceString[i] == searchString[j])
        {
            i++;
            j++;
        }
        else 
        {
            //将i进行重置，j置为0
            i = i - (j - 1);
            j = 0;
        }
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
    int ret = Search(sourceString, searchString);
    if (ret)
        std::cout << "Search Success index:" << ret << std::endl;
    else 
        std::cout << "Search fail" << std::endl;
    return 0;
}
