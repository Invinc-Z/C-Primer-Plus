#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100

/**
 * 修改程序清单 14.2 中 (14.4节)的图书目录程序，使其按照输入图书的顺序输出图书的信息，
 * 然后按照标题字母顺序输出图书的信息，最后按照价格的升序输出图书的信息。
 */

typedef struct { // 图书结构体
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
} Book;

void print_bookinfo_by_origin(const Book book[], int count);
void print_bookinfo_by_title(const Book book[], int count);
void print_bookinfo_by_sale(const Book book[], int count);
char* s_gets(char* st, int n);

int main()
{
    Book library[MAXBKS]; // 图书馆数组
    int count = 0; // 图书数量
    printf("Enter the title of the book (or empty line to stop):\n");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0') {
        printf("Enter the author of the book:\n");
        s_gets(library[count].author, MAXAUTL);
        printf("Enter the value of the book:\n");
        scanf("%f", &library[count].value);
        while (getchar() != '\n'); // 清除输入缓冲区
        count++;
        if (count < MAXBKS) {
            printf("Enter the title of the next book (or empty line to stop):\n");
        }
    }
    if (count > 0)
    {
        printf("print book info by origin:\n");
        print_bookinfo_by_origin(library, count); // 打印图书信息
        printf("\nprint book info by title:\n");
        print_bookinfo_by_title(library, count); // 按标题排序并打印图书信息
        printf("\nprint book info by sale:\n");
        print_bookinfo_by_sale(library, count); // 按售价排序并打印图书信息
    }
    else {
        printf("No books were entered.\n");
    }
}

char* s_gets(char* st, int n)
{
    char* ret_val;
    if (n <= 0) {
        return NULL; // 如果 n 小于等于 0，返回 NULL
    }
    ret_val = fgets(st, n, stdin); // 使用 fgets 读取字符串
    if (ret_val) {
        char* find;
        find = strchr(st, '\n'); // 查找换行符
        if (find) {
            *find = '\0'; // 替换换行符为字符串结束符
        }
        else {
            while (getchar() != '\n'); // 清除输入缓冲区
        }
    }
    return ret_val; // 返回读取的字符串
}

void print_bookinfo_by_origin(const Book book[], int count)
{
    for (int index = 0; index < count; index++) {
        printf("%s by %s: $%.2f\n", book[index].title, book[index].author, book[index].value);
    }
}

void print_bookinfo_by_title(const Book book[], int count)
{
    Book** ppbook = (Book**)malloc(count * sizeof(Book*));
    if (ppbook == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    for (int index = 0; index < count; index++) {
        ppbook[index] = (Book*)&book[index];
    }
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(ppbook[i]->title, ppbook[j]->title) > 0) {
                Book* temp = ppbook[i];
                ppbook[i] = ppbook[j];
                ppbook[j] = temp;
            }
        }
    }
    for (int index = 0; index < count; index++) {
        printf("%s by %s: $%.2f\n", ppbook[index]->title, ppbook[index]->author, ppbook[index]->value);
    }
    free(ppbook); // 释放内存
}

void print_bookinfo_by_sale(const Book book[], int count)
{
    Book** ppbook = (Book**)malloc(count * sizeof(Book*));
    if (ppbook == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    for (int index = 0; index < count; index++) {
        ppbook[index] = (Book*)&book[index];
    }
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (ppbook[i]->value - ppbook[j]->value > 0) {
                Book* temp = ppbook[i];
                ppbook[i] = ppbook[j];
                ppbook[j] = temp;
            }
        }
    }
    for (int index = 0; index < count; index++) {
        printf("%s by %s: $%.2f\n", ppbook[index]->title, ppbook[index]->author, ppbook[index]->value);
    }
    free(ppbook); // 释放内存
}
