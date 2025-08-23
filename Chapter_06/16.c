#include <stdio.h>

/**
 * Daphne以10%的单利息投资了100美元（也就是说，每年投资获利相当于原始投资的10%）。
 * Deirdre以5%的复合利息投资了100美元（也就是说，利息是当前余额的5%，包含之前的利息）。
 * 编写一个程序，计算需要多少年Deirdre的投资额才会超过Daphne，并显示那时两人的投资额。
 */

int main()
{
    double Daphne = 100.0; // 初始值
    double Deirdre = 100.0; // 初始值
    int year = 0; // 计数器
    while (Daphne >= Deirdre)
    {
        Daphne += 10.0; // Daphne 每年增加 10
        Deirdre *= 1.05; // Deirdre 每年增加 5%
        year++;
    }
    printf("Daphne's money: $%.2f.\n", Daphne);
    printf("Deirdre's money: $%.2f.\n", Deirdre);
    printf("It takes %d years for Deirdre's money to exceed Daphne's money.\n", year);
    return 0;
}

