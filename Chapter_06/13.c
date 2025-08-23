#include <stdio.h>

/**
 * 编写一个程序，创建一个包含8个元素的int类型数组，分别把数组元素设置为2的前8次幂。
 * 使用for循环设置数组元素的值，使用do while循环显示数组元素的值。
 */

int main()
{
    int arr[8] = { 0 };
    arr[0] = 1; // 初始化第一个元素
    for (int i = 1; i < 8; i++)
    {
        arr[i] = arr[i - 1] * 2;
    }
    int j = 0;
    do
    {
        printf("%d ", arr[j]);
    } while (++j < 8);
    printf("\n");
    return 0;
}

