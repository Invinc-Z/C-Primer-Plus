#include <stdio.h>

/**
 * 编写一个程序，初始化一个double类型的3×5二维数组，使用一个处理变长数组的函数将其拷贝至另一个二维数组中。
 * 还要编写一个以变长数组为形参的函数以显示两个数组的内容。这
 * 两个函数应该能处理任意N×M数组（如果编译器不支持变长数组，就使用传统C函数处理N×5的数组）。
 */

void copy_vla(int rows, int cols, double dest[rows][cols],  double arr[rows][cols])
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			dest[i][j] = arr[i][j];
	}
}

void show_vla(int rows, int cols, double arr[rows][cols])
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			printf("%.2f\t", arr[i][j]);
		puts("");
	}
}

int main()
{
	double arr[3][5] = {
		{ 1.1, 2.2, 3.3, 4.4, 5.5 },
		{ 6.6, 7.7, 8.8, 9.9, 10.10 },
		{ 11.11, 12.12, 13.13, 14.14, 15.15 }
	};
	double dest[3][5] = {0}; // 初始化为0
	copy_vla(3, 5, dest, arr);
	show_vla(3, 5, dest);
    return 0;
}

