#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define ANGLETORADIAN(x) ((x) / 180 * PI)

/**
 * 极坐标用向量的模（即向量的长度）和向量相对x轴逆时针旋转的角度来描述该向量。
 * 直角坐标用向量的x轴和y轴的坐标来描述该向量。编写一个程序，读取向量的模和角度（单位：度），然后显示x轴和y轴的坐标。
 * 相关方程如下：
 * x = r*cos A y = r*sin A
 * 需要一个函数来完成转换，该函数接受一个包含极坐标的结构，并返回一个包含直角坐标的结构（或返回指向该结构的指针）。
 */

typedef struct{
    double modulus;
    double angle;
} Polar_t;

typedef struct {
    double x;
    double y;
}Cartesian_t;

void polar2cartesian(const Polar_t* p_polar, Cartesian_t* p_cart);

int main()
{
    Polar_t vector;
    Cartesian_t cart;
    printf("Please enter the modulus of the vector (>=0): ");
    while(scanf("%lf", &vector.modulus) != 1 || vector.modulus < 0)
        continue;
    printf("Please enter the angle of the vector: ");
    while(scanf("%lf", &vector.angle) != 1)
        continue;
    polar2cartesian(&vector, &cart);
    printf("Convert to Cartesian coordinates as: ");
    printf("x = %.2f, y = %.2f\n", cart.x, cart.y);

    return 0;
}

void polar2cartesian(const Polar_t* p_polar, Cartesian_t* p_cart)
{
    p_cart->x = p_polar->modulus * cos(ANGLETORADIAN(p_polar->angle));
    p_cart->y = p_polar->modulus * sin(ANGLETORADIAN(p_polar->angle));
}
