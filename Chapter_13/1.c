#include <stdio.h>
#include <stdlib.h> // 提供 exit()的原型
#include <string.h>
#define SIZE 1024

/**
 * 修改程序清单13.1中(13.2节)的程序，要求提示用户输入文件名，并读取用户输入的信息，不使用命令行参数。
 */

char* s_gets(char* st, int n);

int main()
{
    int ch; // 读取文件时，储存每个字符的地方
    FILE *fp; // “文件指针”
    unsigned long count = 0;
    char filename[SIZE] = {0};
    printf("Please enter filename: ");
    s_gets(filename, SIZE);
    if ((fp = fopen(filename, "r")) == NULL)
    {
        printf("Can't open %s\n", filename);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(fp)) != EOF)
    {
        putc(ch, stdout); // 与 putchar(ch); 相同
        count++;
    }
    fclose(fp);
    printf("File %s has %lu characters\n", filename, count);

    return 0;
}

char* s_gets(char* st, int n)
{
    char* ret_val;
    char* find;
    ret_val = fgets(st, n, stdin);
    if(ret_val == NULL)
        return NULL;
    else
    {
        if((find = strchr(st, '\n')) != NULL)
            *find = '\0';
        else
        {
            while(getchar() != '\n')
                continue;
        }
    }
    return ret_val;
}
