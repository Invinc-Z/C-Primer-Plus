#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 100

/**
 * 编写一个程序，生成100个1～10范围内的随机数，并以降序排列（可以把第11章的排序算法稍加改动，便可用于整数排序，这里仅对整数排序）。
 */

void show_array(int arr[], int n);
void my_sort(int arr[], int n);

int main()
{
    srand((unsigned int)time(NULL)); // 使用当前时间作为随机数种子
    int arr[SIZE] = { 0 }; // 初始化数组为0
    for (int i = 0; i < SIZE; i++)
        arr[i] = rand() % 10 + 1; // 生成1到10之间的随机数
    printf("Origin array is: \n");
    show_array(arr, SIZE);
    my_sort(arr, SIZE);
    printf("After sorting, the array is:\n");
    show_array(arr, SIZE);

    return 0;
}

void show_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%-3d ", arr[i]); // 打印数组中的随机数
        if((i+1) % 20 == 0)
            printf("\n"); // 每20个数换行
    }
    printf("\n");
}

void my_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp; // 交换位置
            }
        }
    }
}
