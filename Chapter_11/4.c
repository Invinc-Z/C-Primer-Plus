#include <stdio.h>
#include <string.h>
#define SIZE 8

/**
 * 设计并测试一个函数，它类似编程练习3的描述，只不过它接受第2个参数指明可读取的最大字符数。
 */

void  get_word_n(char* arr, int n)
{
    // 1. 跳过空白
    char ch;
    while(scanf("%c", &ch) && (ch == ' ' || ch == '\t' || ch == '\n'))
        continue;
    // 2. 读取第一个非空白字符
    *arr = ch;
    // 3. 前进一位
    arr++;
    // 4. 现在最多读取n-1个字符并且字符之间不能有空白
    while(--n && scanf("%c", &ch) && ch != ' ' && ch != '\t' && ch != '\n')
    {
        *arr++ = ch;
    }
} // 若读取n个字符，arr数组不会存储空字符,它不能表示字符串,但不会有越界风险

int main()
{
	char arr[SIZE] = { 0 };
    printf("Please enter some characters: ");
	get_word_n(arr, SIZE);
	printf("arr = %s\n", arr);
    return 0;
}

