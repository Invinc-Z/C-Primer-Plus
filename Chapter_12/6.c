#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000
#define NUM 10

/**
 * 编写一个程序，生成1000个1～10范围内的随机数。不用保存或打印这些数字，仅打印每个数出现的次数。
 * 用 10 个不同的种子值运行，生成的数字出现的次数是否相同？
 * 可以使用本章自定义的函数或ANSI C的rand()和srand()函数，它们的格式相同。
 * 这是一个测试特定随机数生成器随机性的方法。
 */

int main()
{
    srand((unsigned int)time(NULL)); // 使用当前时间作为随机数种子
    int arr[SIZE] = { 0 }; // 初始化数组为0
    for (int i = 0; i < SIZE; i++)
        arr[i] = rand() % NUM + 1; // 生成1到10之间的随机数
    int arr2[10] = { 0 }; // 初始化统计数组为0
    for (int i = 0; i < SIZE; i++)
        arr2[arr[i] - 1]++; // 统计每个数字出现的次数
    for (int i = 0; i < NUM; i++)
        printf("%d occured: %d\n", i + 1, arr2[i]); // 打印数字
    return 0;
}

