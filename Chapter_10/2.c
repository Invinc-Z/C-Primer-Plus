#include <stdio.h>

/**
 * 编写一个程序，初始化一个double类型的数组，然后把该数组的内容拷贝至3个其他数组中（在main()中声明这4个数组）。
 * 使用带数组表示法的函数进行第1份拷贝。使用带指针表示法和指针递增的函数进行第2份拷贝。
 * 把目标数组名、源数组名和待拷贝的元素个数作为前两个函数的参数。
 * 第3个函数以目标数组名、源数组名和指向源数组最后一个元素后面的元素的指针。也就是说，给定以下声明，则函数调用如下所示：
 * double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
 * double target1[5];
 * double target2[5];
 * double target3[5];
 * copy_arr(target1, source, 5);
 * copy_ptr(target2, source, 5);
 * copy_ptrs(target3, source, source + 5);
 */

void copy_arr(double target[], double source[], int n)
{
	for (int i = 0; i < n; i++)
	{
		target[i] = source[i];
	}
}
void copy_ptr(double * target, double * source, int n)
{
	for (int i = 0; i < n; i++)
	{
		*(target + i) = *(source + i);
	}
}
void copy_ptrs(double* target, double* src_start, double* src_end)
{
	while(src_start < src_end)
	{
		*target++ = *src_start++;
	}
}
void print_array(double* arr, int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%.1f ", *(arr+i));
    }
    printf("\n");
}

int main()
{
	double source[5] = { 1.2, 1.3, 1.4, 1.5, 1.6 };
	double target1[5] = {0.0};
	double target2[5] = {0.0}; // 初始化为0
	double target3[5] = { 0.0, 0.0, 0.0, 0.0, 0.0 }; // 初始化为0
	copy_arr(target1, source, 5);
	copy_ptr(target2, source, 5);
	copy_ptrs(target3, source, source + 5);
    printf("target1: ");
    print_array(target1, 5);
    printf("target2: ");
    print_array(target2, 5);
    printf("target3: ");
    print_array(target3, 5);
    return 0;
}

