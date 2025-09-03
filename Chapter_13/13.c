#include <stdio.h>
#include <stdlib.h>

/**
 * 用变长数组（VLA）代替标准数组，完成编程练习12。
 */

int main()
{
    int ROW = 20;
    int COLUMN = 31;
    char num[ROW][COLUMN] ;
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
