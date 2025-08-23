#include <stdio.h>

/**
 * 编写一个程序，提示用户输入一个double类型的数，并打印该数的立方值。
 * 自己设计一个函数计算并打印立方值。main()函数要把用户输入的值传递给该函数。
 */

double get_cubed(double n);

int main()
{
    double val;
    printf("Please enter a double value: ");
    scanf("%lf", &val);
    printf("The cube of %.2f is %.2f.\n", val, get_cubed(val));
    return 0;
}

double get_cubed(double n)
{
    return n * n * n;
}
