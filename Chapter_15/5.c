#include <stdio.h>

/**
 * 编写一个函数，把一个 unsigned int 类型值中的所有位向左旋转指定数量的位。
 * 例如，rotate_l(x,4)把x中所有位向左移动4个位置，而且从最左端移出的位会重新出现在右端。
 * 也就是说，把高阶位移出的位放入低阶位。在一个程序中测试该函数。
 */

unsigned int rotate_l(unsigned int value, int n);
char* int2str(int value, char* p);

int main()
{
    char arr[33] = {0};
    unsigned int n = 0x19951218;
    int n_bits = 8;
    printf("unsigned int vlaue is %d\n", n);
    puts("origin binary string is:");
    printf("%s\n", int2str(n, arr));
    printf("rotate %d left to %d bit is:\n", n, n_bits);
    printf("%s\n", int2str(rotate_l(n, n_bits), arr));

    return 0;
}

unsigned int rotate_l(unsigned int value, int n)
{
    int bit_num = sizeof(unsigned int) * 8;
    // 找出前n位
    unsigned int n_bits = (value >> (bit_num - n)) & 0xFFFFFFFF;
    return value << n | n_bits;
}

char* int2str(int value, char* p) {
    // 处理特殊情况：值为0
    if (value == 0) {
        p[0] = '0';
        p[1] = '\0';
        return p;
    }

    int index = 0;

    // 计算二进制位数
    int num_bits = sizeof(int) * 8;

    // 从最高位开始处理每一位
    /* int started = 0; // 标记是否已遇到第一个1（用于跳过前导零） */
    for (int i = num_bits - 1; i >= 0; i--) {
        unsigned int bit = (value >> i) & 1;

        // 跳过前导零
        /* if (bit == 1) started = 1; */
        /* if (!started && bit == 0) continue; */

        p[index++] = bit ? '1' : '0';
    }

    p[index] = '\0'; // 添加字符串结束符
    return p;
}
