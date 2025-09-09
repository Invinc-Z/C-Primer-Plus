#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 10

/**
 * .编写一个函数接受这些参数：内含int类型元素的数组名、数组的大小和一个代表选取次数的值。
 * 该函数从数组中随机选择指定数量的元素，并打印它们。每个元素只能选择一次（模拟抽奖数字或挑选陪审团成员）。
 * 另外，如果你的实现有time()（第12章讨论过）或类似的函数，可在srand()中使用这个函数的输出来初始化随机数生成器rand()。
 * 编写一个简单的程序测试该函数。
 */

void pick(const int* arr, int len, int count)
{
    int idx;
    int temp[SIZE] = {0}; // 标志数组 如果对应位置被选择 置1
    for(int i = 0; i < count; i++)
    {
        do{
            idx = rand() % len;
        }while(arr[idx] == 1);
        temp[idx] = 1;
        printf("%d ", arr[idx]);
    }
    printf("\n");
}

void print_array(const int* arr, int len)
{
    for(int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    srand(time(NULL));
    int arr[SIZE] = {0,1,2,3,4,5,6,7,8,9};
    printf("Origin array is: ");
    print_array(arr, SIZE);
    int count = 2;
    printf("%d lucky body is: ", count);
    pick(arr, SIZE, count);

    return 0;
}
