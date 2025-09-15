#include <stdio.h>
#include <string.h>
#include "stack.h"
#define SIZE 4096

/**
 * 编写一个程序，提示用户输入一个字符串。然后该程序把该字符串的字符逐个压入一个栈（参见复习题5），
 * 然后从栈中弹出这些字符，并显示它们。结果显示为该字符串的逆序。
 */

char* s_gets(char* str, int n);

int main()
{
    char str[SIZE] = {0};
    char dest[SIZE] = {0};
    printf("Please enter some strings: ");
    s_gets(str, SIZE);

    stack_t stack;
    init_stack(&stack);

    for(int i = 0; str[i] != '\0'; i++)
    {
        en_stack(&stack, str[i]);
    }
    printf("Top is: %c\n", stack.top->item);
    int i = 0;
    while(de_stack(&stack, &dest[i]))
        i++;
    dest[i] = '\0';

    puts("Orign str is: ");
    puts(str);
    puts("Reversed string by stack is: ");
    puts(dest);

    return 0;
}

char* s_gets(char* str, int n)
{
    char* ret_val = fgets(str, n, stdin);
    if(ret_val == NULL)
        return NULL;
    char* find = strchr(str, '\n');
    if(find)
        *find = '\0';
    else
    {
        while(getchar() != '\n')
            continue;
    }
    return str;
}
