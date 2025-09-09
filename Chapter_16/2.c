#include <stdio.h>
#define HARMONIC_MEAN(a,b) (1 / ((1.0 / (a) +  1.0 / (b)) / 2))

/**
 * 两数的调和平均数这样计算：先得到两数的倒数，然后计算两个倒数的平均值，最后取计算结果的倒数。
 * 使用#define指令定义一个宏“函数”，执行该运算。编写一个简单的程序测试该宏。
 */

int main()
{
    int a = 2;
    int b = 4;
    printf("The harmonic mean of %d and %d is %.2f\n", a, b, HARMONIC_MEAN(a, b));

    return 0;
}

