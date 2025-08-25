#include <stdio.h>

/**
 * 编写并测试一个函数，该函数以3个double变量的地址作为参数，
 * 把最小值放入第1个变量，中间值放入第2个变量，最大值放入第3个变量。
 */

void larger_of_three(double* pa, double* pb, double* pc);

int main()
{
    double a = 1.6;
    double b = 1.7;
    double c = 1.4;
    printf("before swap: a = %.2f, b = %.2f, c = %.2f\n", a, b, c);
    larger_of_three(&a, &b,&c);
    printf("after swap: a = %.2f, b = %.2f, c = %.2f\n", a, b, c);
    return 0;
}

void larger_of_three(double* pa, double* pb, double* pc)
{
    double temp = 0;
    if (*pa < *pb)
    {
        if (*pa > *pc)
        {
            double temp_a = *pa;
            temp = *pb;
            *pa = *pc;
            *pb = temp_a;
            *pc = temp;
        }
        else if (*pa < *pc)
        {
            if (*pb < *pc)
            {
                ;
            }
            else if(*pb > *pc)
            {
                temp = *pb;
                *pb = *pc;
                *pc = temp;
            }
        }
    }
    else if (*pa > *pb)
    {
        if (*pa < *pc)
        {
            temp = *pa;
            *pa = *pb;
            *pb = temp;
        }
        else if (*pa > *pc)
        {
            if (*pb < *pc)
            {
                temp = *pa;
                *pa = *pb;
                *pb = *pc;
                *pc = temp;
            }
            else if (*pb > *pc)
            {
                temp = *pa;
                *pa = *pc;
                *pc = temp;
            }
        }
    }
}

