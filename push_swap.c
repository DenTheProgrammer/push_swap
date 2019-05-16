//
// Created by Maybell Debbi on 2019-05-16.
//


#include "push_swap.h"


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
//    while (a->size > 0)
//        push(a, b);
    while (b->size > 0)
        push(b, a);
//    rotate(a);
//    rotate(a);
//    rotate(a);
//    rotate(a);
//    rotate(a);
//    rotate(a);
//    rotate(a);
//    rotate(a);
//    rotate(a);
//    rotate(a);
//    rotate(a);
//    reverse_rotate(a);
//    reverse_rotate(a);
//    reverse_rotate(a);
//    reverse_rotate(a);
//    reverse_rotate(a);
//    reverse_rotate(a);
    return (0);
}