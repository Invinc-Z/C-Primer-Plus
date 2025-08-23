#include <stdio.h>
#define ARR_SIZE 8
/**
 * 编写一个程序，在数组中读入8个整数，然后按倒序打印这8个整数。
 */

int main()
{
    printf("Please enter %d integers: ", ARR_SIZE);
    int arr[ARR_SIZE] = { 0 };
    int val = 0;
    int i = 0;
    while (i < ARR_SIZE && scanf("%d", &val))
    {
        arr[i++] = val;
    }
    for (int j = ARR_SIZE -1; j > -1; j--)
        printf("%-3d", arr[j]);
    printf("\n");
    return 0;
}

