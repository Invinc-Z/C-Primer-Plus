#include <stdio.h>

/**
 * 修改练习8，使用一个函数返回计算的结果。
 */

float get_val(float f1, float f2);

int main()
{
    float f1,f2;
    printf("Please enter two floating-point value (using spaces, tab characters, or line breaks to separate): ");
    while(scanf("%f %f", &f1, &f2) == 2)
    {
        printf("(%.2f - %.2f) / (%.2f * %.2f) = %.2f\n", f1, f2, f1, f2, get_val(f1, f2));
        printf("Please enter two floating-point value (using spaces, tab characters, or line breaks to separate): ");
    }
    printf("bye\n");
    return 0;
}

float get_val(float f1, float f2)
{
    return (f1 -f2) / (f1 * f2);
}
