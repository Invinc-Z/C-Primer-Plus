#include <stdio.h>
#define GRAMS_PER_MOLECULE 3.0E-23
#define GRAMS_PER_QUART 950

/**
 * 1个水分子的质量约为3.0×10^{-23}克。1夸脱水大约是950克。
 * 编写一个程序，提示用户输入水的夸脱数，并显示水分子的数量。
 */

int main()
{
    float quarts;
    printf("Please enter the number of quarts of water: ");
    scanf("%f", &quarts);
    printf("The number of water molecule is %E.\n", quarts * GRAMS_PER_QUART / GRAMS_PER_MOLECULE);
    return 0;
}

