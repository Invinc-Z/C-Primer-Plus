#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"

/**
 * 修改宠物俱乐部程序，把所有同名的宠物都储存在同一个节点中。
 * 当用户选择查找宠物时，程序应询问用户该宠物的名字，然后列出该名字的所有宠物（及其种类）。
 */

char get_choice();
char * s_gets(char * st, int n);
void add_pet(Tree * pt);
void print_pet(Item temp);
void find_pet(const Tree * pt);
void drop_pet(Tree * pt);
void show_pet(const Tree * pt);

int main(void)
{
    Tree pet;
    char ch;

    InitializeTree(&pet);
    while ((ch = get_choice()) != 'q')
    {
        switch (ch)
        {
        case 'a': add_pet(&pet);
                  break;
        case 'l': show_pet(&pet);
                  break;
        case 'f': find_pet(&pet);
                  break;
        case 'n': printf("%d pets in club.\n",
                         TreeItemCount(&pet));
                  break;
        case 'd': drop_pet(&pet);
                  break;
        default: puts("Switching error");
        }
        printf("\n");
    }

    DeleteAll(&pet);
    printf("Bye.\n");

    return 0;
}

char get_choice()
{
    char ch;

    puts("Nerfville Pet Club Membership Program");
    puts("Enter the letter corresponding to your choice:");
    puts("a) add a pet        l) show list of pets");
    puts("n) number of pets   f) find pets");
    puts("d) delete a pet     q) quit");


    ch = getchar();
    while (strchr("alnfdq", tolower(ch)) == NULL)
    {
        while (getchar() != '\n')
            continue;
        printf("Please input the a, l, n, f, d or q.\n");
        ch = getchar();
    }
    while (getchar() != '\n')
        continue;

    return ch;
}

void show_pet(const Tree * pt)
{
    if (TreeIsEmpty(pt))
        printf("No pet in club.\n");
    else
        Traverse(pt, print_pet);
}

void find_pet(const Tree * pt)
{
    Item temp;

    if (TreeIsEmpty(pt))
        puts("No pet in the club.\n");
    else
    {
        printf("Enter the name of pet:\n");
        s_gets(temp.petname, SLEN);
        FindItem(&temp, pt);
    }
}

void add_pet(Tree * pt)
{
    Item temp;

    if (TreeIsFull(pt))
        puts("No room in the club.\n");
    else
    {
        printf("Enter the name of pet:\n");
        s_gets(temp.petname, SLEN);
        printf("Enter the kind of pet:\n");
        s_gets(temp.kind[0], SLEN);
        temp.num = 1;
        AddItem(&temp, pt);
    }
}

void drop_pet(Tree * pt)
{
    Item temp;

    if (TreeIsEmpty(pt))
    {
        puts("No entries.\n");
        return;
    }

    printf("Enter the name of pet:\n");
    s_gets(temp.petname, SLEN);
    if (DeleteItem(&temp, pt) == 0)
    {
        printf("Can't find the pet.\n");
    }
}

void print_pet(Item temp)
{
    int i;

    printf("name: %s\t\tkind: ", temp.petname);
    for (i = 0; i < temp.num; i++)
        printf("%s ", temp.kind[i]);
    printf("\n");
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}
