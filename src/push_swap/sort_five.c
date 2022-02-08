/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 19:57:18 by pveeta            #+#    #+#             */
/*   Updated: 2021/09/12 19:59:14 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_for_five_a(t_main *info)
{
	t_list	*a;
	t_list	*b;
	t_list	*e;

	e = info->stack_a_head;
	b = info->stack_a_tail->prev;
	a = info->stack_a_tail;
	if (b->value < a->value && mini_arr_check_sort(b->value, e, a) == 1)
		sort_command(info, SA);
	else if (a->value > e->value && mini_arr_check_sort(a->value, e, a) == 1)
		sort_command(info, RA);
	else if (e->value < a->value && mini_arr_check_sort(e->value, e, a) == 1)
		sort_command(info, RRA);
	else
		sort_for_five_a2(info);
}

void	sort_for_five_a2(t_main *info)
{
	while (find_size_stack(info->stack_a_head) >= 4)
	{
		if (info->stack_a_tail->order < 3)
			sort_command(info, PB);
		else
		{
			sort_command(info, RA);
			if (mini_arr_check_sort(info->stack_a_head->value, \
						info->stack_a_head, info->stack_a_tail) == 1 && \
				(info->stack_a_head->value > info->stack_a_head->next->value) \
				&& find_size_stack(info->stack_b_head) == 0)
				return ;
		}
	}
	if (info->stack_b_tail->order == 1 && \
			find_size_stack(info->stack_b_head) > 1)
		sort_command(info, SB);
	sort_for_three_a(info);
	sort_command(info, PA);
	sort_command(info, PA);
}
