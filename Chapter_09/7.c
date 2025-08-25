#include <stdio.h>
#include <ctype.h>

/**
 * 编写一个函数，从标准输入中读取字符，直到遇到文件结尾。程序要报告每个字符是否是字母。
 * 如果是，还要报告该字母在字母表中的数值位置。
 * 例如，c和C在字母表中的位置都是3。合并一个函数，以一个字符作为参数，如果该字符是一个字母则返回一个数值位置，否则返回-1。
 */

int get_pos(char ch);

int main()
{
	int ch;
    printf("Please enter some characters, the program will give the position at the alphabet table for every letter you entered:\n");
    while ((ch = getchar()) != EOF)
    {
        if(get_pos(ch) != -1)
            printf("The position of '%c' is %d.\n", ch, get_pos(ch));
    }
    return 0;
}

int get_pos(char ch){
    if (isalpha(ch)) {
        if (ch >= 'a' && ch <='z')
			return ch - 'a' + 1;
        else if (ch >= 'A' && ch <= 'Z')
            return ch - 'A' + 1;
    }
	return -1;
}

