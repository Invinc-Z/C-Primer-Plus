#include <stdio.h>

/**
 * 使用递归函数重写编程练习8。
 */

double recursive_power(double base, int exponent);

int main()
{
    double base = 0.0;
    int exponent = -3;
    double result = recursive_power(base, exponent);
    printf("%.2f raised to the power of %d is %.5f.\n", base, exponent, result);
    return 0;
}

double recursive_power(double base, int exponent)
{
    if(base == 0){
        return 0.0;
    }
    if (exponent == 0) {
        return 1.0; // Base case: any number raised to the power of 0 is 1
    }
    if (exponent < 0) {
        return 1.0 / recursive_power(base, -exponent); // Handle negative exponents
    }
    return base * recursive_power(base, exponent - 1); // Recursive case
}


