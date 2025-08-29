#include <stdio.h>
#define SIZE 256

/**
 * strncpy(s1, s2, n)函数把s2中的n个字符拷贝至s1中，截断s2，或者有必要的话在末尾添加空字符。
 * 如果s2的长度是n或多于n，目标字符串不能以空字符结尾。该函数返回s1。
 * 自己编写一个这样的函数，名为mystrncpy()。在一个完整的程序中测试该函数，使用一个循环给函数提供输入值。
 */

char* mystrncpy(char* dest, const char* src, size_t n)
{
    char * tmp = dest;
    while(n > 0 && (*dest = *src))
    {
        dest++;
        src++;
        n--;
    }
    while(n > 0)
    {
        *dest++ = '\0';
        n--;
    }
    return tmp;
}


int main()
{
    char src[SIZE] = "Hello, world!";
    int count;
    char dest[SIZE] = {0};
    printf("Please enter the count of characters you want to copy in \"%s\" (not num to quit): ", src);
    while(scanf("%d", &count) && count > -1)
    {
        printf("Copy %d characters\n", count);
        mystrncpy(dest, src, count);
        printf("Source: %s\n", src);
        printf("Destination after strncpy: %s\n", dest);
        while(getchar() != '\n') ;
        printf("Please enter the count of characters you want to copy in \"%s\" (not num to quit): ", src);
    }
    printf("bye\n");
    return 0;
}

