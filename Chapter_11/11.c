#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define LIM 10
#define SIZE 256

/**
 * 编写一个函数，读入10个字符串或者读到EOF时停止。该程序为用户提供一个有5个选项的菜单：
 * 打印源字符串列表、以ASCII中的顺序打印字符串、按长度递增顺序打印字符串、按字符串中第1个单词的长度打印字符串、退出。
 * 菜单可以循环显示，除非用户选择退出选项。当然，该程序要能真正完成菜单中各选项的功能。
 */

char * s_gets(char * st, int n);			//获取字符串输入
char get_choice(void);						//获取选择
void print_sour(char * st[], int n);		//打印源字符串
void print_ascii(char * st[], int n);		//按ASCII码顺序打印
void print_length(char * st[], int n);		//按长度顺序打印
void print_first_word(char * st[], int n);	//按第一个单词的长度顺序打印
int first_word(char * st);					//计算第一个单词数

int main()
{
    char str[LIM][SIZE] = {{0}};
    char * ptr[LIM];
    int row = 0;							//输入的字符串数量
    char choice;							//用户输入的选择字符

    printf("Input some strings before EOF (no more than 10):\n");
    while (row < LIM && s_gets(str[row], SIZE))
    {
        ptr[row] = str[row];				//设置指针指向字符串
        row++;
    }
    while((choice = get_choice()) != 'q')
    {
        printf("\n");
        switch (choice)
        {
        case 'a': print_sour(ptr, row);
                  break;
        case 'b': print_ascii(ptr, row);
                  break;
        case 'c': print_length(ptr, row);
                  break;
        case 'd': print_first_word(ptr, row);
                  break;
        default: printf("Error!\n");
                 break;
        }
        printf("\n");
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
//获取用户选择
char get_choice(void)
{
    char ch;

    printf("a. print the sourse strings.     b. print in order of ASCII.\n");
    printf("c. print in order of length.	 d. print in order of the first word's length.\n");
    printf("q. quit.\n");
    printf("Enter a character (a, b, c, d or q):");
    ch = getchar();
    while (getchar() != '\n')
        continue;
    while ((ch < 'a' || ch > 'd') && ch != 'q')
    {
        printf("Please input the right option (a, b, c, d or q): ");
        ch = getchar();
        while (getchar() != '\n')
            continue;
    }
    return ch;
}

//打印源字符串
void print_sour(char * st[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        puts(st[i]);
}

//按ASCII中的顺序打印字符串
void print_ascii(char * st[], int n)
{
    int i, j;
    char * temp;

    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (strcmp(st[i], st[j]) > 0)
            {
                temp = st[j];
                st[j] = st[i];
                st[i] = temp;
            }
    for (i = 0; i < n; i++)
        puts(st[i]);
}

//按长度顺序打印
void print_length(char * st[], int n)
{
    int i, j;
    char * temp;

    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (strlen(st[i]) > strlen(st[j]))
            {
                temp = st[j];
                st[j] = st[i];
                st[i] = temp;
            }
    for (i = 0; i < n; i++)
        puts(st[i]);
}
//按第一个单词的长度顺序打印
void print_first_word(char * st[], int n)
{
    int i, j;
    char * temp;

    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (first_word(st[i]) > first_word(st[j]))
            {
                temp = st[j];
                st[j] = st[i];
                st[i] = temp;
            }
    for (i = 0; i < n; i++)
        puts(st[i]);
}

//计算第一个单词的长度
int first_word(char * st)
{
    int i = 0;
    int count = 0;

    while (!isalpha(st[i]))
        i++;
    while (isalpha(st[i]))
    {
        i++;
        count++;
    }

    return count;
}

