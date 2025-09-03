#include <stdio.h>
#include <stdlib.h>

/**
 * 编写一个程序，以一个字符和任意文件名作为命令行参数。
 * 如果字符后面没有参数，该程序读取标准输入；否则，程序依次打开每个文件并报告每个文件中该字符出现的次数。
 * 文件名和字符本身也要一同报告。程序应包含错误检查，以确定参数数量是否正确和是否能打开文件。
 * 如果无法打开文件，程序应报告这一情况，然后继续处理下一个文件。
 */

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "args error\n");
        exit(EXIT_FAILURE);
    }
    char ch = argv[1][0];
    int count = 0;
    char temp;
    if (argc == 2)
    {
        printf("Please input some words, and count \"%c\": ", ch);
        while ((temp = getchar()) != EOF)
            if (temp == ch) count++;
        printf("%c in stdin occurs %d\n", ch, count);
        return 0;
    }

    FILE* fp;
    for (int i = 2; i < argc; i++)
    {
        if ((fp = fopen(argv[i], "r")) == NULL)
        {
            fprintf(stderr, "Error open file \"%s\"\n", argv[i]);
            continue;
        }
        while ((temp = getc(fp)) != EOF)
            if (temp == ch) count++;
        printf("%c in %s occurs %d\n", ch, argv[i], count);
        fclose(fp);
    }

    return 0;
}
