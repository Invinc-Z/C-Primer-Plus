#include <stdio.h>

/**
 * 编写一个程序，生成以下输出：
 * For he's a jolly good fellows!
 * For he's a jolly good fellows!
 * For he's a jolly good fellows!
 * Which nobody can deny!
 * 除了main()函数以外，该程序还要调用两个自定义函数：
 * 一个名为jolly(),用于打印前3条消息，调用一次打印一条；
 * 另一个函数名为deny()，打印最后一条消息。
 */

// 函数前置声明
void jolly();
void deny();

int main()
{
    // 调用函数
    jolly();
    jolly();
    jolly();
    deny();
    return 0;
}

// 函数定义
void jolly()
{
    printf("For he's a jolly good fellows!\n");
}

void deny()
{
    printf("Which nobody can deny!\n");
}
