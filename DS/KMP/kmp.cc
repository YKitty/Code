#include <iostream>
#include <string>

using namespace std;
/*
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
        // 当j==-1时，i也会++
        // 这是因为，只有是i和第一个字符进行比较时，j才会等于-1，所以此时回到开始时，没有必要在和这个i进行比较了
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
*/  

void GetNext(const string& des, int* next)
    {
        //第一个位置为-1
        next[0] = -1;
        
        int cur_index = 0;
        int cal_index = -1;
        
        //每次计算的都是下一个数据元素
        while (cur_index < des.size() - 1)
        {
            if (cal_index == -1 || des[cal_index] == des[cur_index])
                next[++cur_index] = ++cal_index;
                
            else
                cal_index = next[cal_index];
        }
    }
    
    int Search(string src, string des, int* next)
    {
        int i = 0;
        int j = 0;
        // 这里不能使用j < des.size() 两个类型不一样
        while (i < src.size() && j < (int)des.size())
        {
            if (j == -1 || src[i] == des[j])
            {
                i++;
                j++;
            }
            else
                j = next[j];
        }
        
        return j == des.size() ? i - j : -1;
    }
    
    /* KMP算法 */
    int MystrStr(string src, string des)
    {
        if (des.size() == 0)
            return 0;
        int* next = new int[des.size()];
        GetNext(des, next);
        
        return Search(src, des, next);
    }

int main()
{
    string src = "hello";
    string des = "ll";
    MystrStr(src, des);
	return 0;
}   
 
/*
int main()
{
    std::string sourceString = "hello";
    std::string searchString = "ll";
    int next[10] = { 0 };
    GetNext(searchString, next);
    int ret = Search(sourceString, searchString, next);
    if (ret)
        std::cout << "Search Success index:" << ret << std::endl;
    else 
        std::cout << "Search fail" << std::endl;
    return 0;
}
*/ 
