#include <stdio.h>
#include <string.h>

/**
 * 编写一个程序，先提示用户输入名，然后提示用户输入姓。在一行打印用户输入的名和姓，下一行分别打印名和姓的字母数。
 * 字母数要与相应名和姓的结尾对齐，如下所示：
 * Melissa Honeybee
 *       7        8
 * 接下来，再打印相同的信息，但是字母个数与相应名和姓的开头对齐，如下所示：
 * Melissa Honeybee
 * 7       8
 */

int main()
{
    char first_name[32] = {0};
    char last_name[32] = {0};
    printf("Please enter your first name: ");
    scanf("%s", first_name);
    printf("Please enter your last name: ");
    scanf("%s", last_name);

    int first_name_width = strlen(first_name);
    int last_name_width = strlen(last_name);
    printf("%s %s\n", first_name, last_name);
    printf("%*d %*d\n", first_name_width, first_name_width, last_name_width, last_name_width);
    printf("%s %s\n", first_name, last_name);
    printf("%-*d %-*d\n", first_name_width, first_name_width, last_name_width, last_name_width);

    return 0;
}

