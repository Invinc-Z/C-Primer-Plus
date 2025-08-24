#include <stdio.h>

/**
 * 编写程序读取输入，读到#停止，报告ei出现的次数。
 * 注意
 * 该程序要记录前一个字符和当前字符。用“Receive your eieio award”这样的输入来测试。
 */

int main()
{
    char prev = 0;
    char now = 0;
    printf("Please enter some characters (\'#\' to stop): ");
    int count = 0;
    while ((now = getchar()) != '#') {
        if (prev == 'e' && now == 'i') count++;
        prev = now;
    }
    printf("The 'ei' occurs %d.\n", count);
    return 0;
}

