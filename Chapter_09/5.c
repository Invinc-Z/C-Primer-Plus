#include <stdio.h>

/**
 * 编写并测试一个函数larger_of()，该函数把两个double类型变量的值替换为较大的值。
 * 例如， larger_of(x, y)会把x和y中较大的值重新赋给两个变量。
 */

void larger_of(double* pa, double* pb)
{
    if (*pa < *pb)  *pa = *pb;
    if (*pb < *pa)  *pb = *pa;
}

int main()
{
    double a = 1.2;
    double b = 1.3;
    printf("Before swap: a = %.2f, b = %.2f.\n", a, b);
	larger_of(&a, &b);
	printf("After swap: a = %.2f, b = %.2f.\n", a, b);
    return 0;
}

