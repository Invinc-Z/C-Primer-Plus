#include <stdio.h>

/**
 * 编写一个函数，返回储存在double类型数组中最大值和最小值的差值，并在一个简单的程序中测试该函数。
 */

double get_diff_array(double arr[], int n)
{
	double max = arr[0];
	double min = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	return max - min;
}

int main()
{
	double arr[5] = { 1.2, 3.4, 2.5, 4.6, 0.9 };
	double diff = get_diff_array(arr, 5);
	printf("The difference between the maximum and minimum values in the array is: %.2f\n", diff);
    return 0;
}

