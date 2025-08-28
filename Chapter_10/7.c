#include <stdio.h>

/**
 * 编写一个程序，初始化一个double类型的二维数组，使用编程练习2中的一个拷贝函数
 * 把该数组中的数据拷贝至另一个二维数组中（因为二维数组是数组的数组，所以可以使用处理一维数组的拷贝函数来处理数组中的每个子数组）。
 */

void copy_ptrs(double* target, double* src_start, double* src_end)
{
	while(src_start < src_end)
		*target++ = *src_start++;
}

int main()
{
	double arr[3][4] = {
		{ 1.1, 2.2, 3.3, 4.4 },
		{ 5.5, 6.6, 7.7, 8.8 },
		{ 9.9, 10.10, 11.11, 12.12 }
	};

	double dest[3][4] = { {0.0} }; // 初始化为0

	for (int i = 0; i < 3; i++)
		copy_ptrs(dest[i], arr[i], arr[i] + 4);
    printf("The dest array is: \n");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
			printf("%.2f\t", dest[i][j]);
		puts("");
	}
    return 0;
}

