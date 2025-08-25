#include <stdio.h>
#define BASE_OVERTIME 40
#define RATIO_OVERTIME 1.5
#define TAX_MONEY_1 300
#define TAX_RATE_1 0.15
#define TAX_MONEY_2 150
#define TAX_RATE_2 0.2
#define TAX_RATE_3 0.25

/**
 * 修改第7章的编程练习8，用字符代替数字标记菜单的选项。用q代替5作为结束输入的标记。
 *
 * 第7章编程练习8如下：
 * 编写一个程序，提示用户输入一周工作的小时数，然后打印工资总额、税金和净收入。
 * 做如下假设：
 * a.基本工资 = 1000美元/小时
 * b.加班（超过40小时） = 1.5倍的时间
 * c.税率： 前300美元为15% 续150美元为20% 余下的为25%
 * 用#define定义符号常量。不用在意是否符合当前的税法。
 *
 * 修改练习7的假设a，让程序可以给出一个供选择的工资等级菜单。使用switch完成工资等级选择。
 * 运行程序后，显示的菜单应该类似这样：
 * *****************************************************************
 * Enter the number corresponding to the desired pay rate or action:
 * 1) $8.75/hr  2) $9.33/hr
 * 3) $10.00/hr 4) $11.20/hr
 * 5) quit
 * *****************************************************************
 * 如果选择1～4其中的一个数字，程序应该询问用户工作的小时数。程序要通过循环运行，除非用户输入5。
 * 如果输入1～5以外的数字，程序应提醒用户输入正确的选项，然后再重复显示菜单提示用户输入。
 * 使用#define创建符号常量表示各工资等级和税率。
 */

void show_menu();
void show_list(double base_salary_hour);

int main()
{
    char choice;
    double base_salary_hour = 0.0;
    show_menu();
    while ((choice = getchar()) != 'q')
    {
        switch (choice) {
        case 'a':
            base_salary_hour = 8.75;
            show_list(base_salary_hour);
            break;
        case 'b':
            base_salary_hour = 9.33;
            show_list(base_salary_hour);
            break;
        case 'c':
            base_salary_hour = 10.00;
            show_list(base_salary_hour);
            break;
        case 'd':
            base_salary_hour = 11.20;
            show_list(base_salary_hour);
            break;
        default:
            printf("Please enter character between 1 and 5: ");
            break;
        }
        while(getchar() != '\n');
        show_menu();
    }
    printf("bye\n");
    return 0;
}

void show_menu()
{
    printf("******************************************************************\n\n");
    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("a) $8.75/hr                    b) $9.33/hr \n");
    printf("c) $10.00/hr                   d) $11.20/hr \n");
    printf("q) quit\n");
    printf("******************************************************************\n\n");
}

void show_list(double base_salary_hour)
{
    double work_hours = 0.0;
    double salary = 0.0;
    double tax = 0.0;
    double pure_salary = 0.0;
    printf("Please enter hours you worked in one week (\'q\' to back): ");
    while (scanf("%lf", &work_hours) == 1) {
        if(work_hours > BASE_OVERTIME)
        {
            double overtime_work = (work_hours - BASE_OVERTIME) * RATIO_OVERTIME;
            work_hours = BASE_OVERTIME + overtime_work;
        }
        salary = work_hours * base_salary_hour;
        if(salary <= TAX_MONEY_1) tax = salary * TAX_RATE_1;
        else if(salary <= (TAX_MONEY_1 + TAX_MONEY_2)) tax = TAX_MONEY_1 * TAX_RATE_1 + (salary - TAX_MONEY_1) * TAX_RATE_2;
        else tax = TAX_MONEY_1 * TAX_RATE_1 + TAX_MONEY_2 * TAX_RATE_2 + (salary - TAX_MONEY_1 - TAX_MONEY_2) * TAX_RATE_3;
        pure_salary = salary - tax;
        printf("The salary is: %.2f$, and tax is: %.2f$, and pure salary is: %.2f$.\n", salary, tax, pure_salary);
        printf("Please enter hours you worked in one week (\'q\' to back): ");
    }
}
