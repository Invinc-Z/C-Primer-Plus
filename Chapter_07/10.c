#include <stdio.h>
#define TAX_BASE_RATIO 0.15
#define TAX_EXCEED_RATIO 0.28
#define TAX_SALARY_SINGLE 17850
#define TAX_SALARY_MASTER 23900
#define TAX_SALARY_MARRIED 29750
#define TAX_SALARY_DIVORCED 14875

/**
 * 1988年的美国联邦税收计划是近代最简单的税收方案。它分为4个类别，每个类别有两个等级。
 * 下面是该税收计划的摘要（美元数为应征税的收入）：
 * 类别         税金
 * 单身         17850美元按15%计，超出部分按28%计
 * 户主         23900美元按15%计，超出部分按28%计
 * 已婚，共有   29750美元按15%计，超出部分按28%计
 * 已婚，离异   14875美元按15%计，超出部分按28%计
 * 例如，一位工资为20000美元的单身纳税人，应缴纳税费0.15×17850+0.28×（20000−17850）美元。
 * 编写一个程序，让用户指定缴纳税金的种类和应纳税收入，然后计算税金。
 * 程序应通过循环让用户可以多次输入。
 */

int main()
{
    char choice;
    double salary = 0.0;
    double tax_money = 0.0;
    do
    {
        printf("Please enter the tax category (a. single  b. master  c. married  d. divorced  q. quit): ");
        scanf(" %c", &choice);
        if (choice == 'q') break;
        if(choice < 'a' || choice > 'd') continue;
        // 清除输入缓冲区中的剩余字符
        while (getchar() != '\n') ;
        printf("Please enter salary: ");
        while(scanf("%lf", &salary) != 1)
        {
            printf("Error format. Please enter salary with a double value: ");
        }
        // 清除输入缓冲区中的剩余字符
        while (getchar() != '\n') ;
        switch (choice)
        {
        case 'a':
            if (salary < TAX_SALARY_SINGLE) tax_money = salary * TAX_BASE_RATIO;
            else if (salary >= TAX_SALARY_SINGLE) tax_money = TAX_SALARY_SINGLE * TAX_BASE_RATIO + (salary - TAX_SALARY_SINGLE) * TAX_EXCEED_RATIO;
            printf("Category single, salary $%.2f will pay $%.2f tax.\n", salary, tax_money);
            break;
        case 'b':
            if (salary < TAX_SALARY_MASTER) tax_money = salary * TAX_BASE_RATIO;
            else if (salary >= TAX_SALARY_MASTER) tax_money = TAX_SALARY_MASTER * TAX_BASE_RATIO + (salary - TAX_SALARY_MASTER) * TAX_EXCEED_RATIO;
            printf("Category master, salary $%.2f will pay $%.2f tax.\n", salary, tax_money);
            break;
        case 'c':
            if (salary < TAX_SALARY_MARRIED) tax_money = salary * TAX_BASE_RATIO;
            else if (salary >= TAX_SALARY_MARRIED) tax_money = TAX_SALARY_MARRIED * TAX_BASE_RATIO + (salary - TAX_SALARY_MARRIED) * TAX_EXCEED_RATIO;
            printf("Category married, salary $%.2f will pay $%.2f tax.\n", salary, tax_money);
            break;
        case 'd':
            if (salary < TAX_SALARY_DIVORCED) tax_money = salary * TAX_BASE_RATIO;
            else if (salary >= TAX_SALARY_DIVORCED) tax_money = TAX_SALARY_DIVORCED * TAX_BASE_RATIO + (salary - TAX_SALARY_DIVORCED) * TAX_EXCEED_RATIO;
            printf("Category divorced, salary $%.2f will pay $%.2f tax.\n", salary, tax_money);
            break;
        default:
            break;
        }
    } while (1);
    printf("bye\n");
    return 0;
}
