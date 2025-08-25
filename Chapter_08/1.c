#include <stdio.h>

/**
 * 设计一个程序，统计在读到文件结尾之前读取的字符数。
 */

// 在终端中，EOF通常由组合键 Ctrl+D 触发：
// 第一次按 Ctrl+D：向内核发送缓冲区的输入（如果缓冲区为空，则发送EOF）。
// 第二次按 Ctrl+D（缓冲区为空时）：直接触发EOF信号。

int main()
{
    int count = 0;
    while (getchar() != EOF) {
        count++;
    }
    printf("\nThe count of characters is %d.\n", count);
    return 0;
}

