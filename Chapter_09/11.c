#include <stdio.h>

/**
 * 编写并测试Fibonacci()函数，该函数用循环代替递归计算斐波那契数。
 */

// 使用循环实现Fibonacci数列 0 1 1 2 3 5 8 13 ...
int fibonacci(int n)
{
    if (n <= 0) return 0;
    if (n == 1) return 1;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b; // Calculate the next Fibonacci number
        a = b; // Move to the next pair
        b = c;
    }
    return b; // Return the nth Fibonacci number
}

int main()
{
    int n;
    printf("Please enter an integer, we will give you the first n Fibonacci() item (not number to quit): ");
    while(scanf("%d", &n) == 1)
    {
        for(int i = 0; i <= n; i++)
        {
            printf("fibonacci(%d) is %d\n", i, fibonacci(i));
        }
        printf("\nPlease enter an integer, we will give you the first n Fibonacci() item (not number to quit): ");
    }
    printf("bye\n");
    return 0;
}


