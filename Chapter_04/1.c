#include <stdio.h>

/**
 * 编写一个程序，提示用户输入名和姓，然后以“名,姓”的格式打印出来。
 */ 

int main()
{
    char first_name[32] = {0};
    char last_name[32] = {0};
    printf("Please enter your first_name: ");
    scanf("%s", first_name);
    printf("Pleasr enter your last name: ");
    scanf("%s", last_name);
    printf("Your full name is: %s, %s\n", last_name, first_name);
    return 0;
}

