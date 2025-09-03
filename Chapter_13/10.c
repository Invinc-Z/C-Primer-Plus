#include <stdio.h>
#define SIZE 128

/**
 * 编写一个程序打开一个文本文件，通过交互方式获得文件名。
 * 通过一个循环，提示用户输入一个文件位置。
 * 然后该程序打印从该位置开始到下一个换行符之前的内容。
 * 用户输入负数或非数值字符可以结束输入循环。
 */


int main()
{
    FILE* fp;
    char filename[SIZE] = { 0 };
    int position = 1;
    char ch;
    printf("Enter the name of the file to open: ");
    scanf("%s", filename);

    if ((fp = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "Error opening file %s.\n", filename);
        return -1;
    }
    fseek(fp, 0, SEEK_END);
    int len = ftell(fp);
    printf("len = %d\n", len);
    rewind(fp);
    printf("Please enter the position (negative value or no-number to quit): ");
    while (scanf("%d", &position) && position > -1 && position < len)
    {
        fseek(fp, position, SEEK_SET);
        printf("the content are: ");
        while ((ch = getc(fp)) != '\n') putchar(ch);
        puts("");
        printf("please enter the position (negative value or no-number to quit): ");
        fflush(stdin);
    }
    fclose(fp);
    printf("bye\n");

    return 0;
}
