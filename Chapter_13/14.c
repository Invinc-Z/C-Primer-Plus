#include <stdio.h>
#include <stdlib.h>
#define ROW 20
#define COLUMN 31

/**
 * 数字图像，尤其是从宇宙飞船发回的数字图像，可能会包含一些失真。为编程练习12添加消除失真的函数。
 * 该函数把每个值与它上下左右相邻的值作比较，如果该值与其周围相邻值的差都大于1，
 * 则用所有相邻值的平均值（四舍五入为整数）代替该值。注意，与边界上的点相邻的点少于4个，所以做特殊处理。
 */

int compare(int x, int y, int img[][COLUMN]) {
    //x,y是特定左边
    int sum = 0, cnt = 0, org = 0, flag = 0;
    org = img[x][y];
    //依次判断上下左右是不是合法的
    if (x + 1 <= ROW - 1) {
        if (abs(org - img[x + 1][y]) > 1) flag = 1;
        else flag = 0;
        sum += img[x + 1][y];
        cnt += 1;
    }
    if (x - 1 > 0) {
        if (abs(org - img[x - 1][y]) > 1) flag = 1;
        else flag = 0;
        sum += img[x - 1][y];
        cnt++;
    }
    if (y + 1 < COLUMN - 1) {
        if (abs(org - img[x][y + 1]) > 1) flag = 1;
        else flag = 0;
        sum += img[x][y + 1];
        cnt++;
    }
    if (y - 1 > 0) {
        if (abs(org - img[x][y - 1]) > 1) flag = 1;
        else flag = 0;
        sum += img[x][y - 1];
        cnt++;
    }
    if (flag) return sum / cnt;
    else return org;
}

int main()
{
    int img[ROW][COLUMN] = { {0} };
    int denoise[ROW][COLUMN] = { {0} };
    FILE* fp;
    int i = 0, j = 0;
    char c;
    if ((fp = fopen("12.txt", "r")) == NULL) {
        printf("ERROR!\n");
        exit(EXIT_FAILURE);
    }
    while ((c = getc(fp)) != EOF) {
        if (c != ' ' && c != '\n') {
            switch (c) {
            case '0':img[i][j] = 0;
                     break;
            case '1':img[i][j] = 1;
                     break;
            case '2':img[i][j] = 2;
                     break;
            case '3':img[i][j] = 3;
                     break;
            case '4':img[i][j] = 4;
                     break;
            case '5':img[i][j] = 5;
                     break;
            case '6':img[i][j] = 6;
                     break;
            case '7':img[i][j] = 7;
                     break;
            case '8':img[i][j] = 8;
                     break;
            case '9':img[i][j] = 9;
                     break;
            default: img[i][j] = 0;
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
    printf("over!\n");
    printf("orignal image:\n");
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COLUMN - 1; j++) {
            printf("%d", img[i][j]);
        }
        printf("\n");
    }
    printf("after denoise:\n");
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COLUMN - 1; j++) {
            denoise[i][j] = compare(i, j, img);
            printf("%d", denoise[i][j]);
        }
        printf("\n");
    }

    return 0;
}
