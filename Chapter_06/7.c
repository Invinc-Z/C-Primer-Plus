#include <stdio.h>
#include <string.h>

/**
 * 编写一个程序把一个单词读入一个字符数组中，然后倒序打印这个单词。
 * 提示：strlen()函数（第4章介绍过）可用于计算数组最后一个字符的下标。
 */

int main()
{
    char str[1024] = {0};
    fgets(str, 1024, stdin);
    if(str[strlen(str) - 1] == '\n') str[strlen(str) - 1] = '\0';
    for(int i = strlen(str) -1; i >= 0; i--)
        printf("%c", str[i]);
    printf("\n");
    return 0;
}

