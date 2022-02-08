/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_lot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 20:27:13 by pveeta            #+#    #+#             */
/*   Updated: 2021/09/12 20:28:56 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_in_lot(t_list *tail)
{
	int		min_ord;
	t_list	*copy;

	if (tail == NULL)
		return (-1);
	min_ord = tail->order;
	copy = tail;
	while (copy->prev != NULL && copy->lot == copy->prev->lot)
	{
		if (min_ord > copy->prev->order)
			min_ord = copy->prev->order;
		copy = copy->prev;
	}
	return (min_ord);
}

int	max_ord_in_stack(t_list *stack)
{
	int		max_ord;
	t_list	*copy;

	if (stack == NULL)
		return (-1);
	max_ord = stack->order;
	copy = stack;
	while (copy->next != NULL)
	{
		if (max_ord < copy->next->order)
			max_ord = copy->next->order;
		copy = copy->next;
	}
	return (max_ord);
}

int	min_ord_in_stack(t_list *stack)
{
	int		min_ord;
	t_list	*copy;

	if (stack == NULL)
		return (-1);
	min_ord = stack->order;
	copy = stack;
	while (copy->next != NULL)
	{
		if (min_ord > copy->next->order)
			min_ord = copy->next->order;
		copy = copy->next;
	}
	return (min_ord);
}

void	check_2_in_lot(t_main *info)
{
	if (size_lot(info) == 2)
	{
		if (info->stack_a_tail->order > info->stack_a_tail->prev->order)
		{
			sort_command(info, SA);
			if (info->stack_b_tail && info->stack_b_tail->prev && \
				info->stack_b_tail->order > info->stack_b_tail->prev->order)
				sort_command(info, SB);
		}
		while (check_top_3_side(info, 1) == 1)
			;
	}
}

int	size_lot(t_main *info)
{
	int		res;
	t_list	*copy;

	res = 1;
	copy = info->stack_a_tail;
	while (copy->prev != NULL && copy->prev->lot == copy->lot)
	{
		res++;
		copy = copy->prev;
	}
	return (res);
}
