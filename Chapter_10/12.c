#include <stdio.h>
#define MONTHS 12
#define YEARS 5
/**
 * 重写程序清单10.7(10.2节)的rain.c程序，把main()中的主要任务都改成用函数来完成。
 */

float get_total_print_subtotal(const float rain[][MONTHS], int years);
void print_each_month_average(const float rain[][MONTHS], int years);
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
    float total = get_total_print_subtotal(rain, YEARS);
    printf("\nThe yearly average is %.1f inches.\n\n", total / YEARS);
    print_each_month_average(rain, YEARS);
    return 0;
}

float get_total_print_subtotal(const float rain[][MONTHS], int years)
{
    float total = 0;
    printf("YEAR RAINFALL (inches)\n");
    for (int year = 0; year < years; year++)
    {
        float subtotal = 0;
        for (int month = 0; month < MONTHS; month++)
            subtotal += *(*(rain + year) + month);
        printf("%5d %15.1f\n", 2010 + year, subtotal);
        total += subtotal;
    }
    return total;
}

void print_each_month_average(const float rain[][MONTHS], int years)
{
    printf("MONTHLY AVERAGES:\n\n");
    printf(" Jan Feb Mar Apr May Jun Jul Aug Sep Oct ");
    printf("Nov Dec\n");
    for (int month = 0; month < MONTHS; month++)
    { // 每个月，5年的总降水量
        float subtotal = 0;
        for (int year = 0; year < years; year++)
            subtotal += *(*(rain + year) + month);
        printf("%4.1f", subtotal / years);
    }
    printf("\n");
}
