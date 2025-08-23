#include <stdio.h>

/**
 * 编写一个程序，读取一行输入，然后把输入的内容倒序打印出来。可以把输入储存在char类型的数组中，假设每行字符不超过255。
 * 回忆一下，根据%c转换说明，scanf()函数一次只能从输入中读取一个字符，而且在用户按下Enter键时scanf()函数会生成一个换行字符（\n）。
 */

int main()
{
    char str[256] = {0};
    char ch;
    int i = 0;
    printf("Please enter some words: ");
    while(scanf("%c", &ch) == 1 && ch != '\n')
    {
        str[i++] = ch;
    }
    printf("Reversed: ");
    while(--i > -1)
    {
        printf("%c", str[i]);
    }
    printf("\n");
    return 0;
}

