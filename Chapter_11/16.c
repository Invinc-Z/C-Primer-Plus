#include <stdio.h>
#include <string.h>
#include <ctype.h>

/**
 * .编写一个程序读取输入，直至读到文件结尾，然后把字符串打印出来。
 * 该程序识别和实现下面的命令行参数：
 * -p 按原样打印
 * -u 把输入全部转换成大写
 * -l 把输入全部转换成小写
 *  如果没有命令行参数，则让程序像是使用了-p参数那样运行。
 */

int main(int argc, char* argv[])
{
    char ch;
    if (argc == 1)
    {
        while(scanf("%c", &ch) == 1)
            printf("%c", ch);
    }
    if (argc == 2)
    {
        if (strcmp(argv[1], "-p") == 0)
        {
            while (scanf("%c", &ch) == 1)
                printf("%c", ch);
        }
        else if (strcmp(argv[1], "-u") == 0)
        {
            while (scanf("%c", &ch) == 1)
                printf("%c", toupper(ch));
        }
        else if (strcmp(argv[1], "-l") == 0)
        {
            while (scanf("%c", &ch) == 1)
                printf("%c", tolower(ch));
        }
        else
        {
            printf("Invalid option. Use -p, -u, or -l.\n");
            return -1;
        }
    }

    return 0;
}
