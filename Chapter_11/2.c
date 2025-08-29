#include <stdio.h>
#define SIZE 256

/**
 * 修改并编程练习1的函数，在n个字符后停止，或在读到第1个空白、制表符或换行符时停止，哪个先遇到哪个停止。不能只使用scanf()。
 */


void get_n_character(char* arr, int n)
{
	int i = 0;
	while (i < n && scanf("%c", &arr[i]) && arr[i] != ' ' && arr[i] != '\t' && arr[i] != '\n')
		i++;
}

int main()
{
	char arr[SIZE] = { 0 };
    printf("Please enter some characters: \n");
	get_n_character(arr, sizeof(arr));
    printf("================================================\n");
    printf("The array is: \n");
	for (int i = 0; i < SIZE; i++)
	{
		if (arr[i] == '\0') break; // 避免打印未初始化的字符
		printf("%c", arr[i]);
	}
    printf("\n");
    return 0;
}

