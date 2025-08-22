#include <stdio.h>
#include <float.h>

/**
 * 编写一个程序，将一个double类型的变量设置为1.0/3.0，一个float类型的变量设置为1.0/3.0。
 * 分别显示两次计算的结果各3次：一次显示小数点后面6位数字；一次显示小数点后面12位数字；一次显示小数点后面16位数字。
 * 程序中要包含float.h头文件，并显示FLT_DIG和DBL_DIG的值。1.0/3.0的值与这些值一致吗？
 */ 

int main()
{
    double d1 = 1.0 / 3.0;
    float f1 = 1.0 / 3.0;
    printf("double d1 = %.6f\n", d1);
    printf("double d1 = %.12f\n", d1);
    printf("double d1 = %.16f\n", d1);

    printf("float f1 = %.6f\n", f1);
    printf("float f1 = %.12f\n", f1);
    printf("float f1 = %.16f\n", f1);

    printf("FLT_DIG = %d\n", FLT_DIG);
    printf("DBL_DIG = %d\n", DBL_DIG);
    return 0;
}

