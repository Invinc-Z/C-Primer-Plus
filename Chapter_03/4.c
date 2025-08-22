#include <stdio.h>

/*
 * 编写一个程序，读取一个浮点数，先打印成小数点形式，再打印成指数形式。
 * 然后，如果系统支持，再打印成p记数法（即十六进制记数法）。按以下格式输出（实际显示的指数位数因系统而异）：
 * Enter a floating-point value: 64.25
 * fixed-point notation: 64.250000
 * exponential notation: 6.425000e+01
 * p notation: 0x1.01p+6
*/

int main()
{
    float fp = 0;
    printf("Enter a floating-point value: ");
    scanf("%f", &fp);
    printf("fixed-point notation: %f\n", fp);
    printf("exponential notation: %e\n", fp);
    printf("p notation: %a\n", fp);
    return 0;
}

