#include <stdio.h>

/**
 * 使用if else语句编写一个程序读取输入，读到#停止。
 * 用感叹号替换句号，用两个感叹号替换原来的感叹号，最后报告进行了多少次替换。
 */

int main()
{
    char arr[4096] = {0};
    int count = 0;
    char ch;
    int i = 0;
    printf("Please enter some characters (\'#\' to stop): ");
    while ((ch = getchar()) != '#') {
        if (ch == '.') {
            arr[i] = '!';
            count++;
        }
        else if (ch == '!')
        {
            arr[i] = '!';
            i++;
            arr[i] = '!';
            count++;
        }
        else
            arr[i] = ch;
        i++;
    }
    printf("Reversed data:\n");
    printf("%s\n", arr);
    printf("The count of replacement is %d.\n", count);
    return 0;
}

