/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_lists.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 20:29:02 by pveeta            #+#    #+#             */
/*   Updated: 2021/09/12 20:30:50 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_size_stack(t_list *stack)
{
	t_list	*copy;
	int		size;

	if (stack == NULL)
		return (0);
	size = 1;
	copy = stack;
	while (copy->next != NULL)
	{
		copy = copy->next;
		size++;
	}
	return (size);
}

t_list	*find_last(t_list *stack)
{
	t_list	*copy;

	if (stack == NULL)
		return (NULL);
	copy = stack;
	while (copy->next != NULL)
		copy = copy->next;
	return (copy);
}

int	check_min_value(int value, t_list *stack)
{
	t_list	*copy;

	copy = stack;
	while (copy != NULL)
	{
		if (copy->value < value)
			return (-1);
		copy = copy->next;
	}
	return (1);
}

int	check_max_value(int value, t_list *stack)
{
	t_list	*copy;

	copy = stack;
	while (copy != NULL)
	{
		if (copy->value > value)
			return (-1);
		copy = copy->next;
	}
	return (1);
}

int	check_finish(t_main *info)
{
	if (find_size_stack(info->stack_a_head) == 0)
		return (0);
	if (check_min_value(info->stack_a_tail->value, info->stack_a_head)
		== 1 && \
	mini_arr_check_sort(info->stack_a_tail->value, info->stack_a_head, \
	info->stack_a_tail) == 1 && find_size_stack(info->stack_b_head) == 0)
		info->flag_finish = 1;
	return (info->flag_finish);
}
