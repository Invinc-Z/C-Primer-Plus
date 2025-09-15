/**
 * 类型名：栈
 * 类型属性：可以储存一系列项
 * 类型操作：
 * 初始化栈为空
 * 确认栈为空
 * 确认栈中项数
 * 栈尾部压栈
 * 栈头部弹栈
 * 清空栈
 */

#include <stdbool.h>

typedef char Item;

typedef struct node_s {
    Item item;
    struct node_s* next;
}node_t;

typedef struct stack_s {
    node_t* top;
    int count;
} stack_t;

void init_stack(stack_t* p_stack);

bool is_empty_stack(const stack_t* p_stack);

int count_stack(const stack_t* p_stack);

bool en_stack(stack_t* p_stack, Item item);

bool de_stack(stack_t* p_stack, Item* item);

void destroy_stack(stack_t* p_stack);

