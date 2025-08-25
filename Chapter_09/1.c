#include <stdio.h>

/**
 * 设计一个函数min(x, y)，返回两个double类型值的较小值。在一个简单的驱动程序中测试该函数。
 */

double min(double d1, double d2)
{
	return d1 < d2 ? d1 : d2;
}

int main()
{
    double d1 = 1.2, d2 = 1.3;
    printf("Between %.2f and %.2f the min value is %.2f\n", d1, d2, min(d1, d2));
    return 0;
}

