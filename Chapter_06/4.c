#include <stdio.h>

/**
 * 使用嵌套循环，按下面的格式打印字母：
 * A
 * BC
 * DEF
 * GHIJ
 * KLMNO
 * PQRSTU
 */

int main()
{
    char ch = 'A';
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < i + 1; j++)
            printf("%c", ch++);
        printf("\n");
    }
    return 0;
}

