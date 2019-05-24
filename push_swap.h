/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 18:29:22 by mdebbi            #+#    #+#             */
/*   Updated: 2019/05/23 18:29:28 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_PUSH_SWAP_H
# define PUSH_SWAP_PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "printf.h"
# include "libft/libft.h"

typedef struct s_node
{
    int nbr;
    struct s_node *prev;
    struct s_node *next;
} t_node;

typedef struct s_stack
{
	char *name;
    int size;
    t_node *head;
    t_node *tail;
} t_stack;

int *parseinput(int argc, char **argv);
int 	is_valid_input(char **input, int size);

t_node *create_node(int nbr);
void    add_node_tail(t_node **tail, t_node *node);
t_stack *create_stack(int *arr, int size, char *name);
void print_stacks(t_stack *a, t_stack *b);
void	free_stack(t_stack *stack);
int is_sorted_asc(t_stack *a);
int is_sorted_desc(t_stack *a);

void    swap(t_stack *stack, char **ops);
void    swap_both(t_stack *a, t_stack *b, char **ops);
void    push(t_stack *src, t_stack *dest, char **ops);
void    rotate(t_stack *stack, char **ops);
void    rot_both(t_stack *a, t_stack *b, char **ops);
void    rev_rotate(t_stack *stack, char **ops);
void    rev_rot_both(t_stack *a, t_stack *b, char **ops);

void bubble_sort(int *arr, size_t len);
void    radix_sort(t_stack *a, t_stack *b, char **ops);
void	mdebbis_sort(t_stack *a, t_stack *b, int *tab, size_t len, char **ops);


int is_cyclesorted_desc(t_stack *stack);
char **ops_trimmer(char **oparr);
char **ops_smarter(char **oparr);
char	**del(char **arr, int len, int ind);
char **one_line_fix(char **arr);
void	throw_error(char *msg);
int arrlen(char **arr);
char	**argvdup(int argc, char **argv, int visual);
#endif
