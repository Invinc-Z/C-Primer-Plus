#include <stdio.h>

/*
 * 编写一个程序，创建一个整型变量toes，并将toes设置为10。
 * 程序中还计算toes的两倍和平方。该程序打印3个值，并分别描述以示区分。
*/

int main()
{
    int toes = 10;
    printf("toes = %d, 2 * toes = %d, toes * toes = %d\n",
           toes, 2 * toes, toes * toes);
    return 0;
}

