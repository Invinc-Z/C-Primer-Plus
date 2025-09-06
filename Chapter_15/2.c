#include <stdio.h>
#include <string.h>
#define SIZE 33

/**
 * 编写一个程序，通过命令行参数读取两个二进制字符串，
 * 对这两个二进制数使用～运算符、&运算符、|运算符和^运算符，并以二进制字符串形式打印结果
 * （如果无法使用命令行环境，可以通过交互式让程序读取字符串）。
 */

int str2int(const char* pbin);
char* int2str(int value, char* p);

int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        printf("args error!\n");
        return -1;
    }

    char str1[SIZE] = {0};
    char str2[SIZE] = {0};
    char str3[SIZE] = {0};

    memcpy(str1, argv[1], SIZE);
    memcpy(str2, argv[2], SIZE);
    int n1 = str2int(str1);
    int n2 = str2int(str2);

    puts("------------------------------------");
    printf("\t%s\n", str1);
    printf("~ %s = %s\n", str1, int2str(~n1, str3));

    puts("------------------------------------");
    printf("\t%s\n", str1);
    printf("&\t%s\n", str2);
    printf("\t%s\n", int2str(n1 & n2, str3));

    puts("------------------------------------");
    printf("\t%s\n", str1);
    printf("|\t%s\n", str2);
    printf("\t%s\n", int2str(n1 | n2, str3));

    puts("------------------------------------");
    printf("\t%s\n", str1);
    printf("^\t%s\n", str2);
    printf("\t%s\n", int2str(n1 ^ n2, str3));
    puts("------------------------------------");

    return 0;
}

int str2int(const char* pbin)
{
    int ret = 0;
    int base = 1;
    char* p = (char*)pbin;
    while(*p)
        p++;
    --p;
    while(p - pbin >= 0)
    {
        ret += (*p - 48) * base;
        base *= 2;
        p--;
    }
    return ret;
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
