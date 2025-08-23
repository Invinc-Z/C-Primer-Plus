#include <stdio.h>

/**
 * 编写一个程序，要求用户输入两个浮点数，并打印两数之差除以两数乘积的结果。
 * 在用户输入非数字之前，程序应循环处理用户输入的每对值。
 */

int main()
{
    float f1,f2;
    printf("Please enter two floating-point value (using spaces, tab characters, or line breaks to separate): ");
    while(scanf("%f %f", &f1, &f2) == 2)
    {
        printf("(%.2f - %.2f) / (%.2f * %.2f) = %.2f\n", f1, f2, f1, f2, (f1 - f2) / (f1 * f2));
        printf("Please enter two floating-point value (using spaces, tab characters, or line breaks to separate): ");
    }
    printf("bye\n");
    return 0;
}

