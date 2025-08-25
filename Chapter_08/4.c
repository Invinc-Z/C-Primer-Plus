#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
/**
 * 编写一个程序，在遇到EOF之前，把输入作为字符流读取。该程序要报告平均每个单词的字母数。
 * 不要把空白统计为单词的字母。实际上，标点符号也不应该统计，
 * 但是现在暂时不同考虑这么多（如果你比较在意这点，考虑使用ctype.h系列中的ispunct()函数）。
 */

int main()
{
    bool inword = false; // 如果ch在单词中，inword为true
    int word_count = 0;
    int ch_count = 0;
    char ch; // 读入字符
    printf("Please enter some words to count the average letter number in one word: \n");
    while ((ch = getchar()) != EOF) {
        if (ispunct(ch)) ch = ' ';
        if (!isspace(ch))
        {
            ch_count++;
            if (!inword)
            {
                inword = true; // 开始一个新的单词
                word_count++;
            }
        }
        if (isspace(ch) && inword) // 单词末尾
        {
            inword = false;
        }
    }
    printf("The number of average character in one word is %d.\n", ch_count / word_count);
    return 0;
}

