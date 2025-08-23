#include <stdio.h>

/**
 * 使用嵌套循环，按下面的格式打印字母：
 * F
 * FE
 * FED
 * FEDC
 * FEDCB
 * FEDCBA
 */

int main()
{
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < i + 1; j++)
            printf("%c", 'F' - j);
        printf("\n");
    }
    return 0;
}

