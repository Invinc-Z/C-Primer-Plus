#include <stdio.h>
#define CMS_PER_M 100

/**
 * 编写一个程序，提示用户输入身高（单位：英寸）和姓名，然后以下面的格式显示用户刚输入的信息：\
 * Dabney, you are 6.208 feet tall
 * 使用float类型，并用/作为除号。如果你愿意，可以要求用户以厘米为单位输入身高，并以米为单位显示出来。
 */

int main()
{
    char name[32] = {0};
    printf("Please enter your name: ");
    scanf("%s", name);
    float height;
    printf("Please enter your height(.cm): ");
    scanf("%f", &height);
    printf("%s, your height is %.2f m.\n", name, height / CMS_PER_M);
    return 0;
}

