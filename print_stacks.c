/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 18:28:35 by mdebbi            #+#    #+#             */
/*   Updated: 2019/05/23 18:28:36 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stacks(t_stack *a, t_stack *b)
{
	t_node *ahead = a->head;
	t_node *bhead = b->head;

	while (ahead || bhead)
	{
		if (ahead && bhead)
		{
			ft_printf("|%5d|    |%5d|\n", ahead->nbr, bhead->nbr);
			ahead = ahead->next;
			bhead = bhead->next;
		}
		else if (ahead)
		{
			ft_printf("|%5d|    |     |\n", ahead->nbr);
			ahead = ahead->next;
		}
		else
		{
			ft_printf("|     |    |%5d|\n", bhead->nbr);
			bhead = bhead->next;
		}
	}
	ft_printf("   a          b  \n");
}
