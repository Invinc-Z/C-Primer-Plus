#include <stdio.h>
#include <string.h>

/**
 * 编写一个名为string_in()的函数，接受两个指向字符串的指针作为参数。
 * 如果第2个字符串被包含在第1个字符串，该函数将返回第1个字符串开始的地址。
 * 例如，string_in("hats", "at")将返回hats中a的地址。否则，该函数返回空指针。
 * 在一个完整的程序中测试该函数，使用一个循环给函数提供输入值。
 */

char* string_in(char* str, char* sub_str);
char* s_gets(char* st, int n);

int main()
{
    char str[] = "Hello, World!";
    char sub_str[10] = { 0 };
    printf("Please input the sub string you want to search in \"%s\" (blank line to quit): ", str);
    while (s_gets(sub_str, sizeof(sub_str)) && sub_str[0] != '\0')
    {
        printf("Searching for substring \"%s\" in string \"%s\"...\n", sub_str, str);
        char* result = string_in(str, sub_str);
        if (result)
            printf("Substring \"%s\" found in string \"%s\" at position: %ld\n", sub_str, str, result - str);
        else
            printf("Substring \"%s\" not found in string \"%s\".\n", sub_str, str);
        printf("Please input the sub string you want to search in \"%s\" (blank line to quit): ", str);
    }
    printf("bye\n");
    return 0;
}

char* s_gets(char* st, int n)
{
    char * ret_val;
    char * find;
    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        find = strchr(ret_val, '\n');
        if(find) *find = '\0';
        else
        {
            while(getchar() != '\n')
                continue;
        }
    }
    return ret_val;
}

char* string_in(char* str, char* sub_str)
{
    char* p = str;
    while (*p != '\0')
    {
        char* p1 = p;
        char* p2 = sub_str;
        while (*p1 == *p2 && *p2 != '\0')
        {
            p1++;
            p2++;
        }
        if (*p2 == '\0') // 如果子字符串完全匹配
            return p; // 返回指向匹配位置的指针
        p++; // 否则继续查找下一个位置
    }
    return NULL; // 如果未找到，返回NULL
}
