#include <stdio.h>

/**
 * 编写一个函数，返回储存在double类型数组中最大值的下标，并在一个简单的程序中测试该函数。
 */

size_t max_index_in_array(int arr[], int n)
{
	size_t max_index = 0;
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > arr[max_index])
		{
			max_index = i;
		}
	}
	return max_index;
}

int main()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	size_t max_index = max_index_in_array(arr, 5);
	printf("The maximum value in the array is: %d at index %zu\n", arr[max_index], max_index);
    return 0;
}

