#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAXTITL 64
#define MAXAUTL 64
#define MAXBKS 100

/**
 * .修改程序清单 14.14，从文件中读取每条记录并显示出来，允许用户删除记录或修改记录的内容。
 * 如果删除记录，把空出来的空间留给下一个要读入的记录。要修改现有的文件内容，必须用"r+b"模式，而不是"a+b"模式。
 * 而且，必须更加注意定位文件指针，防止新加入的记录覆盖现有记录。
 * 最简单的方法是改动储存在内存中的所有数据，然后再把最后的信息写入文件。
 * 跟踪的一个方法是在book结构中添加一个成员表示是否该项被删除。
 */

struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
    bool is_deleted; // 标记是否已删除
};

void show_books(struct book library[], int count);
void add_book(struct book library[], int* count);
void del_book(struct book library[], int* count);
char* s_gets(char* str, int n);

int main()
{
    struct book library[MAXBKS] = { 0 }; // 图书馆数组
    FILE* pbooks;
    int size = sizeof(struct book);
    if ((pbooks = fopen("book.dat", "rb+")) == NULL) // 打开二进制文件
    {
        printf("Cannot open book.dat file.\n");
        exit(EXIT_FAILURE);
    }
    int count = 0;
    while (fread(&library[count], size, 1, pbooks) == 1 && count < MAXBKS) {
        count++;
    }
    // 图书操作
    puts("Please enter choice to operate the book lists");
    puts("Press 'p' to print books info, 'a' to add a book, 'd' to delete a book, or 'q' to quit.");
    char ch = getchar();
    while (ch != 'q' && ch != 'Q') {
        while (getchar() != '\n'); // 清除输入缓冲区
        if (ch == 'p' || ch == 'P') show_books(library, count);
        else if (ch == 'a' || ch == 'A') add_book(library, &count);
        else if (ch == 'd' || ch == 'D') del_book(library, &count);
        else
            printf("Invalid menu item. Please try again.\n");
        puts("Press 'p' to print books info, 'a' to add a book, 'd' to delete a book, or 'q' to quit.");
        ch = getchar();
    }
    // 保存图书信息到文件
    for (int i = 0; i < count; i++) {
        if (library[i].is_deleted) continue; // 跳过已删除的书籍
        if (fwrite(&library[i], size, 1, pbooks) != 1) {
            printf("Error writing book data to file.\n");
            exit(EXIT_FAILURE);
        }
    }
    fclose(pbooks);
    printf("bye\n");

    return 0;
}
void show_books(struct book library[], int count)
{
    if (count == 0) printf("The book list is empty.\n");
    for (int i = 0; i < count; i++)
    {
        if (!library[i].is_deleted) { // 如果没有被标记为删除
            printf("%s by %s, $%.2f\n", library[i].title, library[i].author, library[i].value);
        }
    }
}

void add_book(struct book library[], int* count)
{
    int flag = 0;
    for (int i = 0; i < *count; i++)
    {
        if (library[i].is_deleted) { // 如果被标记为删除
            printf("Enter the title of the book:\n");
            s_gets(library[i].title, MAXTITL);
            printf("Enter the author of the book:\n");
            s_gets(library[i].author, MAXAUTL);
            printf("Enter the value of the book:\n");
            scanf("%f", &library[i].value);
            library[i].is_deleted = false; // 新增的书籍未被删除
            while (getchar() != '\n'); // 清除输入缓冲区
            flag = 1;
            break;
        }
    }
    if(flag == 1) 
        return;
    // *count 都为 false，表示都未被标记为删除
    if(*count < MAXBKS) {
        printf("Enter the title of the new book:\n");
        s_gets(library[*count].title, MAXTITL);
        printf("Enter the author of the new book:\n");
        s_gets(library[*count].author, MAXAUTL);
        printf("Enter the value of the new book:\n");
        scanf("%f", &library[*count].value);
        library[*count].is_deleted = false; // 新增的书籍未被删除
        while (getchar() != '\n'); // 清除输入缓冲区
        (*count)++;
    }
    else {
        printf("Library is full. Cannot add more books.\n");
    }
}

void del_book(struct book library[], int* count)
{
    if (*count == 0) {
        printf("No books to delete.\n");
    }
    printf("Please enter the title of the book to delete:\n");
    char title[MAXTITL];
    s_gets(title, MAXTITL);
    bool found = false;
    for (int i = 0; i < *count; i++) {
        if (!library[i].is_deleted && strcmp(library[i].title, title) == 0) {
            library[i].is_deleted = true; // 标记为删除
            found = true;
            printf("Book \"%s\" deleted.\n", title);
            break;
        }
    }
    if (!found) {
        printf("Book \"%s\" not found.\n", title);
    }
    // 清除已删除的书籍
    int new_count = 0;
    for (int i = 0; i < *count; i++) {
        if (!library[i].is_deleted) {
            if (i != new_count) {
                library[new_count] = library[i]; // 移动未删除的书籍
            }
            new_count++;
        }
    }
    *count = new_count; // 更新图书数量
}

char* s_gets(char* str, int n)
{
    char* ret_val;
    char* find;
    ret_val = fgets(str, n, stdin);
    if(ret_val)
    {
        find = strchr(str, '\n');
        if(find) *find = '\0';
        else
        {
            while(getchar() != '\n')
                continue;
        }
    }
    return ret_val;
}
