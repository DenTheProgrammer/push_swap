/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list&stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 18:28:03 by mdebbi            #+#    #+#             */
/*   Updated: 2019/05/23 18:28:04 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *create_node(int nbr)
{
    t_node *new;

    new = (t_node*)malloc(sizeof(t_node));
    new->nbr = nbr;
    new->next = NULL;
    new->prev = NULL;
    return (new);
}

void    add_node_tail(t_node **tail, t_node *node)
{
    if(*tail)
        (*tail)->next = node;
    node->prev = *tail;
    *tail = node;
}


t_stack *create_stack(int *arr, int size, char *name)
{
    t_stack *new;
    int i;
    t_node *curr;

    new = (t_stack*)malloc(sizeof(t_stack));
    new->name = name;
    new->size = size;
    new->head = NULL;
    new->tail = NULL;
    i = 0;
    while (i < size)
    {
        curr = create_node(arr[i]);
        if (i++ == 0)
            new->head = curr;
        add_node_tail(&(new->tail), curr);
    }
    return (new);
}

void	free_stack(t_stack *stack)
{
	t_node *head = stack->head;
	t_node *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}

int arrlen(char **arr)
{
	int len;

	len = 0;
	while (*arr++)
		len++;
	return (len);
}
