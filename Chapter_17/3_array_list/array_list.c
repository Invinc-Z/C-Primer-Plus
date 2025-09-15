/* list.c -- 支持链表操作的函数 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array_list.h"

/* 接口函数 */

/* 把链表设置为空 */
void InitializeList(List * plist)
{
    memset(plist->entries, 0, sizeof(plist->entries));
    plist->items = 0;
}

/* 如果链表为空，返回true */
bool ListIsEmpty(const List * plist)
{
    if (plist->items == 0)
        return true;
    else
        return false;
}

/* 如果链表已满，返回true */
bool ListIsFull(const List * plist)
{
    if (plist->items == MAXSIZE)
        return true;
    else
        return false;
}

/* 返回节点的数量 */
unsigned int ListItemCount(const List * plist)
{
    return plist->items;
}

/* 添加项 */
bool AddItem(Item item, List * plist)
{
    if(plist->items == MAXSIZE)
        return false;
    plist->entries[plist->items] = item;
    plist->items++;
    return true;
}

/* 访问每个节点并执行pfun指向的函数 */
void Traverse(const List * plist, void(*pfun)(Item item))
{
    for(int i = 0; i < plist->items; i++)
        (*pfun)(plist->entries[i]); /* 把函数应用于链表中的项 */
}

/* 释放由malloc()分配的内存 */
/* 设置链表指针为NULL */
void EmptyTheList(List * plist)
{
    plist->items = 0;
}

