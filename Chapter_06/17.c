#include <stdio.h>

/**
 * Chuckie Lucky赢得了100万美元（税后），他把奖金存入年利率8%的账户。
 * 在每年的最后一天， Chuckie取出10万美元。编写一个程序，计算多少年后Chuckie会取完账户的钱？
 */

int main()
{
    double Chuckie = 1000000; // 初始值
    const double rate = 0.08; // 利率
    int year = 0; // 计数器
    while (Chuckie > 0)
    {
        Chuckie -= 100000; // 每年减少 10 万
        Chuckie *= (1 + rate); // 每年增加 8%
        year++;
        printf("Chuckie's money after %d years: %.2f\n", year, Chuckie);
    }
    printf("It takes %d years for Chuckie's money to become negative.\n", year);
    return 0;
}

