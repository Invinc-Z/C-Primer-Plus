#include <stdio.h>
#define MONTHS 12
#define YEARS 5
/**
 * 修改程序清单10.7(10.2节)的rain.c程序，用指针进行计算（仍然要声明并初始化数组）。
 */

int main()
{
    // 计算每年的总降水量、年平均降水量和5年中每月的平均降水量

    // 用2010-2014年的降水量数据来初始化数组
    const float rain[YEARS][MONTHS] = {
        { 2.4, 3.1, 4.5, 5.0, 6.2, 7.1, 8.3, 9.0, 1.1, 1.2, 1.3, 1.4 }, // 2010
        { 2.5, 3.2, 4.6, 5.1, 6.3, 7.2, 8.4, 9.1, 1.2, 1.3, 1.4, 1.5 }, // 2011
        { 2.6, 3.3, 4.7, 5.2, 6.4, 7.3, 8.5, 9.2, 1.3, 1.4, 1.5, 1.6 }, // 2012
        { 2.7, 3.4, 4.8, 5.3, 6.5, 7.4, 8.6, 9.3, 1.4, 1.5, 1.6, 1.7 }, // 2013
        { 2.8, 3.5, 4.9, 5.4, 6.6, 7.5, 8.7, 9.4, 1.5, 1.6, 1.7, 1.8 }  // 2014
    };
    int year, month;
    float subtotal, total;
    printf("YEAR RAINFALL (inches)\n");
    for (year = 0, total = 0; year < YEARS; year++)
    {
        for (month = 0, subtotal = 0; month < MONTHS; month++)
        {
            subtotal += *(*(rain + year) + month);
        }
        printf("%5d %15.1f\n", 2010 + year, subtotal);
        total += subtotal;
    }
    printf("\nThe yearly average is %.1f inches.\n\n", total / YEARS);
    printf("MONTHLY AVERAGES:\n\n");
    printf(" Jan Feb Mar Apr May Jun Jul Aug Sep Oct ");
    printf("Nov Dec\n");
    for (month = 0; month < MONTHS; month++)
    { // 每个月，5年的总降水量
        for (year = 0, subtotal= 0; year < YEARS; year++)
            subtotal += *(*(rain + year) + month);
        printf("%4.1f", subtotal / YEARS);
    }
    printf("\n");
    return 0;
}

