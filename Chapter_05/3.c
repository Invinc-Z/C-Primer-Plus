#include <stdio.h>
#define DAYS_PER_WEEK 7

/**
 * 编写一个程序，提示用户输入天数，然后将其转换成周数和天数。
 * 例如，用户输入18，则转换成2周4天。以下面的格式显示结果：
 * 18 days are 2 weeks, 4 days.
 * 通过while循环让用户重复输入天数，当用户输入一个非正值时（如0或-20），循环结束。
 */

int main()
{
    int days;           // 存储转换前的天数
    int weeks;          // 存储转换后的周数
    int residue_day;    // 存储转换后的天数

    printf("Please enter the number of days (<=0 to quit): ");
    while(scanf("%d", &days) == 1 && days > 0)
    {
        weeks = days / DAYS_PER_WEEK;
        residue_day = days % DAYS_PER_WEEK;
        printf("%d %s %s %d %s, %d %s.\n", days, days > 1 ? "days" : "day", days > 1 ? "are" : "is",
               weeks, weeks > 1 ? "weeks" : "week", residue_day, residue_day > 1 ? "days" : "day");
        printf("Please enter the number of days (<=0 to quit): ");
    }
    return 0;
}

