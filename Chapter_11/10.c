#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define SIZE 256

/**
 * 编写一个函数接受一个字符串作为参数，并删除字符串中的空格。
 * 在一个程序中测试该函数，使用循环读取输入行，直到用户输入一行空行。
 * 该程序应该应用该函数只每个输入的字符串，并显示处理后的字符串。
 */

char * s_gets(char* st, int n);
char* del_space(char* st);

int main()
{
    char str[SIZE] = { 0 };
    printf("Please input a string to delete spaces (blank line to quit): ");
    while (s_gets(str, sizeof(str)) && str[0] != '\0')
    {
        printf("String after deleting spaces: %s\n", del_space(str));
        printf("Please input a string to delete spaces (blank line to quit): ");
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

char* del_space(char* st)
{
    char* p = st; // 记录开头位置
    while (*st != '\0')
    {
        if (*st == ' ') // 如果不是空格 所有字符往前移动一格
        {
            for(int i = 0; *(st + i) != '\0'; i++)
                *(st + i) = *(st + i + 1);
        }
        else
            st++;
    }
    return p;
}

