#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 4096

/**
 * 编写一个程序打开两个文件。可以使用命令行参数或提示用户输入文件名。
 * a.该程序以这样的顺序打印：打印第1个文件的第1行，第2个文件的第1行，第1个文件的第2行，第2个文件的第2行，
 * 以此类推，打印到行数较多文件的最后一行。
 * b.修改该程序，把行号相同的行打印成一行。
 */

int main(int argc, char* argv[])
{
    FILE* fa, * fb;
    char* ret_val1;
    char* ret_val2;
    char str[SIZE] = {0};

    if (argc != 3)
    {
        fprintf(stderr, "args error\n");
        exit(EXIT_FAILURE);
    }
    if ((fa = fopen(argv[1], "r")) == NULL || (fb = fopen(argv[2], "r")) == NULL)
    {
        puts("Can't open file");
        exit(EXIT_FAILURE);
    }

    do
    {
        if((ret_val1 = fgets(str, sizeof(str), fa)) != NULL)
            fputs(str, stdout);
        if((ret_val2 = fgets(str, sizeof(str), fb)) != NULL)
            fputs(str, stdout);
    }
    while(ret_val1 != NULL || ret_val2 != NULL);
    fclose(fa);
    fclose(fb);

    return 0;
}
