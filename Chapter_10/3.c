#include <stdio.h>

/**
 * 编写一个函数，返回储存在int类型数组中的最大值，并在一个简单的程序中测试该函数。
 */

int max_in_array(int* arr, int n)
{
	int max = *arr;
	for (int i = 1; i < n; i++)
	{
		if (*(arr+i) > max)
		{
			max = *(arr+i);
		}
	}
	return max;
}

int main()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	int max = max_in_array(arr, 5);
	printf("The maximum value in the array is: %d\n", max);
    return 0;
}

