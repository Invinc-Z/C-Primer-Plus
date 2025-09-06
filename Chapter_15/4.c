#include <stdio.h>

/**
 * 编写一个程序，接受两个int类型的参数：一个是值；一个是位的位置。
 * 如果指定位的位置为1，该函数返回1；否则返回0。在一个程序中测试该函数。
 */

int check_bit(int n, int index);
char* int2str(int value, char* p);

int main()
{
    char arr[33] = {0};
    int n = 1218;
    int index = 2;
    printf("%d = %s (binary) is %d at index %d\n", n, int2str(n, arr), check_bit(n, index), index);

    return 0;
}

int check_bit(int n, int index)
{
    return (n >> index & 1);
}

char* int2str(int value, char* p) {
    // 处理特殊情况：值为0
    if (value == 0) {
        p[0] = '0';
        p[1] = '\0';
        return p;
    }

    int index = 0;
    unsigned int unsigned_value = (unsigned int)value; // 处理负数

    // 计算二进制位数
    int num_bits = sizeof(int) * 8;

    // 从最高位开始处理每一位
    int started = 0; // 标记是否已遇到第一个1（用于跳过前导零）
    for (int i = num_bits - 1; i >= 0; i--) {
        unsigned int bit = (unsigned_value >> i) & 1;

        // 跳过前导零
        if (bit == 1) started = 1;
        if (!started && bit == 0) continue;

        p[index++] = bit ? '1' : '0';
    }

    p[index] = '\0'; // 添加字符串结束符
    return p;
}
