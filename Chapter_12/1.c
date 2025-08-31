#include <stdio.h>

/**
 * 不使用全局变量，重写程序清单12.4。(12.1.7节)i
 *
 *  global.c -- 使用外部变量 
 *  #include <stdio.h>
 *  int units = 0;
 *  void critic(void);
 *  int main(void)
 *  {
 *      extern int units;
 *      printf("How many pounds to a firkin of butter?\n");
 *      scanf("%d", &units);
 *      while (units != 56)
 *          critic();
 *      printf("You must have looked it up!\n");
 *      return 0;
 *  }
 *  void critic(void)
 *  {
 *      printf("No luck, my friend. Try again.\n");
 *      scanf("%d", &units);
 *  }
 */

void critic(int* p_units)
{
	printf("No luck, my friend. Try again.\n");
	scanf("%d", p_units);
}
int main()
{
	int units = 0;
	printf("How many pounds to a firkin of butter?\n");
	scanf("%d", &units);
	while (units != 56)
		critic(&units);
	printf("You must have looked it up!\n");

    return 0;
}
