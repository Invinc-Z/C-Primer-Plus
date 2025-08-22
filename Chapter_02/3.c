#include <stdio.h>
#define YEAR 365

/**
 * 编写一个程序把你的年龄转换成天数，并显示这两个值。这里不用考虑闰年的问题。
 */

int main()
{
    int age = 0;
    printf("Please input your age: ");
    scanf("%d", &age);
    int age_by_days = age * YEAR;
    printf("Your age is %d years, which converts to %d days.\n", age, age_by_days);
    return 0;
}

