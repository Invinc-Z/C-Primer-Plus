#include <stdio.h>
#define LITERS_PER_GALLON 3.785
#define KMS_PER_MILE 1.609

/**
 * 编写一个程序，提示用户输入旅行的里程和消耗的汽油量。然后计算并显示消耗每加仑汽油行驶的英里数，显示小数点后面一位数字。
 * 接下来，使用1加仑大约3.785升，1英里大约为1.609千米，把单位是英里/加仑的值转换为升/100公里（欧洲通用的燃料消耗表示法），
 * 并显示结果，显示小数点后面1位数字。
 * 注意，美国采用的方案测量消耗单位燃料的行程（值越大越好），而欧洲则采用单位距离消耗的燃料测量方案（值越低越好）。
 * 使用#define 创建符号常量或使用 const 限定符创建变量来表示两个转换系数。
 */

int main()
{
    float distance_miles;
    float gas_gallons;
    printf("Please enter the travel mileage: ");
    scanf("%f", &distance_miles);
    printf("Please enter the amount of gasoline consumed (in gallons): ");
    scanf("%f", &gas_gallons);
    printf("Miles per gallon (MPG) = %.1f\n", distance_miles / gas_gallons);
    printf("The gas consumed: %.1fL/100Km\n", gas_gallons * LITERS_PER_GALLON / (distance_miles * KMS_PER_MILE) * 100);
    return 0;
}

