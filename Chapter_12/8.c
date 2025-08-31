#include <stdio.h>
#include <stdlib.h>

/**
 * 提供make_array()和show_array()函数的定义，完成该程序。
 * make_array()函数接受两个参数，第1个参数是int类型数组的元素个数，第2个参数是要赋给每个元素的值。
 * 该函数调用malloc()创建一个大小合适的数组，将其每个元素设置为指定的值，并返回一个指向该数组的指针。
 * show_array()函数显示数组的内容，一行显示8个数。
 */

int * make_array(int elem, int val);
void show_array(const int arr[], int n);

int main()
{
    int* pa;
    int size = 0;
    int value;
    printf("Enter the number of elements: ");
    while (scanf("%d", &size) == 1 && size > 0)
    {
        printf("Enter the initialization value: ");
        scanf("%d", &value);
        pa = make_array(size, value);
        if (pa)
        {
            show_array(pa, size);
            free(pa);
        }
        printf("Enter the number of elements (<1 to quit): ");
    }
    printf("Done.\n");

    return 0;
}

int* make_array(int size, int value)
{
    if (size <= 0)
    {
        printf("Invalid size. Returning NULL.\n");
        return NULL; // 返回NULL表示分配失败
    }
    int* arr = (int*)malloc(size * sizeof(int)); // 动态分配内存
    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL; // 返回NULL表示分配失败
    }
    for (int i = 0; i < size; i++)
        arr[i] = value; // 初始化数组元素
    return arr; // 返回指向数组的指针
}

void show_array(const int arr[], int size)
{
    if (arr == NULL || size <= 0)
    {
        printf("Invalid array or size.\n");
        return; // 如果数组无效或大小无效，直接返回
    }
    printf("Array elements:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]); // 打印数组元素
        if ((i + 1) % 8 == 0) printf("\n"); // 每8个元素换行
    }
    printf("\n");
}

