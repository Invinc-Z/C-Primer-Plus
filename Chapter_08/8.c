#include <stdio.h>

/**
 * 编写一个程序，显示一个提供加法、减法、乘法、除法的菜单。
 * 获得用户选择的选项后，程序提示用户输入两个数字，然后执行用户刚才选择的操作。
 * 该程序只接受菜单提供的选项。程序使用float类型的变量储存用户输入的数字，如果用户输入失败，则允许再次输入。
 * 进行除法运算时，如果用户输入0作为第2个数（除数），程序应提示用户重新输入一个新值。
 * 该程序的一个运行示例如下：
 * Enter the operation of your choice:
 * a. add s. subtract
 * m. multiply d. divide
 * q. quit
 * a
 * Enter first number: 22 .4
 * Enter second number: one
 * one is not an number.
 * Please enter a number, such as 2.5, -1.78E8, or 3: 1
 * 22.4 + 1 = 23.4
 * Enter the operation of your choice:
 * a. add s. subtract
 * m. multiply d. divide
 * q. quit
 * d
 * Enter first number: 18.4
 * Enter second number: 0
 * Enter a number other than 0: 0.2
 * 18.4 / 0.2 = 92
 * Enter the operation of your choice:
 * a. add s. subtract
 * m. multiply d. divide
 * q. quit
 * q
 * Bye.
 */

void show_menu();
void get_two_float(float* pf1, float* pf2);
void get_two_float_not_zero(float* pf1, float* pf2);

int main()
{
    char choice = 0;
    float f1 = 0;
    float f2 = 0;
    show_menu();
    while ((choice = getchar()) != 'q')
    {
        switch (choice) {
        case 'a':
            get_two_float(&f1, &f2);
            printf("%.2f + %.2f = %.2f\n", f1, f2, f1 + f2);
            break;
        case 'b':
            get_two_float(&f1, &f2);
            printf("%.2f - %.2f = %.2f\n", f1, f2, f1 - f2);
            break;
        case 'm':
            get_two_float(&f1, &f2);
            printf("%.2f * %.2f = %.2f\n", f1, f2, f1 * f2);
            break;
        case 'd':
            get_two_float_not_zero(&f1, &f2);
            printf("%.2f / %.2f = %.2f\n", f1, f2, f1 / f2);
            break;
        }
        while (getchar() != '\n');
        show_menu();
    }
    printf("Bye!\n");
    return 0;
}

void show_menu()
{
    printf("Enter the operation of your choice:\n");
    printf("a. add                    b. subtract \n");
    printf("m. multiply               d. divide \n");
    printf("q. quit\n");
}

void get_two_float(float* pf1, float* pf2)
{
    char ch;
    printf("Enter first number: ");
    while (scanf("%f", pf1) != 1)
    {
        while ((ch = getchar()) != '\n')
            printf("%c", ch);
        printf(" is not an number.\n");
        printf("Please enter a number, such as 2.5, -1.78E8. or 3: ");
    }
    while ((ch = getchar()) != '\n') ;
    printf("Enter second number: ");
    while (scanf("%f", pf2) != 1)
    {
        while ((ch = getchar()) != '\n')
            printf("%c", ch);
        printf(" is not an number.\n");
        printf("Please enter a number, such as 2.5, -1.78E8. or 3: ");
    }
}

void get_two_float_not_zero(float* pf1, float* pf2)
{
    char ch;
    printf("Enter first number: ");

    while (scanf("%f", pf1) != 1)
    {
        while ((ch = getchar()) != '\n')
            printf("%c", ch);
        printf(" is not an number.\n");
        printf("Please enter a number, such as 2.5, -1.78E8. or 3: ");
    }
    while ((ch = getchar()) != '\n') ;
    printf("Enter second number: ");
label: while (scanf("%f", pf2) != 1)
       {
           while ((ch = getchar()) != '\n')
               printf("%c", ch);
           printf(" is not an number.\n");
           printf("Please enter a number, such as 2.5, -1.78E8. or 3: ");
       }
       if (*pf2 == 0)
       {
           while ((ch = getchar()) != '\n');
           printf("Enter a number other than 0: ");
           goto label;
       }
}
