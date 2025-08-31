#include <stdio.h>

/**
 * 重新设计编程练习2，要求只使用自动变量。
 * 该程序提供的用户界面不变，即提示用户输入模式等。但是，函数调用要作相应变化。
 */

void set_mode(int * mode, int * old_mode);
void get_info(int mode, double* distance, double* power);
void show_info(int mode, double distance, double power);

int main()
{
    int mode = 0;
    int old_mode = mode;
    double distance = 0.0;
    double power = 0.0;
    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &mode);
    while (mode >= 0)
    {
        set_mode(&mode, &old_mode);
        get_info(mode, &distance, &power);
        show_info(mode, distance, power);
        printf("Enter 0 for metric mode, 1 for US mode (-1 to quit): ");
        scanf("%d", &mode);
    }
    printf("Done.\n");

}

void set_mode(int* mode, int* old_mode)
{
    if (*mode == 0 || *mode == 1)
        *old_mode = *mode;
    else
    {
        printf("Invalid mode specified. Mode %d%s used.\n", *old_mode, *old_mode ? "(US)" : "(metric)");
        *mode = *old_mode; // Reset to the last valid mode
    }
}

void get_info(int mode, double* distance, double* power)
{
    if (mode == 0)
        printf("Enter distance traveled in kilometers: ");
    else if (mode == 1)
        printf("Enter distance traveled in miles: ");
    scanf("%lf", distance);
    if (mode == 0)
        printf("Enter fuel consumed in liters: ");
    else if (mode == 1)
        printf("Enter fuel consumed in miles: ");
    scanf("%lf", power);
}

void show_info(int mode, double distance, double power)
{
    if (mode == 0)
        printf("Fuel consumption is %.2lf liters per 100km.\n", power / distance * 100);
    else if (mode == 1)
        printf("Fuel consumption is %.2lf miles per gallon.\n", distance / power);
}

