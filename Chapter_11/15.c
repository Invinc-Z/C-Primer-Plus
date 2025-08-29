#include <stdio.h>
#include <ctype.h>
#define SIZE 64
/**
 * 使用字符分类函数实现atoi()函数。如果输入的字符串不是纯数字，该函数返回0。
 */

int my_atoi(const char* str);
int main()
{
    char p[SIZE] = {0};
    printf("Please enter some digits to convert integer (type 'q' to quit): ");
    while(scanf("%s", p) && p[0] != 'q')
    {
        printf("The integer value of the string \"%s\" is: %d\n", p, my_atoi(p));
        printf("Please enter some digits to convert integer (type 'q' to quit): ");
        while(getchar() != '\n') ;
    }
    printf("bye\n");
    return 0;
}

int my_atoi(const char* str)
{
    int result = 0;
    int sign = 1; // 默认正数
    while (isspace(*str)) // 跳过空白字符
    {
        str++;
    }
    if (*str == '-') // 检查负号
    {
        sign = -1;
        str++;
    }
    else if (*str == '+') // 检查正号
    {
        str++;
    }
    while (isdigit(*str)) // 处理数字字符
    {
        result = result * 10 + (*str - '0'); // 将字符转换为整数
        str++;
    }
    if(*str == '\0') // 便利到结尾无字母出现
        return sign * result; // 返回结果，考虑符号
    else 
        return 0;
}

