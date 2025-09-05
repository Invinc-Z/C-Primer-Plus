#include <stdio.h>
#include <stdbool.h>

/**
 * 编写一个函数，提示用户输入日、月和年。月份可以是月份号、月份名或月份名缩写。
 * 然后该程序应返回一年中到用户指定日子（包括这一天）的总天数。
 */

// 月份结构体
struct Month {
    char name[12];      // 月份全名
    char abbr[4];       // 月份缩写
    int days;           // 该月天数
    int num;            // 月份数字
};
// 全局月份数组
const struct Month months[12] = {
    {"January", "Jan", 31, 1},
    {"February", "Feb", 28, 2},
    {"March", "Mar", 31, 3},
    {"April", "Apr", 30, 4},
    {"May", "May", 31, 5},
    {"June", "Jun", 30, 6},
    {"July", "Jul", 31, 7},
    {"August", "Aug", 31, 8},
    {"September", "Sep", 30, 9},
    {"October", "Oct", 31, 10},
    {"November", "Nov", 30, 11},
    {"December", "Dec", 31, 12}
};

// 函数声明
void get_date(int* years, int* months, int* days);
bool is_leap_year(int year);
int calculate_total_days(int year, int month_index, int day);

int main()
{
    int n_years, n_months, n_days, total_days;
    get_date(&n_years, &n_months, &n_days);
    // 计算总天数
    total_days = calculate_total_days(n_years, n_months - 1, n_days);
    printf("%d-%d-%d is the %d-th day at this year.\n", n_years, n_months, n_days, total_days);

    return 0;
}

void get_date(int* years, int* months, int* days)
{
    // 获取用户输入
    printf("Please enter the year: ");
    while(scanf("%d", years) != 1)
    {
        while(getchar() != '\n')
            continue;
        printf("Please enter an integer: ");
    }
    printf("Please enter the month (1-12): ");
    while(scanf("%d", months) != 1 || *months < 1 || *months > 12)
    {
        while(getchar() != '\n')
            continue;
        printf("Please enter the month (1-12): ");
    }

    printf("Please enter the day (1-31): ");
    while(scanf("%d", days) != 1 || *days < 1 || *days > 31)
    {
        while(getchar() != '\n')
            continue;
        printf("Please enter the day (1-31): ");
    }
}

bool is_leap_year(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 计算总天数
int calculate_total_days(int year, int month_index, int day) {
    int total = 0;

    // 累加之前月份的天数
    for (int i = 0; i < month_index; i++) {
        total += months[i].days;
        // 闰年2月特殊处理
        if (i == 1 && is_leap_year(year)) {
            total += 1;
        }
    }
    // 加上当前月的天数
    total += day;
    return total;
}
