#include <stdio.h>

/**
 * 考虑下面两个无限序列：
 * 1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ...
 * 1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 + ...
 * 编写一个程序计算这两个无限序列的总和，直到到达某次数。
 * 提示：奇数个-1 相乘得-1，偶数个-1相乘得1。让用户交互地输入指定的次数，当用户输入0或负值时结束输入。
 * 查看运行100项、1000项、10000项后的总和，是否发现每个序列都收敛于某值？
 *
 * 上面的序列不收敛，下面的序列收敛于0.69
 */

int main()
{
    int count = 0;
    printf("Please enter the count (<=0 to quit): ");
    while (scanf("%d", &count) == 1 && count > 0)
    {
        double sum1 = 0;
        double sum2 = 0;
        int j = -1; // 用于控制符号
        for (int i = 1; i <= count; i++)
        {
            j *= -1;
            sum1 += 1.0 / i;
            sum2 += j * 1.0 / i;
        }
        printf("1 + 1/2 + 1/3 + ... + 1/%d = %.2f\n", count, sum1);
        printf("1 - 1/2 + 1/3 - 1/4 + ... + 1/%d = %.2f\n", count, sum2);
        printf("Please enter the count (<=0 to quit): ");
    }
    printf("Done\n");
    return 0;
}

