#include <stdio.h>

/**
 * 编写一个程序，在遇到EOF之前，把输入作为字符流读取。程序要打印每个输入的字符及其相应的ASCII十进制值。
 * 注意，在ASCII序列中，空格字符前面的字符都是非打印字符，要特殊处理这些字符。
 * 如果非打印字符是换行符或制表符，则分别打印\n或\t。否则，使用控制字符表示法。
 * 例如，ASCII的1是Ctrl+A，可显示为^A。注意，A的ASCII值是Ctrl+A的值加上64。其他非打印字符也有类似的关系。
 * 除每次遇到换行符打印新的一行之外，每行打印10对值。（注意：不同的操作系统其控制字符可能不同。）
 */

// 在终端中，EOF通常由组合键 Ctrl+D 触发：
// 第一次按 Ctrl+D：向内核发送缓冲区的输入（如果缓冲区为空，则发送EOF）。
// 第二次按 Ctrl+D（缓冲区为空时）：直接触发EOF信号。

int main()
{
    char ch;
    int count = 0;
    while ((ch = getchar()) != EOF) {
        if(ch == '\n')
        {
            count = 0;
            printf("[\\n %d]\t", ch);
        }
        else if(ch == '\t')
        {
            printf("[\\t %d]\t", ch);
            count++;
        }
        else if(ch > 0 && ch <= 31)
        {
            printf("[^%c %d]\t",ch + 64, ch);
            count++;
        }
        else
        {
            printf("[%c %d]\t", ch, ch);
            count++;
        }
        if(count % 10 == 0)
            printf("\n");
    }
    return 0;
}
