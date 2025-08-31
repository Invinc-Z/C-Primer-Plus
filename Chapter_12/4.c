#include <stdio.h>

/**
 * 在一个循环中编写并测试一个函数，该函数返回它被调用的次数。
 */

static int count = 0; // 静态变量，初始化为0
void test()
{
    printf("%s() was called %d.\n", __func__, count);
}

int main()
{
    int i = 0;
    while (i < 10)
    {
        count++;
        test();
        i++;
    }
    printf("The loop has run %d times.\n", i);
    return 0;
}
