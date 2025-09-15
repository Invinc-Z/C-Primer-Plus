#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

/**
 * 编写一个程序，打开和读取一个文本文件，并统计文件中每个单词出现的次数。
 * 用改进的二叉查找树储存单词及其出现的次数。程序在读入文件后，会提供一个有3个选项的菜单。
 * 第1个选项是列出所有的单词和出现的次数。
 * 第2个选项是让用户输入一个单词，程序报告该单词在文件中出现的次数。
 * 第3个选项是退出。
 */

void show_menu();
char get_choice();

int main()
{
    BST* pbst = bst_create();
    KeyType key;
    memset(&key, 0, sizeof(key));
    FILE* fp = fopen("word.txt", "r");
    if(fp == NULL)
    {
        printf("open file error.\n");
        exit(EXIT_FAILURE);
    }

    char line[SIZE] = {0};
    while (fgets(line, sizeof(line), fp) != NULL) {
        char *token = strtok(line, " \t\n"); // 指定分隔符为空格、制表符或换行符
        while (token != NULL) {
            /* printf("单词: %s\n", token); */
            memset(&key, 0, sizeof(key));
            key.count = 1;
            strcpy(key.word, token);
            bst_insert(pbst, key);
            token = strtok(NULL, " \t\n"); // 继续分割同一行
        }
    }
    char word[64] = {0};
    while(1)
    {
        show_menu();
        switch(get_choice())
        {
        case 'a':
            bst_inorder(pbst);
            break;
        case 'b':
            {
                printf("please enter the word you want to search: ");
                scanf("%s", word);
                memset(&key, 0, sizeof(key));
                strcpy(key.word, word);
                TreeNode* pnode = bst_search(pbst, key);
                if(pnode == NULL)
                    printf("\"%s\" occurs %d\n", word, 0);
                else
                    printf("\"%s\" occurs %d\n", word, pnode->key.count);
                break;
            }
        case 'q':
            puts("bye");
            exit(0);
        }
    }

    return 0;
}

void show_menu()
{
    printf("==============================\n");
    printf("a. Show words and their count\n");
    printf("b. Find word count\n");
    printf("q. Quit\n");
}

char get_choice()
{
    char ch;
    while(scanf(" %c", &ch) != 1 || (ch != 'a' && ch != 'b' && ch != 'q'))
    {
        printf("Please enter letter(a, b or q): ");
        while(getchar() != '\n')
            continue;
        continue;
    }
    while(getchar() != '\n')
        continue;
    return ch;
}
