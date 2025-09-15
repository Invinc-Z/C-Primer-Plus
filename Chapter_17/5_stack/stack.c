#include "stack.h"
#include <stdlib.h>

void init_stack(stack_t* p_stack)
{
    p_stack->top = NULL;
    p_stack->count = 0;
}

bool is_empty_stack(const stack_t* p_stack)
{
    return p_stack->count == 0;
}

int count_stack(const stack_t* p_stack)
{
    return p_stack->count;
}

bool en_stack(stack_t* p_stack, Item item)
{
    node_t* pnew = (node_t*)calloc(1, sizeof(node_t));
    if(pnew == NULL)
        return false;
    pnew->item = item;
    pnew->next = p_stack->top;
    p_stack->top = pnew;
    p_stack->count++;

    return true;
}

bool de_stack(stack_t* p_stack, Item* item)
{
    if(is_empty_stack(p_stack))
        return false;
    node_t* curr = p_stack->top;
    *item = curr->item;
    p_stack->top = curr->next;
    free(curr);
    p_stack->count--;
    return true;
}

void destroy_stack(stack_t* p_stack)
{
    Item* item = NULL;
    while(!is_empty_stack(p_stack))
    {
        de_stack(p_stack, item);
    }
}

