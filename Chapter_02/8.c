#include <stdio.h>

/**
 * 在C语言中，函数可以调用另一个函数。
 * 编写一个程序，调用一个名为one_three()的函数。该函数在一行打印单词"one"，再调用第2个函数two()，然后在另一行打印单词"three"。
 * two()函数在一行显示单词"two"。main()函数在调用one_three()函数前要打印短语"Starting now:"，并在调用完毕后显示短语"done!"。
 * 应此，该程序的输出应如下所示：
 * starting now:
 * one
 * two
 * three
 * done!
 */

// 函数前置声明
void one_three();
void two();
int main()
{
    printf("Starting now:\n");
    one_three();
    printf("done!\n");
    return 0;
}

// 函数定义
void one_three()
{
    printf("one\n");
    two();
    printf("three\n");
}
void two()
{
    printf("two\n");
}

