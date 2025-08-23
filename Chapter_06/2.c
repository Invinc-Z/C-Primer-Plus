#include <stdio.h>

/**
 * 使用嵌套循环，按下面的格式打印字符：
 * $
 * $$
 * $$$
 * $$$$
 * $$$$$
 */

int main()
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < i + 1; j++)
            printf("$");
        printf("\n");
    }
    return 0;
}

