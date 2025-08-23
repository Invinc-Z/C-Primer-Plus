#include <stdio.h>

/**
 * Rabnud博士加入了一个社交圈。起初他有5个朋友。他注意到他的朋友数量以下面的方式增长。
 * 第1周少了1个朋友，剩下的朋友数量翻倍；第2周少了2个朋友，剩下的朋友数量翻倍。
 * 一般而言，第N周少了N个朋友，剩下的朋友数量翻倍。
 * 编写一个程序，计算并显示Rabnud博士每周的朋友数量。
 * 该程序一直运行，直到超过邓巴数（Dunbar’s number）。
 * 邓巴数是粗略估算一个人在社交圈中有稳定关系的成员的最大值，该值大约是150。
 */

int main()
{
    int friends = 5; // 初始值
    const int rate = 2; // 利率
    int week = 0; // 计数器
    while (friends <= 150)
    {
        friends -= 1; // 每周减少1个朋友
        friends *= rate; // 每周增加2倍
        week++;
        printf("friend's value after %d weeks: %d\n", week, friends);
    }
    printf("It takes %d weeks for friend's value to become Dunbar's number(about 150).\n", week);
    return 0;
}

