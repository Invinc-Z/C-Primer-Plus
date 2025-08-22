#include <stdio.h>
#define CENTIMETERS_PER_INCH 2.54

/**
 * 1英寸相当于2.54厘米。编写一个程序，提示用户输入身高（/英寸），然后以厘米为单位显示身高。
 */

int main()
{
    float height;
    printf("Please enter your height(with inches): ");
    scanf("%f", &height);
    printf("Your height is %.2f in, which converts to %.2f cm.\n", height, height * CENTIMETERS_PER_INCH);
    return 0;
}

