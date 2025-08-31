#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "diceroll.h" 

/**
 * 编写一个程序，按照程序清单12.13 (12.3节)输出示例后面讨论的内容，修改该程序。
 * 使其输出类似：
 * Enter the number of sets; enter q to stop : 18
 * How many sides and how many dice? 6 3
 * Here are 18 sets of 3 6-sided throws.
 * 12 10 6 9 8 14 8 15 9 14 12 17 11 7 10 13 8 14
 * How many sets? Enter q to stop: q
 */

void print_points(int sets_num, int sides, int dice);

int main()
{
    srand(time(NULL));
    int sets_num;
    int sides;
    int dice;
    printf("Enter the number of sets; enter q to stop: ");
    while(scanf("%d", &sets_num) == 1)
    {
        while(1)
        {
            printf("How many sides and how many dice? ");
            if(scanf("%d %d", &sides, &dice) == 2)
            {
                printf("Here are %d sets of %d %d-sided throws.\n", sets_num, dice, sides);
                print_points(sets_num, sides, dice);
                break;
            }
        }
        printf("How many sets? Enter q to stop: ");
    }

    return 0;
}

void print_points(int sets_num, int sides, int dice)
{
    int i = 0;
    int points;
    while(i < sets_num)
    {
        points = roll_n_dice(dice, sides);
        printf("%d ", points);
        i++;
    }
    puts("");
}
