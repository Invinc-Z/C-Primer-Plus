#include <stdio.h>

/**
 * 编写一个程序，提示用户输入大写字母。使用嵌套循环以下面金字塔型的格式打印字母：
 * A
 * ABA
 * ABCBA
 * ABCDCBA
 * ABCDEDCBA
 * 打印这样的图形，要根据用户输入的字母来决定。例如，上面的图形是在用户输入E后的打印结果。
 * 提示：用外层循环处理行，每行使用3个内层循环，分别处理空格、以升序打印字母、以降序打印字母。
 */

int main()
{
    char ch;
    printf("Please enter a captial letter (type \'q\' to exit): ");
    while(scanf(" %c", &ch) == 1 && ch != 'q')
    {
        for(int i = 0; i < ch - 'A' + 1; i++)
        {
            int j = 0;
            for( ; j < i + 1; j++)
                printf("%c", j + 'A');
            for(char k = j + 'A' - 2; k >= 'A'; k--)
                printf("%c", k);
            printf("\n");
        }
        printf("Please enter a captial letter (type \'q\' to exit): ");
    }
    return 0;
}

