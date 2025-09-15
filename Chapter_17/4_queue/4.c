// 和 queue.c 一起编译
#include <stdio.h>
#include <stdlib.h> // 提供 rand() 和 srand() 的原型
#include <time.h> // 提供 time() 的原型
#include "queue.h" // 更改 Item 的 typedef
#define MIN_PER_HR 60.0

/**
 * 重写mall.c（程序清单17.7），用两个队列模拟两个摊位。
 */

int newcustomer(double x); // 是否有新顾客到来？
Item customertime(long when); // 设置顾客参数

int main(void)
{
    Queue line1;
    Queue line2;
    Item temp; // 新的顾客数据
    int hours; // 模拟的小时数
    int cust_per_hour; // 每小时平均多少位顾客
    int wait_time1 = 0; // 摊位1从当前到空闲所需的时间
    int wait_time2 = 0; // 摊位2从当前到空闲所需的时间
    long cycle, cyclelimit; // 循环计数器、计数器的上限
    long turnaways = 0; // 因队列已满被拒的顾客数量
    long customers = 0; // 加入队列的顾客数量
    long served = 0; // 在模拟期间咨询过Sigmund的顾客数量
    long sum_line = 0; // 累计的队列总长
    double min_per_cust; // 顾客到来的平均时间
    long line_wait = 0; // 队列累计的等待时间

    srand((unsigned int)time(0)); // rand() 随机初始化
    puts("Enter the number of simulation hours:");
    scanf("%d", &hours);
    cyclelimit = MIN_PER_HR * hours;
    puts("Enter the average number of customers per hour:");
    scanf("%d", &cust_per_hour);
    min_per_cust = MIN_PER_HR / cust_per_hour;

    InitializeQueue(&line1);
    InitializeQueue(&line2);
    for (cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_cust))
        {
            if (QueueIsFull(&line1) && QueueIsFull(&line2))
            {

                puts("test.");
                turnaways++;
            }
            else
            {
                customers++;
                temp = customertime(cycle);
                if(line1.items > line2.items)
                    EnQueue(temp, &line2);
                else if(line1.items < line2.items)
                    EnQueue(temp, &line1);
                else 
                    (rand() % 2) ? EnQueue(temp, &line1) : EnQueue(temp, &line2);
            }
        }
        if (wait_time1 <= 0 && !QueueIsEmpty(&line1))
        {
            DeQueue(&temp, &line1);
            wait_time1 = temp.processtime;
            line_wait += cycle - temp.arrive;
            served++;
        }
        if (wait_time2 <= 0 && !QueueIsEmpty(&line2))
        {
            DeQueue(&temp, &line2);
            wait_time2 = temp.processtime;
            line_wait += cycle - temp.arrive;
            served++;
        }
        if (wait_time1 > 0)
            wait_time1--;
        if (wait_time2 > 0)
            wait_time2--;
        sum_line += QueueItemCount(&line1) + QueueItemCount(&line2);
    }
    if (customers > 0)
    {
        printf("customers accepted: %ld\n", customers);
        printf("customers served: %ld\n", served);
        printf("turnaways: %ld\n", turnaways);
        printf("average queue size: %.2f\n",
               (double) sum_line / cyclelimit);
        printf("average wait time: %.2f minutes\n",
               (double) line_wait / served);
    }
    else
        puts("No customers!");
    EmptyTheQueue(&line1);
    EmptyTheQueue(&line2);
    puts("Bye!");

    return 0;
}

int newcustomer(double x)
{
    if(x * rand() / RAND_MAX < 1)
        return 1;
    else 
        return 0;
}

Item customertime(long when)
{
    Item cust;
    cust.arrive = when;
    cust.processtime = rand() % 3 + 1;

    return cust;
}
