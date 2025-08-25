#include <stdio.h>

/**
 * 第6章的程序清单6.20中，power()函数返回一个double类型数的正整数次幂。改进该函数，使其能正确计算负幂。
 * 另外，函数要处理0的任何次幂都为0，任何数的0次幂都为1（函数应报告0的0次幂未定义，因此把该值处理为1）。
 * 要使用一个循环，并在程序中测试该函数。
 */

double power(double base, int exponent);

int main()
{
    double base = 0.0;
    int exponent = 0.0;
    double result = power(base, exponent);
    printf("%.2f raised to the power of %d is %.5f.\n", base, exponent, result);
    return 0;
}

double power(double base, int exponent)
{
    double result = 1.0;
    if(base == 0)
    {
        if(exponent == 0)
        {
            printf("0^0 is undefined, returning 1.0.\n");
            return 1.0; // 0^0 is often defined as 1 in programming contexts
        }
        return 0.0; // 0 raised to any positive exponent is 0
    }
    if (exponent < 0)
    {
        for (int i = 0; i < -exponent; i++)
            result /= base;
    }
    if (exponent > 0)
    {
        for (int i = 0; i < exponent; i++)
            result *= base;
    }
    return result;
}

