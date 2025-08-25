#include <stdio.h>

/**
 * 编写一个函数，接受3个参数：一个字符和两个整数。
 * 字符参数是待打印的字符，第1个整数指定一行中打印字符的次数，第2个整数指定打印指定字符的行数。编写一个调用该函数的程序。
 */

void show_character(char ch, int i, int j)
{
    for(int k = 0; k < j; k++)
    {
        for(int l = 0; l < i; l++)
        {
            printf("%c", ch);
        }
        printf("\n");
    }
}
int main()
{
    show_character('Z', 8, 8);
    return 0;
}

