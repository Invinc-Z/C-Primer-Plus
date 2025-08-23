#include <stdio.h>

/**
 * 编写一个程序打印一个表格，每一行打印一个整数、该数的平方、该数的立方。要求用户输入表格的上下限。使用一个for循环。
 */

int main()
{
    int min;
    int max;
    printf("Please enter table lower limit: ");
    scanf("%d", &min);
    printf("Please enter table upper limit: ");
    scanf("%d", &max);
    printf("-------------------------------------\n");
    printf("\tvalue\tsuqare\tcubed\n");
    for(int i = min; i <= max; i++)
    {
        printf("-------------------------------------\n");
        printf("\t%d\t%d\t%d\n", i, i * i, i * i * i);
    }
    printf("-------------------------------------\n");
    return 0;
}

