#include <stdio.h>

/**
 * 编写一个程序，读取一个浮点数，首先以小数点记数法打印，然后以指数记数法打印。
 * 用下面的格式进行输出（系统不同，指数记数法显示的位数可能不同）：
 * a. 输入21.3或2.1e+001；
 * b. 输入+21.290或2.129E+001；
 */

int main()
{
    float f1 = 0;
    printf("Please enter a floating-point value: ");
    scanf("%f", &f1);
    printf("f1 = %.1f, or = %.1e\n", f1, f1);

    float f2 = 0;
    printf("Please enter a floating-point value: ");
    scanf("%f", &f2);
    printf("f2 = %+.3f, or = %.3E\n", f2, f2);
    return 0;
}

