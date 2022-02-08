/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 19:41:30 by pveeta            #+#    #+#             */
/*   Updated: 2021/09/16 19:00:38 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_for_four_a(t_main *info)
{
	if (sort_for_four_a2(info->stack_a_tail, info->stack_a_tail->prev, \
				info->stack_a_head, info) == 1)
		return ;
	if (sort_for_four_a3 (info->stack_a_tail->prev, \
				info->stack_a_head, info) == 1)
	{
		sort_for_three_a(info);
		sort_command(info, PA);
	}
	else
	{
		sort_command(info, RRA);
		sort_command(info, RRA);
		sort_command(info, PB);
		sort_for_three_a(info);
		sort_command(info, PA);
	}
}

int	sort_for_four_a2(t_list *a, t_list *b, t_list *d, t_main *info)
{
	if (a->value > d->value && mini_arr_check_sort(a->value, d, a) == 1)
	{
		sort_command(info, RA);
		return (1);
	}
	if (b->value < a->value && mini_arr_check_sort(b->value, d, a) == 1)
	{
		sort_command(info, SA);
		return (1);
	}
	if (d->value < a->value && mini_arr_check_sort(d->value, d, a) == 1)
	{
		sort_command(info, RRA);
		return (1);
	}
	return (0);
}

int	sort_for_four_a3(t_list *b, t_list *d, t_main *info)
{
	if (check_min_value(info->stack_a_tail->value, info->stack_a_head) == 1)
	{
		sort_command(info, PB);
		return (1);
	}
	else if (check_min_value(b->value, info->stack_a_head) == 1)
	{
		sort_command(info, SA);
		sort_command(info, PB);
		return (1);
	}
	else if (check_min_value(d->value, info->stack_a_head) == 1)
	{
		sort_command(info, RRA);
		sort_command(info, PB);
		return (1);
	}
	return (0);
}

int	mini_arr_check_sort(int value, t_list *head, t_list *tail)
{
	t_list	*copy;
	t_list	*current;

	current = head;
	if (current->prev)
		copy = current->prev;
	while (current->next && current->next->value != value)
		current = current->next;
	if (current && current->prev && \
			current->value > current->prev->value)
		return (-1);
	if (current->prev != NULL)
	{
		copy = current->prev;
		while (copy != head)
		{
			if (copy->prev && copy->value > copy->prev->value)
				return (-1);
			copy = copy->prev;
		}
	}
	return (mini_arr_check_sort2(copy, current, tail));
}

int	mini_arr_check_sort2(t_list *copy, t_list *current, t_list *tail)
{
	if (current->next)
	{
		copy = current->next;
		while (copy != tail)
		{
			if (copy->next && copy->value < copy->next->value)
				return (-1);
			copy = copy->next;
		}
	}
	return (1);
}
