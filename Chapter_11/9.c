#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define SIZE 256

/**
 * 编写一个函数，把字符串中的内容用其反序字符串代替。在一个完整的程序中测试该函数，使用一个循环给函数提供输入值。
 */

char * s_gets(char* st, int n);
bool reverse_str(char* str, int len);

int main()
{
    char str[SIZE] = { 0 };
    printf("Please input a string to reverse (blank line to quit): ");
    while (s_gets(str, sizeof(str)) && str[0] != '\0')
    {
        int len = strlen(str);
        if (reverse_str(str, len))
            printf("Reversed string: %s\n", str);
        else
            printf("Reversed string failed\n");
        printf("Please input a string to reverse (blank line to quit): ");
    }
    printf("bye\n");
    return 0;
}

char * s_gets(char* st, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        find = strchr(st, '\n');
        if(find) *find = '\0';
        else 
        {
            while(getchar() != '\n')
                continue;
        }
    }
    return ret_val;
}

bool reverse_str(char* str, int len)
{
    int i = 0;
    int j = len - 1;
    while (i < j)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    return true; // 返回true表示成功
}
