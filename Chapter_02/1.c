#include <stdio.h>

/*
 * 编写一个程序，调用一次printf()函数，把你的姓名打印在一行。
 * 再调用一次printf()函数，把你的姓名打印在两行。
 * 然后，再调用两次printf()函数，把你的姓名打印在一行。
 * 输入应如下所示（当然要把示例的内容换成你的姓名）：
 *
 * Gustav Mahler    <- 第1次打印的内容
 * Gustav           <- 第2次打印的内容
 * Mahler           <- 仍是第2次打印的内容
 * Gustav Mahler    <- 第3次和第4次打印的内容
 *
*/
int main()
{
    printf("Gustav Mahler\n");  // 第1次
    printf("Gustav\nMahler\n"); // 第2次
    printf("Gustav ");          // 第3次
    printf("Mahler\n");         // 第4次

    return 0;
}

