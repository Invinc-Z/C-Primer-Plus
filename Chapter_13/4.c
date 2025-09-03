#include <stdio.h>

/**
 * 编写一个程序，按顺序在屏幕上显示命令行中列出的所有文件。使用argc控制循环。
 */

int main(int argc, char* argv[])
{
    FILE * file;
    for (int i = 1; i < argc; i++)
    {
        file = fopen(argv[i], "r");
        if (file == NULL) {
            printf("Can not open file %s\n", argv[i]);
            continue;  // 跳过无法打开的文件
        }
        printf("File %d: %s\n", i, argv[i]);
        char ch;
        while ((ch = fgetc(file)) != EOF) {
            putchar(ch);  // 打印文件内容
        }
        printf("\n\n");  // 每个文件内容后换行
    }
    fclose(file);  // 关闭文件
    return 0;
}
