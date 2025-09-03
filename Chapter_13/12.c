#include <stdio.h>
#include <stdlib.h>
#define ROW 20
#define COLUMN 31

/**
 * 创建一个文本文件，内含20行，每行30个整数。这些整数都在0～9之间，用空格分开。
 * 该文件是用数字表示一张图片，0～9表示逐渐增加的灰度。
 * 编写一个程序，把文件中的内容读入一个20×30的int数组中。
 * 一种把这些数字转换为图片的粗略方法是：该程序使用数组中的值初始化一个20×31的字符数组，用值0 对应空格字符，1 对应点字符，以此类推。
 * 数字越大表示字符所占的空间越大。例如，用#表示9。每行的最后一个字符（第31个）是空字符，这样该数组包含了20个字符串。
 * 最后，程序显示最终的图片（即，打印所有的字符串），并将结果储存在文本文件中。
 */

int main()
{
    char num[ROW][COLUMN] = { {0} };
    FILE* fp;
    int i = 0, j = 0;
    char c;
    if ((fp = fopen("12.txt", "r")) == NULL) {
        printf("Error!\n");
        exit(EXIT_FAILURE);
    }
    while ((c = getc(fp)) != EOF) {
        if (c != ' ' && c != '\n') {
            // printf("%c enter\n",c);
            switch (c) {
            case '0':num[i][j] = ' ';
                     break;
            case '1':num[i][j] = '.';
                     break;
            case '2':num[i][j] = '*';
                     break;
            case '3':num[i][j] = '/';
                     break;
            case '4':num[i][j] = '-';
                     break;
            case '5':num[i][j] = '!';
                     break;
            case '6':num[i][j] = '?';
                     break;
            case '7':num[i][j] = '=';
                     break;
            case '8':num[i][j] = '~';
                     break;
            case '9':num[i][j] = '#';
                     break;
            default: num[i][j] = ' ';
                     break;
            }
            j++;
            if (j == COLUMN - 1) {
                i++;
                j = 0;
            }
            if (i == ROW) break;
        }
    }
    fclose(fp);
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COLUMN; j++) {
            printf("%c", num[i][j]);
        }
        printf("\n");
    }

    return 0;
}
