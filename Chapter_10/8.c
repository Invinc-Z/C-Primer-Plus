#include <stdio.h>
/**
 * 使用编程练习2中的拷贝函数，把一个内含7个元素的数组中第3～第5个元素拷贝至内含3个元素的数组中。
 * 该函数本身不需要修改，只需要选择合适的实际参数（实际参数不需要是数组名和数组大小，只需要是数组元素的地址和待处理元素的个数）。
 */

void copy_ptr(double * target, double * source, int n)
{
	for (int i = 0; i < n; i++)
		*(target + i) = *(source + i);
}

int main()
{
	double arr[7] = { 1,2,3,4,5,6,7 };
	double dest[3] = { 0 };

	copy_ptr(dest, (arr + 2), 3);

    printf("arr is: ");
	for (int i = 0; i < 7; i++)
		printf("%.1f ", arr[i]);
    printf("\n");
    printf("dest is: ");
	for (int i = 0; i < 3; i++)
		printf("%.1f ", dest[i]);
    printf("\n");
    return 0;
}

