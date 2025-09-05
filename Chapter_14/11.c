#include <stdio.h>
#include <math.h>
#define PI 3.14159265
#define SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

/**
 * 编写一个名为transform()的函数，接受4个参数：
 * 内含double类型数据的源数组名、内含double类型数据的目标数组名、
 * 一个表示数组元素个数的int类型参数、函数名（或等价的函数指针）。
 * transform()函数应把指定函数应用于源数组中的每个元素，并把返回值储存在目标数组中。
 * 例如：transform(source, target, 100, sin);
 * 该声明会把target[0]设置为sin(source[0])，等等，共有100个元素。
 * 在一个程序中调用transform()4次，以测试该函数。
 * 分别使用math.h函数库中的两个函数以及自定义的两个函数作为参数。
 */

typedef double (*Func)(double x);
void transform(double* src, double* dest, int n, Func func);
void show_array(double* arr, int n);
void deg2rad(double* deg, double* rad, int n);
double opposite(double x);
double plus_one(double x);

int main()
{
    double degrees[] = {30.0, 60.0, 90.0, 120.0, 150.0, 180.0};
    double radians[6] = {0};
    double dest[6] = {0};

    deg2rad(degrees, radians, SIZE(degrees));

    printf("origin degree x is: \n");
    show_array(degrees, SIZE(degrees));

    printf("sin(x) is: ");
    transform(radians, dest, SIZE(radians), sin);
    show_array(dest, SIZE(dest));

    printf("cos(x) is: ");
    transform(radians, dest, SIZE(radians), cos);
    show_array(dest, SIZE(dest));

    printf("x * -1 is: ");
    transform(degrees, dest, SIZE(radians), opposite);
    show_array(dest, SIZE(dest));

    printf("x + 1 is: ");
    transform(degrees, dest, SIZE(radians), plus_one);
    show_array(dest, SIZE(dest));
    return 0;
}

void transform(double* src, double* dest, int n, Func func)
{
    for(int i = 0; i < n; i++)
        dest[i] = func(src[i]);
}

void show_array(double* arr, int n)
{
    for(int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
    printf("\n");
}

void deg2rad(double* deg, double* rad, int n)
{
    for(int i = 0; i < n; i++)
        rad[i] = deg[i] * PI / 180;
}

double opposite(double x)
{
    return x * -1;
}

double plus_one(double x)
{
    return x + 1;
}
