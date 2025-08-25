#include <stdio.h>

/**
 * 修改程序清单8.8中(8.7.3节)的get_first()函数，让该函数返回读取的第1个非空白字符，并在一个简单的程序中测试。
 */

char get_first()
{
    char ch;
    scanf(" %c", &ch);
    while(getchar() != '\n') ;
    return ch;
}
int main()
{
    printf("Please enter something, we will show the first character (except space) you entered: \n");
    printf("The first character you entered is: %c\n", get_first());
    return 0;
}

