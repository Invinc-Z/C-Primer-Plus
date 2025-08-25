#include <stdio.h>

/**
 * 设计一个函数chline(ch, i, j)，打印指定的字符j行i列。在一个简单的驱动程序中测试该函数。
 */

void chline(char ch, int i, int j)
{
    if (i < 1 || j < 1) {
        printf("Invalid input!\n");
        return;
    }
    for (int k = 0; k < j; k++) {
        for (int l = 0; l < i; l++) {
            putchar(ch);
        }
        putchar('\n');
    }
}

int main()
{
    char ch = 'Z';
	int i = 4, j = 6;
    chline(ch, i, j);
    return 0;
}
