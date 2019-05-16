//
// Created by Maybell Debbi on 2019-05-16.
//


#include "push_swap.h"


void    swap(t_stack *stack, char *name)
{
    t_node *tmp;

    if (stack->size == 1)
        return ;
    if (stack->size == 2)
        stack->tail = stack->head;
    tmp = stack->head;
    stack->head = stack->head->next;
    tmp->next = stack->head->next;
    stack->head->next = tmp;
    if (*name)
        printf("s%s\n", name);
}

void    swap_both(t_stack *a, t_stack *b)
{
    swap(a, "");
    swap(b, "");
    printf("ss");

}

void    push(t_stack *src, t_stack *dest)
{
    t_node *tmp;

    if (src->size == 0)
        return ;
    tmp = src->head;
    src->head = src->head->next;
    tmp->next = dest->head;
    dest->head = tmp;
    src->size--;
    dest->size++;
    if (src->size == 0 || src->size == 1)
        src->tail = src->size == 0 ? src->head : NULL;
    if (dest->size == 1)
        dest->tail = dest->head;
}

int main()
{
    int testa[] = {0, 45, 65, 90, -4};
    int testb[] = {1};
    t_stack *a = create_stack(testa, sizeof(testa)/ sizeof(int));
    t_stack *b = create_stack(testb, sizeof(testb)/ sizeof(int));
//    swap(a, "a");
//    swap(b, "b");
//    swap_both(a, b);
//    push(a, b);
//    push(b, a);
    while (a->size > 0)
        push(a, b);
    while (b->size > 0)
        push(b, a);
    return (0);
}