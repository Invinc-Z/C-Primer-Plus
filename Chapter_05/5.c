#include <stdio.h>

/**
 * 修改程序addemup.c（程序清单5.13, 5.4.2节），你可以认为addemup.c是计算20天里赚多少钱的程序
 * （假设第1天赚$1、第2天赚$2、第3天赚$3，以此类推）。
 * 修改程序，使其可以与用户交互，根据用户输入的数进行计算（即，用读入的一个变量来代替20）。
 */

int main()
{
    int days;
    printf("Enter the number of consecutive days you have worked (<=0 to quit): ");
    while(scanf("%d", &days) == 1 && days > 0)
    {
        int sum = 0;
        while(days)
            sum += days--;
        printf("You got $%d\n", sum);
        printf("Enter the number of consecutive days you have worked (<=0 to quit): ");
    }
    printf("bye\n");
    return 0;
}

