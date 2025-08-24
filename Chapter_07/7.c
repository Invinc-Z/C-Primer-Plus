#include <stdio.h>
#define BASE_SALARY_PER_HOUR 1000
#define BASE_OVERTIME 40
#define RADIO_OVERTIME 1.5
#define TAX_MONEY_1 300
#define TAX_RATE_1 0.15
#define TAX_MONEY_2 150
#define TAX_RATE_2 0.2
#define TAX_RATE_3 0.25

/**
 * 编写一个程序，提示用户输入一周工作的小时数，然后打印工资总额、税金和净收入。
 * 做如下假设：
 * a.基本工资 = 1000美元/小时
 * b.加班（超过40小时） = 1.5倍的时间
 * c.税率： 前300美元为15% 续150美元为20% 余下的为25%
 * 用#define定义符号常量。不用在意是否符合当前的税法。
 */

int main()
{
    double work_hours = 0.0;
    double salary = 0.0;
    double tax = 0.0;
    double pure_salary = 0.0;
    printf("Please enter hours you worked in one week (\'q\' to quit): ");
    while (scanf("%lf", &work_hours) == 1) {
        if(work_hours > BASE_OVERTIME)
        {
            double overtime_work = (work_hours - BASE_OVERTIME) * RADIO_OVERTIME;
            work_hours = BASE_OVERTIME + overtime_work;
        }
        salary = work_hours * BASE_SALARY_PER_HOUR;
        if(salary <= TAX_MONEY_1) tax = salary * TAX_RATE_1;
        else if(salary <= (TAX_MONEY_1 + TAX_MONEY_2)) tax = TAX_MONEY_1 * TAX_RATE_1 + (salary - TAX_MONEY_1) * TAX_RATE_2;
        else tax = TAX_MONEY_1 * TAX_RATE_1 + TAX_MONEY_2 * TAX_RATE_2 + (salary - TAX_MONEY_1 - TAX_MONEY_2) * TAX_RATE_3;
        pure_salary = salary - tax;
    printf("The salary is: %.2f$, and tax is: %.2f$, and pure salary is: %.2f$.\n", salary, tax, pure_salary);
    printf("Please enter hours you worked in one week (\'q\' to quit): ");
    }
    printf("bye\n");
    return 0;
}

