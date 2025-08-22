#include <stdio.h>

/*
 * 编写一个程序，要求提示输入一个ASCII码值（如66），然后打印输入的字符。
*/

int main()
{
    int ch = 0;
    printf("Please enter an ASCII code value: ");
    scanf("%d", &ch);
    printf("ASCII code %d is \'%c\'.\n", ch, ch);
    return 0;
}

