#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FILENAME_LEN 256

/**
 * 使用命令行参数的程序依赖于用户的内存如何正确地使用它们。
 * 重写程序清单13.2中(13.3节)的程序，不使用命令行参数，而是提示用户输入所需信息。
 */

int main()
{
    FILE* in, * out;
    int ch;
    char in_filename[MAX_FILENAME_LEN] = { 0 };
    char out_filename[MAX_FILENAME_LEN] = { 0 };
    int count = 0;
    // 设置输入
    printf("Please enter the file name compressed: ");
    fgets(in_filename, MAX_FILENAME_LEN, stdin);
    if (in_filename[strlen(in_filename) - 1] == '\n')
        in_filename[strlen(in_filename) - 1] = '\0';
    if ((in = fopen(in_filename, "r")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file \"%s\"\n", in_filename);
        exit(EXIT_FAILURE);
    }
    // 设置输出
    strncpy(out_filename, in_filename, MAX_FILENAME_LEN - 5);
    out_filename[MAX_FILENAME_LEN - 5] = '\0';
    strcat(out_filename, ".red");
    if ((out = fopen(out_filename, "w")) == NULL)
    {
        fprintf(stderr, "Can't create output file.\n");
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(in)) != EOF)
    {
        if (count++ % 3 == 0)
            putc(ch, out);
    }
    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "Error in closing files\n");

    return 0;
}
