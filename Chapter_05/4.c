#include <stdio.h>
#define INCHES_PER_FEET 12
#define CENTIMETERS_PER_INCH 2.54

/**
 * 编写一个程序，提示用户输入一个身高（单位：厘米），并分别以厘米和英寸为单位显示该值，允许有小数部分。
 * 程序应该能让用户重复输入身高，直到用户输入一个非正值。其输出示例如下：
 * Enter a height in centimeters: 182
 * 182.0 cm = 5 feet, 11.7 inches
 * Enter a height in centimeters (<=0 to quit): 168.7
 * 168.0 cm = 5 feet, 6.4 inches
 * Enter a height in centimeters (<=0 to quit): 0
 * bye
 */

int main()
{
    float height;
    printf("Enter a height in centimeters: ");
    while(scanf("%f", &height) == 1 && height > 0)
    {
        float height_inches = height / CENTIMETERS_PER_INCH;
        int height_feet = (int)(height_inches / 12);
        printf("%.1f cm = %d feet, %.1f inches\n", height, height_feet, height_inches - height_feet * INCHES_PER_FEET);
        printf("Enter a height in centimeters (<=0 to quit): ");
    }
    printf("bye\n");
    return 0;
}

