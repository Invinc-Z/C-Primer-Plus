#include <stdio.h>

/*
 * 许多研究表明，微笑益处多多。编写一个程序，生成以下格式的输出：
 * Smile!Smile!Smile!
 * Smile!Smile!
 * Smile!
 * 该程序要定义一个函数，该函数被调用一次打印一次"Smile!"，根据程序的需要使用该函数。
*/

// 函数前置声明
void smile();

int main()
{
    smile();
    smile();
    smile();
    printf("\n");
    smile();
    smile();
    printf("\n");
    smile();
    printf("\n");
    return 0;
}

// 函数定义
void smile()
{
    printf("Smile!");
}

