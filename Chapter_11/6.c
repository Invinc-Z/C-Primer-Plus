#include <stdio.h>
#include <stdbool.h>

/**
 * 编写一个名为is_within()的函数，接受一个字符和一个指向字符串的指针作为两个函数形参。
 * 如果指定字符在字符串中，该函数返回一个非零值（即为真）。否则，返回0（即为假）。
 * 在一个完整的程序中测试该函数，使用一个循环给函数提供输入值。
 */

bool is_within(char ch, char* str)
{
    if (ch == '\0') return false; // 如果ch是字符串结束符，直接返回false
    while (*str != '\0')
    {
        if (*str == ch)
            return true; // 如果找到匹配的字符，返回true
        str++;
    }
    return false;
}

int main()
{
    char str[] = "Hello, World!";
    char ch;
    printf("Enter a character to check if it's within the string \"%s\" (blank line to quit): ", str);
    while (scanf("%c", &ch) && ch != '\n')
    {
        if (is_within(ch, str))
            printf("Character '%c' is within the string \"%s\".\n", ch, str);
        else
            printf("Character '%c' is not within the string \"%s\".\n", ch, str);
        while(getchar() != '\n') ; // 清除输入缓冲区多余的字符
        printf("Enter a character to check if it's within the string \"%s\" (blank line to quit): ", str);
    }
    printf("bye\n");
    return 0;
}
