#include <stdio.h>
#define CUPS_PER_PINT 2
#define OUNCES_PER_CUP 8
#define SOUPSPOONS_PER_OUNCE 2
#define TEASPOONS_PER_SOUPSPOON 3
/*
 * 在美国的体积测量系统中，1品脱等于2杯，1杯等于8盎司，1盎司等于2大汤勺，1大汤勺等于3茶勺。
 * 编写一个程序，提示用户输入杯数，并以品脱、盎司、汤勺、茶勺为单位显示等价容量。
 * 思考对于该程序，为何使用浮点类型比整数类型更合适？
 *
 * 品脱 pint
 * 杯 cup
 * 盎司 ounce
 * 汤勺 soup spoon
 * 茶勺 tea spoon
*/ 

int main()
{
    float cups;
    printf("Please enter the number of cups: ");
    scanf("%f", &cups);
    printf("You enter %.2f cups, which converts to %.2f pints, or %.2f ounces, or %.2f soup spoons, or %.2f tea spoons.\n",
           cups, cups / CUPS_PER_PINT, cups * OUNCES_PER_CUP, cups * OUNCES_PER_CUP * SOUPSPOONS_PER_OUNCE, 
           cups * OUNCES_PER_CUP * SOUPSPOONS_PER_OUNCE * TEASPOONS_PER_SOUPSPOON);
    return 0;
}

