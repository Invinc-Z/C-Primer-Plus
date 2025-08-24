#include <stdio.h>

/**
 * 编写一个程序，读取整数直到用户输入0。输入结束后，
 * 程序应报告用户输入的偶数（不包括0）个数、这些偶数的平均值、输入的奇数个数及其奇数的平均值。
 */

int main()
{
    int n;
    int count_odd = 0;
    int count_even = 0;
    int sum_odd = 0;
    int sum_even = 0;
    printf("Please enter some integers (0 to quit): ");
    while (scanf("%d", &n) && n != 0) {
        if (n % 2) {
            count_odd++;
            sum_odd += n;
        }
        else
        {
            count_even++;
            sum_even += n;
        }
    }
    if (count_odd)
        printf("The count of odd value is: %d，and sum of them is：%d，and average of them is：%.2f.\n", 
               count_odd, sum_odd, 1.0 * sum_odd / count_odd);
    else
        printf("The count of odd value is: 0.\n");
    if (count_even)
        printf("The count of even value is: %d，and sum of them is: %d，and average of them is: %.2f.\n",
               count_even, sum_even, 1.0 * sum_even / count_even);
    else
        printf("The count of even value is: 0.\n");
    return 0;
}

