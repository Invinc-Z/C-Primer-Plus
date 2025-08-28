#include <stdio.h>

/**
 * 编写一个程序，声明一个int类型的3×5二维数组，并用合适的值初始化它。
 * 该程序打印数组中的值，然后各值翻倍（即是原值的2倍），并显示出各元素的新值。
 * 编写一个函数显示数组的内容，再编写一个函数把各元素的值翻倍。
 * 这两个函数都以函数名和行数作为参数。
 */

void show_array(int (*arr)[5], int rows)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < 5; j++)
			printf("%d\t", arr[i][j]);
		puts("");
	}
}
void arrx2(int (*arr)[5], int rows)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < 5; j++)
			arr[i][j] *= 2; // 将每个元素乘以2
}

int main()
{
	int arr[3][5] = {
		{ 1, 2, 3, 4, 5 },
		{ 6, 7, 8, 9, 10 },
		{ 11, 12, 13, 14, 15 }
	};
	printf("Original array:\n");
	show_array(arr, 3);
	arrx2(arr, 3);
	printf("After multiplying each element by 2:\n");
	show_array(arr, 3);
    return 0;
}

