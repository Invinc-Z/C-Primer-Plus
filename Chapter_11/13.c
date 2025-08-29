#include <stdio.h>

/**
 * 编写一个程序，反序显示命令行参数的单词。
 * 例如，命令行参数是see you later，该程序应打印later you see。
 */

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		printf("No command line arguments provided.\n");
		return -1;
	}
	printf("Command line arguments:\n");
	for (int i = 1; i < argc; i++)
	{
		printf("%s ", argv[i]);
	}
	printf("\n");
	printf("Reversed command arguments: \n");
	for (int i = argc - 1; i > 0; i--)
	{
		printf("%s ", argv[i]);
	}
	printf("\n");

    return 0;
}
