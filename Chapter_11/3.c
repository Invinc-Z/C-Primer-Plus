#include <stdio.h>
#define SIZE 32

/**
 * 设计并测试一个函数，从一行输入中把一个单词读入一个数组中，并丢弃输入行中的其余字符。
 * 该函数应该跳过第1个非空白字符前面的所有空白。
 * 将一个单词定义为没有空白、制表符或换行符的字符序列。
 */

char* get_word(char* arr)
{
    scanf("%s", arr);
    while (getchar() != '\n');
    return arr;
}

int main()
{
    char arr[SIZE] = { 0 };
    printf("Please enter some characters to make a word: ");
    get_word(arr);
    printf("arr = %s\n", arr);
    return 0;
}

