#include <stdio.h>

/**
 * 编写一个程序读取输入，读到#字符停止。程序要打印每个输入的字符以及对应的ASCII码（十进制）。
 * 一行打印8个字符。建议:使用字符计数和求模运算符（%）在每8个循环周期时打印一个换行符。
 */

int main()
{
    char ch;
    int count = 0;
    printf("Please enter some characters (end with \'#\'): ");
    while (scanf("%c", &ch) == 1 && ch != '#'){
        if (ch == '\n') {
            count = 0;
            continue; // 跳过换行符
        }
        printf("'%c'=%3d  ", ch, ch); // 打印字符和ASCII码
        count++;
        // 每8个字符换行
        if (count % 8 == 0) printf("\n");
    }
    // 最后一行不足8个字符时换行
    if (count % 8 != 0) printf("\n");
    return 0;
}

