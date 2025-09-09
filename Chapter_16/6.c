#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM 40
#define NAME_LEN 40
#define SIZE 9

/**
 * 修改程序清单16.17，使用struct names元素（在程序清单16.17后面的讨论中定义过），而不是double类型的数组。
 * 使用较少的元素，并用选定的名字显式初始化数组。
 */

typedef struct names {
    char first[NAME_LEN];
    char last[NAME_LEN];
} full_name_t;

void show_staff(const full_name_t* p_staff, int len);
int mycomp(const void * p1, const void * p2);

int main(void)
{
    full_name_t staff[SIZE] = {
        {"Sanfeng", "Zhang"}, {"Cuishan", "Zhang"}, {"Wuji", "Zhang"},
        {"Zhiruo", "Zhou"}, {"Qinshu", "Song"}, {"Jue", "Mie"},
        {"Xiao", "Yang"}, {"Yixiao", "We"}, {"Li", "A"}
    };
    printf("Before sort, staff is: \n");
    show_staff(staff, SIZE);
    qsort(staff, SIZE, sizeof(full_name_t), mycomp);
    printf("After sort, staff is: \n");
    show_staff(staff, SIZE);

    return 0;
}

void show_staff(const full_name_t* p_staff, int len)
{
    for(int i = 0; i < len; i++)
        printf("%s %s\n", p_staff[i].last, p_staff[i].first);
    printf("\n");
}

/* 按从小到大的顺序排序 */
int mycomp(const void * p1, const void * p2)
{
    const full_name_t* ps1 = (const full_name_t*)p1;
    const full_name_t* ps2 = (const full_name_t*)p2;
    int res;
    res = strcmp(ps1->last, ps2->last);
    if(res != 0)
        return res;
    else
    {
        // 同姓，则比较名
        return strcmp(ps1->first, ps2->first);
    }
}
