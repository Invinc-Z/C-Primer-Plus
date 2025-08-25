#include <stdio.h>

/**
 * 两数的调和平均数这样计算：先得到两数的倒数，然后计算两个倒数的平均值，最后取计算结果的倒数。
 * 编写一个函数，接受两个double类型的参数，返回这两个参数的调和平均数。
 */

double get_harmonic_mean(double i, double j)
{
    return 1 / ((1 / i + 1 / j) / 2);
}
int main()
{
    double i = 1.2;
    double j = 1.3;
    printf("The harmonic mean of %.2lf and %.2lf is %.2lf.\n", i, j, get_harmonic_mean(i, j));
    return 0;
}



