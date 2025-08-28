#include <stdio.h>

/**
 * 编写一个程序，提示用户输入3组数，每组数包含5个double类型的数（假设用户都正确地响应，不会输入非数值数据）。
 * 该程序应完成下列任务。
 * a.把用户输入的数据储存在3×5的数组中
 * b.计算每组（5个）数据的平均值
 * c.计算所有数据的平均值
 * d.找出这15个数据中的最大值
 * e.打印结果
 * 每个任务都要用单独的函数来完成。
 * 完成任务b，要编写一个计算并返回一维数组平均值的函数，利用循环调用该函数3次。
 * 对于处理其他任务的函数，应该把整个数组作为参数，完成任务c和d的函数应把结果返回主调函数。
 *
 * 以变长数组作为函数形参，完成编程练习13。
 */

void read_data(int rows, int cols, double arr[rows][cols]);
void show_data(int rows, int cols, double arr[rows][cols]);
double get_average_block(int cols, double arr[cols]);
double get_average(int rows, int cols, double arr[rows][cols]);
double get_max_in_array(int rows, int cols, double arr[rows][cols]);

int main()
{
    double arr[3][5] = { {0.0} }; // 初始化为0
    read_data(3, 5, arr);
    printf("您输入的数组为：\n");
    show_data(3, 5, arr);
    for (size_t i = 0; i < 3; i++)
    {
        printf("第%zu行的平均值为：%.2f\n", i + 1, get_average_block(5, arr[i]));
    }
    printf("所有数据的平均值为：%.2f\n", get_average(3, 5, arr));
    printf("所有数据的最大值为：%.2f\n", get_max_in_array(3, 5, arr));
    return 0;
}
void read_data(int rows, int cols, double arr[rows][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("请输入第%d行第%d列的数：", i + 1, j + 1);
            scanf("%lf", &arr[i][j]);
        }
    }
}
void show_data(int rows, int cols, double arr[rows][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            printf("%.2f\t", arr[i][j]);
        puts("");
    }
}
double get_average_block(int cols, double arr[cols])
{
    double total = 0.0;
    for (int i = 0; i < cols; i++)
        total += arr[i];
    return total / cols;
}
double get_average(int rows, int cols, double arr[rows][cols])
{
    double total = 0.0;
    for (int i = 0; i < rows; i++)
        total += get_average_block(cols, arr[i]);
    return total / rows;
}
double get_max_in_array(int rows, int cols, double arr[rows][cols])
{
    double max = arr[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] > max)
                max = arr[i][j];
        }
    }
    return max;
}
