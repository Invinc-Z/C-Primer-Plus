#include <stdio.h>

/**
 * 编写一个程序，只接受正整数输入，然后显示所有小于或等于该数的素数。
 */

// 素数（质数）：是指在大于1的自然数中，除了1和它本身之外不再有其他因数的数。
// 合数：是指在大于1的自然数中，除了1和它本身之外还有其他因数的数。

int is_prime(int n);

int main()
{
    int n;
    printf("Please enter a positive integer (<=0 to quit): ");
    while(scanf("%d", &n) == 1 && n > 0)
    {
        printf("The prime that <= %d : ", n);
        for(int i = 1; i <= n; i++)
        {
            if(is_prime(i) == 1)
                printf("%d ", i);
        }
        printf("\n");
        printf("Please enter a positive integer (<=0 to quit): ");
    }
    printf("bye\n");
    return 0;
}

int is_prime(int n)
{
    if(n <= 1) return 0;
    if(n == 2) return 1;
    for(int i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
            return 0;
    }
    return 1;
}
