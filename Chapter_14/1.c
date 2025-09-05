#include <stdio.h>
#include <string.h>
#define SIZE 64

/**
 * 复习题5：
 * 编写一个函数，用户提供月份号，该函数就返回一年中到该月为止（包括该月）的总天数。
 * 假设在所有函数的外部声明了第3题的结构模版和一个该类型结构的数组。
 *
 * 重新编写复习题5，用月份名的拼写代替月份号（别忘了使用strcmp()）。在一个简单的程序中测试该函数。
 */

typedef struct {
    char month[4];  // 月份名称缩写
    int days;  // 月份天数
    int month_num; // 月份号
} Month;

const Month months[] = {
    {"Jan", 31, 1},
    {"Feb", 28, 2},
    {"Mar", 31, 3},
    {"Apr", 30, 4},
    {"May", 31, 5},
    {"Jun", 30, 6},
    {"Jul", 31, 7},
    {"Aug", 31, 8},
    {"Sep", 30, 9},
    {"Oct", 31, 10},
    {"Nov", 30, 11},
    {"Dec", 31, 12}
};

char* s_gets(char* str, int n);
int get_days_by_months(const char* str);

int main()
{
    char str[SIZE] = {0};
    printf("Please enter the short name of month(q to quit): ");
    while(s_gets(str, sizeof(str)) && str[0] != 'q')
    {
        int ret = get_days_by_months(str);
        if(ret == 0)
        {
            printf("Invalid short month name. Please enter short month name again (q to quit): ");
            continue;
        }
        printf("The total number of days from Jan. to %s. is: %d.\n", str, ret);
        printf("Please enter the short name of month(q to quit): ");
    }
    printf("bye\n");

    return 0;
}

char* s_gets(char* str, int n)
{
    char* ret_val;
    char* find;
    ret_val = fgets(str, n, stdin);
    if(ret_val)
    {
        if((find = strchr(str, '\n')))
            *find = '\0';
        else
        {
            while(getchar() != '\n')
                continue;
        }
    }
    return ret_val;
}
int get_days_by_months(const char* str)
{
    int total_days = 0;
    int flag = 0;   // 标志str是否是无效字符 flag == 12 无效
    for(size_t i = 0; i < sizeof(months) / sizeof(months[0]); i++)
    {
        total_days += months[i].days;
        if(strcmp(str, months[i].month) == 0)
            break;
        else
            flag++;
    }
    if(flag == sizeof(months) / sizeof(months[0]))
        total_days = 0;
    return total_days;
}
