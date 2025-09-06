#include <stdio.h>

/**
 * 编写一个函数，把二进制字符串转换为一个数值。例如，有下面的语句：
 * char * pbin = "01001001";
 * 那么把pbin作为参数传递给该函数后，它应该返回一个int类型的值73。
 */

int str2int(const char* pbin);

int main()
{
    const char* pbin = "01001001";
    printf("%s converts to %d at decimal system\n", pbin, str2int(pbin));
    return 0;
}

int str2int(const char* pbin)
{
    int ret = 0;
    int base = 1;
    char* p = (char*)pbin;
    while(*p)
        p++;
    --p;
    while(p - pbin >= 0)
    {
        ret += (*p - 48) * base;
        base *= 2;
        p--;
    }
    return ret;
}
