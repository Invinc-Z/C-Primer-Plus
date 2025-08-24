#include <stdio.h>

/**
 * 编写一个程序读取输入，读到#字符停止，然后报告读取的空格数、换行符数和所有其他字符的数量。
 */

int main()
{
    char ch;
    int space = 0;
    int newline = 0;
    int other = 0;
    printf("Please enter some characters (type \'#\' to stop): ");
    while (scanf("%c", &ch) == 1 && ch != '#')
    {
        if (ch == ' ') space++;
        else if (ch == '\n') newline++;
        else other++;
    }
    printf("We got %d spaces, %d newlines, and %d other characters\n",
           space, newline, other);
    return 0;
}

