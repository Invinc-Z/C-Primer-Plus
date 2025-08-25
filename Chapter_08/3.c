#include <stdio.h>
#include <ctype.h>

/**
 * 编写一个程序，在遇到 EOF 之前，把输入作为字符流读取。该程序要报告输入中的大写字母和小写字母的个数。
 * 假设大小写字母数值是连续的。或者使用ctype.h库中合适的分类函数更方便。
 */

int main()
{
    char ch;
    int lower_ch = 0;
    int upper_ch = 0;
    printf("Please enter some words to count the number of capital and loowercase letters: ");
    while ((ch = getchar()) != EOF) {
        if (islower(ch)) lower_ch++;
        if (isupper(ch)) upper_ch++;
    }
    printf("The number of capital letters is: %d\n", upper_ch);
    printf("The number of lowercase letters is: %d\n", lower_ch);
    return 0;
}

