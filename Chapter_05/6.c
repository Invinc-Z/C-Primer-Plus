#include <stdio.h>

/**
 * 修改编程练习5的程序，使其能计算整数的平方和（可以认为第1天赚$1、第2天赚$4、第3天赚$9，以此类推，这看起来很不错）。
 * C没有平方函数，但是可以用n * n来表示n的平方。
 */

int main()
{
    int days;
    printf("Enter the number of consecutive days you have worked (<=0 to quit): ");
    while(scanf("%d", &days) == 1 && days > 0)
    {
        int sum = 0;
        while(days)
        {
            sum += days * days;
            days--;
        }
        printf("You got $%d\n", sum);
        printf("Enter the number of consecutive days you have worked (<=0 to quit): ");
    }
    printf("bye\n");
    return 0;
}

