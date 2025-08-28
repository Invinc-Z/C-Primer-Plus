#include <stdio.h>

/**
 * 编写一个函数，把double类型数组中的数据倒序排列，并在一个简单的程序中测试该函数。
 */

void reverse_array(double arr[], int n)
{
	for (int i = 0; i < n / 2; i++)
	{
		double temp = arr[i];
		arr[i] = arr[n - 1 - i];
		arr[n - 1 - i] = temp;
	}
}

int main()
{
	double arr[5] = { 1.2, 3.4, 2.5, 4.6, 0.9 };
	printf("Original array: ");
	for (int i = 0; i < 5; i++)
	{
		printf("%.2f ", arr[i]);
	}
	puts("");
	reverse_array(arr, 5);
	printf("Reversed array: ");
	for (int i = 0; i < 5; i++)
	{
		printf("%.2f ", arr[i]);
	}
	puts("");
    return 0;
}

