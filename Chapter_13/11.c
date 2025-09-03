#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 256

/**
 * 编写一个程序，接受两个命令行参数。第1个参数是一个字符串，第2个参数是一个文件名。
 * 然后该程序查找该文件，打印文件中包含该字符串的所有行。
 * 因为该任务是面向行而不是面向字符的，所以要使用fgets()而不是getc()。
 * 使用标准C库函数strstr()（11.5.7节简要介绍过）在每一行中查找指定字符串。
 * 假设文件中的所有行都不超过255个字符。
 */


int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "args error\n");
        exit(EXIT_FAILURE);
    }
    FILE* fp;
    if ((fp = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stderr, "Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    char buff[SIZE] = { 0 };
    while (fgets(buff, sizeof(buff), fp) != NULL)
    {
        if (strstr(buff, argv[1]))
            fputs(buff, stdout);
    }
    fclose(fp);

    return 0;
}
