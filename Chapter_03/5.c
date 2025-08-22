#include <stdio.h>
#define SECONDS_PER_YEAR 3.156E7
/*
 * 一年大约有3.156×10^{7}秒。编写一个程序，提示用户输入年龄，然后显示该年龄对应的秒数。
*/

int main()
{
    int age;
    printf("Please enter your age: ");
    scanf("%d", &age);
    printf("Your age is %d years, which converts to %E seconds\n", age, age * SECONDS_PER_YEAR);
    return 0;
}

