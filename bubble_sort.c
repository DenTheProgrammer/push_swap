/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 18:27:39 by mdebbi            #+#    #+#             */
/*   Updated: 2019/05/23 18:27:41 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void bubble_sort(int *arr, size_t len)
{
	int swap_cnt;
	size_t i;
	int tmp;

	swap_cnt = 1;
	while (swap_cnt != 0)
	{
		swap_cnt = 0;
		i = 0;
		while (i < len - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				swap_cnt++;
			}
			i++;
		}
	}
}
