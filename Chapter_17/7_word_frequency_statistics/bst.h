#ifndef BST_H
#define BST_H
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#define SIZE 32
/* typedef int KeyType; */
typedef struct {
    char word[SIZE];
    int count;
} KeyType;
typedef struct node {
    KeyType key;        // 结点key值,具有唯一性
    struct node* left;  // 左子树
    struct node* right; // 右子树
} TreeNode;
// 推荐定义一个二叉搜索树的结构体,这样更便于扩展
typedef struct {
    TreeNode* root; // 根结点指针
}BST;
// 基础操作
// 创建一棵空的BST
BST* bst_create();
// 销毁一棵BST
void bst_destroy(BST* tree);
// 根据key插入一个新结点
bool bst_insert(BST* tree, KeyType key);
// 根据key搜索某个结点并返回
TreeNode* bst_search(BST* tree, KeyType key);
// 根据key删除一个结点
bool bst_delete(BST* tree, KeyType key);
// 深度优先-先序遍历
void bst_preorder(BST* tree);
// 深度优先-中序遍历
void bst_inorder(BST* tree);
// 深度优先-后序遍历
void bst_postorder(BST* tree);
#endif // !BST_H
