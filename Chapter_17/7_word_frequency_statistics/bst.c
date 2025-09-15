#include "bst.h"
#include <string.h>
BST* bst_create()
{
    return  (BST*)calloc(1, sizeof(BST));
}
/*
 * 向二叉搜索树中新增一个结点
 * 1.若key已存在，则不新增，插入失败
 * 2.若key不存在，则进行新增，插入成功
 */
bool bst_insert(BST* tree, KeyType key) {
    // 1.遍历找到插入的位置
    // 初始化两个指针,一个用于找到插入位置,一个用于指向它的父结点
    TreeNode* parent = NULL;
    TreeNode* curr = tree->root;
    int diff;   // while循环一定执行,不用担心diff未初始化
    while (curr != NULL) {  // 此遍历就是为了查找NULL,curr最终等于NULL说明查找到了插入位置
        diff = strcmp(key.word, curr->key.word);
        if (diff > 0) {
            // 待插入结点的key大于当前结点key
            // 向右遍历查找
            parent = curr;
            curr = curr->right;
        }
        else if (diff < 0)
        {
            // 待插入结点的key小于当前结点key
            // 向左遍历查找
            parent = curr;
            curr = curr->left;
        }
        else
        {
            // 待插入结点的key等于当前结点key
            // key重复,插入失败
            // word值加1
            curr->key.count++; 
            return true;
        }
    }   // 循环结束,说明curr是NULL,即key不重复,找到了插入的位置,parent指针指向待插入位置的父结点
        // 2.新建一个结点,初始化结点
        // 重要建议: 在二叉搜索树中新建结点,请一律使用calloc,安全第一!
    TreeNode* new_node = (TreeNode*)calloc(1, sizeof(TreeNode));
    if (new_node == NULL) {
        printf("calloc failed in bst_insert.\n");
        exit(1);
    }
    new_node->key = key;
    // 3.将新结点链接到二叉树上(链表的尾插)
    if (parent == NULL) {
        // 说明此时树是一个空树
        tree->root = new_node;  // 新结点成为根结点
        return true;    // 插入成功
    }
    // 插入的结点不是第一个结点
    if (diff < 0) {
        // 插入左子树
        parent->left = new_node;
    }
    else {
        // 插入右子树
        parent->right = new_node;
    }
    return true;
}
TreeNode* bst_search(BST* tree, KeyType key)
{
    TreeNode* curr = tree->root;
    while (curr != NULL) {
        if (strcmp(curr->key.word, key.word) == 0)
        {
            return curr;
        }
        else  if (strcmp(curr->key.word, key.word) > 0)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
    return NULL;
}

// 根据 key 删除一个结点
bool bst_delete(BST* tree, KeyType key) {
	// 1.利用 curr 和 parent 两个指针找到待删除结点以及它的父节点
	TreeNode* curr = tree-> root;
	TreeNode* parent = NULL;
	// 2.根据 key 值的大小关系, 来遍历这棵树的结点
	while (curr != NULL) {  // 这一点模拟了单链表的遍历, 因为搜索路径就是一条单链表
		int diff = strcmp(key.word, curr->key.word);
		if (diff > 0) {
			// 待删除 key 值比当前结点 key 值要大, 于是去右子树中遍历查找
			parent = curr;
			curr = curr-> right;
		}
		else if (diff < 0) {
			// 待删除 key 值比当前结点 key 值要小, 于是去左子树中遍历查找
			parent = curr;
			curr = curr-> left;
		}
		else {
			// 找到待删除结点, 下面就开始删除该结点的操作
			break;
		}
	}
	/*
		while 循环结束, 有两种可能性:
		1.找到了目标 key 结点, 依赖 break 结束循环
			此时 curr 指针指向待删除结点, parent 指向它的父结点
		2.没找到目标 key 结点, 依赖 curr 变成 NULL 结束循环
			此时 curr 指针是 NULL 相当于找到了这个不存在 key 结点的插入位置
			而 parent 就指向插入位置的父结点
		以上两种情况, 如果是第一种情况, 我们就继续删除
		但如果是第二种情况, 目标结点不存在, 删除就失败了
	*/
	if (curr == NULL) {
		return false;
	}
	// 2.根据度不同来进行不同的处理, 使得待删除结点从树结构中断开
	// 2.1 判断结点的度是否为 2, 如果度为 2, 进行降级处理
	if (curr-> left != NULL && curr-> right != NULL) {
		// 删除的结点是度为 2 的, 于是将它降低为删除度为 0 或 1
		TreeNode* min_node = curr-> right;   // 寻找待删除结点的右子树最小结点, 从 curr 的右子树结点开始
		TreeNode* min_parent = curr;    // 寻找待删除结点的右子树最小结点的父结点
		while (min_node-> left != NULL) {
			min_parent = min_node;
			min_node = min_node-> left;
		}   // while 循环结束时, min_node 指向右子树最小结点, min_parent 指向 min_node 结点的父结点
		// 将右子树最小结点的值替换给 curr 结点, 并且后续将删除右子树最小结点
		curr-> key = min_node-> key;
		// 后续的删除操作都是基于 curr 指针和 parent 指针的, 所以这里要进行一步赋值操作
		curr = min_node;
		parent = min_parent;
	}
	// 接下来待删除的结点就是 curr 结点, 它的父结点就是 parent, 而且这个结点的度一定是 0 或 1
	// 2.2 统一处理度为 0 或 1 结点的删除操作
	// 核心操作: parent -> left/right = curr -> left/right
	// 先确定 parent 指向待删除结点的左子树还是右子树
	TreeNode* child = (curr-> left != NULL) ? curr-> left : curr-> right;
	/*
		考虑特殊情况:
		删除的结点是度为 0 或 1 的根结点
		此时需要更新根结点指针
	*/
	if (parent == NULL) {
		// 删除的结点是根结点, 此根结点度为 0 或 1
		tree-> root = child;
	}
	else {
		// 删除的结点不是根结点
		// 执行核心操作: parent -> left/right = child;
		if (parent-> left == curr) {
			// 待删除结点是父结点的左子树, 那么就让父结点的左子树指向 child
			parent-> left = child;
		}
		else {
			// 待删除结点是父结点的右子树, 那么就让父结点的右子树指向 child
			parent-> right = child;
		}
	}
	// 3.free 这个结点
	free(curr); // 删除成功
	return true;
}

/*
   利用递归实现BST的先序遍历
   root参数表示此一轮递归调用中的根结点
   先序遍历是: DLR
   分解的思路是:
   对于任何一棵树root来说:
   1.总是先输出根结点的值
   2.然后递归遍历它的左子树
   3.最后递归遍历它的右子树
   preoder(root) = D + preorder(root->left) + preorder(root->right)
   这就是递归体
   这样的分解不会无休止进行,如果分解成一棵空树,也就是root是空指针时,返回函数
   这就是递归的出口
   */
static void preorder(TreeNode* root) {
    if (root == NULL)
    {
        return;
    }
    printf("%s %d\n", root->key.word, root->key.count);
    preorder(root->left);
    preorder(root->right);
}
// 深度优先-先序遍历
void bst_preorder(BST* tree)
{
    if (tree == NULL) {
        // 树为空直接返回
        return;
    }
    // 利用辅助函数递归实现BST的先序遍历
    preorder(tree->root);
    printf("\n");
}
/*
   利用递归实现BST的中序遍历
   root参数表示此一轮递归调用中的根结点
   中序遍历是: LDR
   分解的思路是:
   对于任何一棵树root来说:
   1.总是先递归遍历它的左子树
   1.然后再输出根结点的值
   3.最后递归遍历它的右子树
   inorder(root) = inorder(root->left) + D + inorder(root->right)
   这就是递归体
   这样的分解不会无休止进行,如果分解成一棵空树,也就是root是空指针时,返回函数
   这就是递归的出口
   */
static void inorder(TreeNode* root) {
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%s %d\n", root->key.word, root->key.count);
    inorder(root->right);
}
// 深度优先-中序遍历
void bst_inorder(BST* tree)
{
    if (tree == NULL) {
        // 树为空直接返回
        return;
    }
    // 利用辅助函数递归实现BST的中序遍历
    inorder(tree->root);
    printf("\n");
}
/*
   利用递归实现BST的后序遍历
   root参数表示此一轮递归调用中的根结点
   中序遍历是: LRD
   分解的思路是:
   对于任何一棵树root来说:
   1.总是先递归遍历它的左子树
   3.然后递归遍历它的右子树
   3.最后再输出根结点的值
   postorder(root) = postorder(root->left) + postorder(root->right) + D
   这就是递归体
   这样的分解不会无休止进行,如果分解成一棵空树,也就是root是空指针时,返回函数
   这就是递归的出口
   */
static void postorder(TreeNode* root) {
    // 1.递归的出口
    if (root == NULL) {
        return;
    }
    // 2.递归体
    postorder(root->left);
    postorder(root->right);
    printf("%s %d\n", root->key.word, root->key.count);
}
void bst_postorder(BST* tree) {
    if (tree == NULL) {
        // 树为空直接返回
        return;
    }
    // 利用辅助函数递归实现BST的后序遍历
    postorder(tree->root);
    printf("\n");
}
static void destroy(TreeNode* root) {
    // 1.递归的出口
    if (root == NULL) {
        return;
    }
    // 2.递归体
    destroy(root->left);
    destroy(root->right);
    free(root);
}
void bst_destroy(BST* tree)
{
    if (tree == NULL) {
        // 树为空直接返回
        return;
    }
    // 利用辅助函数递归实现BST的销毁
    destroy(tree->root);
    free(tree);
}
