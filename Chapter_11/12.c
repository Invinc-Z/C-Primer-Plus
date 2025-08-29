#include <stdio.h>
#include <ctype.h>
#define SIZE 1024
/**
 * 编写一个程序，读取输入，直至读到 EOF，报告读入的单词数、大写字母数、小写字母数、标点符号数和数字字符数。
 * 使用ctype.h头文件中的函数。
 */

int main()
{
	printf("Please input some words: \n");
	char str[SIZE] = { 0 };
	int word_count = 0, big_alpha_count = 0, small_alpha_count = 0, punctuation_count = 0, numeric_count = 0;
	while (fgets(str, sizeof(str), stdin))
	{
		char* p = str;
		while (*p != '\0')
		{
			if (isalpha(*p))
			{
				if (isupper(*p))
					big_alpha_count++;
				else
					small_alpha_count++;
			}
			else if (isdigit(*p))
				numeric_count++;
			else if (ispunct(*p))
				punctuation_count++;
			if (*p == ' ' || *p == '\t' || *p == '\n') // 如果是空格、制表符或换行符，认为是一个单词的结束
				word_count++;
			p++;
		}
	}
    printf("---------------------------\n");
	printf("Word count: %d\n", word_count);
	printf("Big alphabet count: %d\n", big_alpha_count);
	printf("Small alphabet count: %d\n", small_alpha_count);
	printf("Punctuation marks count: %d\n", punctuation_count);
	printf("Numeric characters count: %d\n", numeric_count);
    return 0;
}

