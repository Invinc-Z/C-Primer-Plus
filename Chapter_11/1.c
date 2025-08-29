#include <stdio.h>
#define SIZE 256

/**
 * 设计并测试一个函数，从输入中获取下n个字符（包括空白、制表符、换行符），
 * 把结果储存在一个数组里，它的地址被传递作为一个参数。
 */

void get_n_character(char* arr, int n)
{
	int i = 0;
	while (i < n && scanf("%c", &arr[i]))
		i++;
}
int main()
{
    printf("Please enter some characters: \n");
	char arr[SIZE] = { 0 };
	get_n_character(arr, sizeof(arr));
    printf("\n========================================\n");
    printf("The arr is: \n");
	for (int i = 0; i < SIZE; i++)
	{
		if (arr[i] == '\0') break; 
		printf("%c", arr[i]);
	}
    printf("\n");
    return 0;
}

