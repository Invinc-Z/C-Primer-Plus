#include <stdio.h>
#include <float.h>  //FLT_MIN
/* 
 * 通过试验（即编写带有此类问题的程序）观察系统如何处理整数上溢、浮点数上溢和浮点数下溢的情况。
 * 浮点数上溢：计算导致数字过大，超出当前类型能表达的范围时，发生上溢
 * 浮点数下溢：计算导致数字过小，必须舍弃尾数中的有效位，发生下溢
 * 具体解释见3.4.6节
*/

int main()
{
    char ch1 = 127;
    // 整数上溢
    char ch2 = 128;
    char ch3 = 129;
    char ch4 = 255;
    printf("ch1 = %d\n", ch1);
    printf("ch2 = %d\n", ch2);
    printf("ch3 = %d\n", ch3);
    printf("ch4 = %d\n", ch4);

    unsigned char ch5 = 255;
    printf("ch5 = %d\n", ch5);

    // 浮点数上溢
    float toobig = 3.4E38 * 100.0f;
    printf("toobig = %e\n", toobig);

    // 浮点数下溢
    float a = 1.0e-20f;  // 非常小的数
    float b = 1.0e-30f;
    float result = a * b;  // 结果为 1.0e-50，远小于最小正数
    printf("a = %e\n", a);
    printf("b = %e\n", b);
    printf("a * b = %e\n", result);
    printf("最小正规格化数: %e\n", FLT_MIN);
    return 0;
}

