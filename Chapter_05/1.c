#include <stdio.h>
#define MINUTES_PER_HOUR 60

/**
 * 编写一个程序，把用分钟表示的时间转换成用小时和分钟表示的时间。
 * 使用#define或const创建一个表示60的符号常量或const变量。
 * 通过while循环让用户重复输入值，直到用户输入小于或等于0的值才停止循环。
 */

int main()
{
    int minutes;    // 储存转换前的分钟
    int hours;      // 储存转换后的小时
    int mins;       // 储存转换后的分钟
    printf("Please enter minutes (<=0 to quit): ");
    while(scanf("%d", &minutes) == 1 && minutes > 0)
    {
        hours = minutes / MINUTES_PER_HOUR;
        mins = minutes % MINUTES_PER_HOUR;
        printf("%d minutes can convert to %d %s and %d %s\n", 
               minutes, hours, hours > 1 ? "hours" : "hour", mins, mins > 1 ? "minutes" : "minute" );
        printf("Please enter minutes (<=0 to quit): ");
    }
    return 0;
}

