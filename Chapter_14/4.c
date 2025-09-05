#include <stdio.h>
#include <string.h>
#define SIZE 20

/**
 * 编写一个程序，创建一个有两个成员的结构模板：
 * a.第1个成员是社会保险号，第2个成员是一个有3个成员的结构，第1个成员代表名，第2个成员代表中间名，第3个成员表示姓。
 * 创建并初始化一个内含5个该类型结构的数组。该程序以下面的格式打印数据：
 * Dribble, Flossie M.–– 302039823
 * 如果有中间名，只打印它的第1个字母，后面加一个点（.）；如果没有中间名，则不用打印点。
 * 编写一个程序进行打印，把结构数组传递给这个函数。
 *
 * b.修改a部分，传递结构的值而不是结构的地址。
 */

struct name {
    char first[SIZE];
    char middle[SIZE];
    char last[SIZE];
};
typedef struct person {
    long id;
    struct name full_name;
} Person;

char* s_gets(char* str, int n);
void get_info(Person* people, int n);
void show_info(const Person* people, int n);
void show_info2(const Person p);

int main()
{
    Person people[5];
    get_info(people, sizeof(people)/sizeof(people[0]));
    printf("Info as follows: \n");
    printf("Using struct address to print: \n");
    show_info(people, sizeof(people)/sizeof(people[0]));
    printf("Using struct value to print: \n");
    for (size_t i = 0; i < sizeof(people)/sizeof(people[0]); i++) {
        show_info2(people[i]);
    }

    return 0;
}

void get_info(Person* people, int n)
{
    for (int i = 0; i < n; i++) {
        printf("Enter ID for person %d: ", i + 1);
        while(scanf("%ld", &people[i].id) != 1)
        {
            printf("Please enter an integer ID: ");
            continue;
        }
        while(getchar() != '\n')
            continue;
        printf("Enter first name: ");
        s_gets(people[i].full_name.first, SIZE);
        printf("Enter middle name: ");
        s_gets(people[i].full_name.middle, SIZE);
        printf("Enter last name: ");
        s_gets(people[i].full_name.last, SIZE);
    }
}

void show_info(const Person* people, int n)
{
    for (int i = 0; i < n; i++) {
        char middle_initial = people[i].full_name.middle[0];
        if (middle_initial == '\0') {
            printf("%s, %s -- %ld\n", people[i].full_name.last, people[i].full_name.first, people[i].id);
        }
        else {
            printf("%s, %s %c. -- %ld\n", people[i].full_name.last, people[i].full_name.first, middle_initial, people[i].id);
        }
    }
}

void show_info2(const Person p)
{
    char middle_initial = p.full_name.middle[0];
    if (middle_initial == '\0') {
        printf("%s, %s -- %ld\n", p.full_name.last, p.full_name.first, p.id);
    }
    else {
        printf("%s, %s %c. -- %ld\n", p.full_name.last, p.full_name.first, middle_initial, p.id);
    }
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
