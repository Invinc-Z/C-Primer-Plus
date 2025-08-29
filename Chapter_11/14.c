#include <stdio.h>
#include <stdlib.h>

/**
 * 编写一个通过命令行运行的程序计算幂。第1个命令行参数是double类型的数，作为幂的底数，第2个参数是整数，作为幂的指数。
 */

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		printf("No command line arguments provided.\n");
		return -1;
	}
	double d1 = atof(argv[1]);
	int i1 = atoi(argv[2]);
	double sum = 1.0;
	for (int i = 0; i < i1; i++)
	{
		sum *= d1; // 每次乘以d1
	}
	printf("The result of multiplying %.2f by itself %d times is: %.2f\n", d1, i1, sum);
}
