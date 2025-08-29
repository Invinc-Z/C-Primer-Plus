#include <stdio.h>

/**
 * 设计并测试一个函数，搜索第1个函数形参指定的字符串，在其中查找第2个函数形参指定的字符首次出现的位置。
 * 如果成功，该函数返指向该字符的指针，如果在字符串中未找到指定字符，则返回空指针（该函数的功能与strchr()函数相同）。
 * 在一个完整的程序中测试该函数，使用一个循环给函数提供输入值。
 */


char * my_strchr(const char * str, char c);

int main()
{
    char str[] = "Hello, World!";
    char ch;
    printf("Please enter the character you want to find in str \"%s\" (blank line to quit): ", str);
    while((ch = getchar()) != '\n')
    {
        char * result = my_strchr(str, ch);
        if (result)
            printf("Found '%c' at position: %ld\n", ch, result - str);
        else
            printf("Character '%c' not found in string.\n", ch);
        while(getchar() != '\n') ;
        printf("Please enter the character you want to find in str \"%s\" (blank line to quit): ", str);
    }
    printf("bye\n");
    return 0;
}

char * my_strchr(const char * str, char c)
{
    while (*str != '\0')
    {
        if (*str == c)
            return (char *)str; // 返回指向找到的字符的指针
        str++;
    }
    return NULL; // 如果未找到，返回NULL
}
