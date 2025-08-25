#include <stdio.h>

/**
 * 为了让程序清单9.8中的to_binary()函数更通用，编写一个to_base_n()函数接受两个在2～10范围内的参数，
 * 然后以第2个参数中指定的进制打印第1个参数的数值。
 * 例如，to_base_n(129， 8)显示的结果为201，也就是129的八进制数。在一个完整的程序中测试该函数。
 */

int to_base_n(int n, int digits)
{
    int result = 0;
    int multiplier = 1;
    while (n > 0) {
        int digit = n % digits; // Get the last digit in base 'digits'
        result += digit * multiplier; // Add it to the result
        multiplier *= 10; // Move to the next place value
        n /= digits; // Remove the last digit
    }
	return result;
}

int main()
{
    int num = 129;
    int base = 8;
    printf("to_base_n(%d, %d) is %d\n", num, base, to_base_n(num, base));
    return 0;
}
