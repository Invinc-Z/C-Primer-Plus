#include <stdio.h>
#include <string.h>
#define CSIZE 4
#define NAME_LEN 32
#define SCORE_NUM 3

/**
 * 编写一个程序满足下面的要求。
 * a.外部定义一个有两个成员的结构模板name：一个字符串储存名，一个字符串储存姓。
 * b.外部定义一个有3个成员的结构模板student：一个name类型的结构，一个grade数组储存3个浮点型分数，一个变量储存3个分数平均数。
 * c.在main()函数中声明一个内含CSIZE（CSIZE = 4）个student类型结构的数组，并初始化这些结构的名字部分。用函数执行d、e、f和g中描述的任务。
 * d.以交互的方式获取每个学生的成绩，提示用户输入学生的姓名和分数。把分数储存到grade数组相应的结构中。可以在main()函数或其他函数中用循环来完成。
 * e.计算每个结构的平均分，并把计算后的值赋给合适的成员。
 * f.打印每个结构的信息。
 * g.打印班级的平均分，即所有结构的数值成员的平均值。
 */

typedef struct name {
    char first[NAME_LEN];
    char last[NAME_LEN];
} Name;
typedef struct student {
    Name full_name;
    float grade[SCORE_NUM];
    float average;
} Student;

char* s_gets(char* str, int n);
void get_student_scores(Student* students, int n);
void calculate_average(Student* students, int n);
void print_student_info(const Student* students, int n);
void print_class_average(const Student* students, int n);

int main()
{
    Student students[CSIZE] = {0}; // 初始化学生数组
    get_student_scores(students, CSIZE);
    calculate_average(students, CSIZE);
    print_student_info(students, CSIZE);
    print_class_average(students, CSIZE);

    return 0;
}

char* s_gets(char* str, int n)
{
    char* ret_val;
    char* find;
    ret_val = fgets(str, n, stdin);
    if(ret_val)
    {
        find = strchr(str, '\n');
        if(find) *find = '\0';
        else
        {
            while(getchar() != '\n')
                continue;
        }
    }
    return ret_val;
}

void get_student_scores(Student* students, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("Please enter student %d\' first name: ", i + 1);
        s_gets(students[i].full_name.first, NAME_LEN);
        printf("Please enter student %d\' last name: ", i + 1);
        s_gets(students[i].full_name.last, NAME_LEN);
        for(int j = 0; j < SCORE_NUM; j++)
        {
            printf("Please enter student %d\' score %d: ", i + 1, j + 1);
            while(scanf("%f", &students[i].grade[j]) != 1)
            {
                while(getchar() != '\n')
                    continue;
                printf("Please input a float-pointing value: ");
                continue;
            }
        }
        while(getchar() != '\n')
            continue;
    }
}
void calculate_average(Student* students, int n)
{
    for(int i = 0; i < n; i++)
    {
        float sum = 0;
        for(int j = 0; j < SCORE_NUM; j++)
            sum += students[i].grade[j];
        students[i].average = sum / SCORE_NUM;
    }
}
void print_student_info(const Student* students, int n)
{
    printf("All students information are as follows: \n");
    printf("-------------------------------------------------------------------------\n");
    printf("Student Name \t Score#1 \t Score#2 \t Score#3 \t Average\n");
    printf("-------------------------------------------------------------------------\n");
    for(int i = 0; i < n; i++)
    {
        printf("%s %s \t %-6.2f \t %-6.2f \t %-6.2f \t %-6.2f\n",
               students[i].full_name.first, students[i].full_name.last, 
               students[i].grade[0], students[i].grade[1], students[i].grade[2], students[i].average);
    }
    printf("-------------------------------------------------------------------------\n");
}
void print_class_average(const Student* students, int n)
{
    float sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += students[i].average;
    }
    printf("The class average score is %.2f\n", sum / n);
}
