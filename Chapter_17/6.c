#include <stdio.h>
#define SIZE(arr) ( sizeof(arr) / sizeof(arr[0]) )

/**
 * 编写一个函数接受3个参数：一个数组名（内含已排序的整数）、该数组的元素个数和待查找的整数。
 * 如果待查找的整数在数组中，那么该函数返回 1；如果该数不在数组中，该函数则返回 0。
 * 用二分查找法实现。
 */

void show_array(int* arr, int n);
int binary_search(int* arr, int n, int value);

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,16,17,18,19};
    int value = 15;
    int len = SIZE(arr);
    show_array(arr, len);
    printf("value %d is in array: %d\n", value, binary_search(arr, len, value));

    return 0;
}

int binary_search(int* arr, int n, int value)
{
    int left = 0, right = n - 1;
    int diff;
    while(left <= right)
    {
        int mid = left + ((right - left) >> 1);
        diff = value - arr[mid];
        if(diff < 0)
            right = mid - 1;
        else if(diff > 0)
            left = mid + 1;
        else 
            return 1;
    }
    return 0;
}

void show_array(int* arr, int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
