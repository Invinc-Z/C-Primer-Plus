#include <stdio.h>

/**
 * 编写一个函数，把两个数组中相对应的元素相加，然后把结果储存到第3个数组中。
 * 也就是说，如果数组1中包含的值是2、4、5、8，数组2中包含的值是1、0、4、6，那么该函数把3、4、9、14赋给第3个数组。
 * 函数接受3个数组名和一个数组大小。在一个简单的程序中测试该函数。
 */

void add_two_array(int arr1[], int arr2[], int sum_arr[], int n)
{
	for (int i = 0; i < n; i++)
		sum_arr[i] = arr1[i] + arr2[i];
}

void show_array(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	puts("");
}

int main()
{
	int arr1[5] = { 1, 2, 3, 4, 5 };
	int arr2[5] = { 6, 7, 8, 9, 10 };
	int sum_arr[5] = { 0 }; // 初始化为0
	add_two_array(arr1, arr2, sum_arr, 5);
    printf("arr1 is: ");
	show_array(arr1, 5);
    printf("arr2 is: ");
	show_array(arr2, 5);
    printf("arr1 + arr2 is: ");
	show_array(sum_arr, 5);
    return 0;
}

