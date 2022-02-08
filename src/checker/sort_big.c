/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 19:59:23 by pveeta            #+#    #+#             */
/*   Updated: 2021/09/12 20:06:04 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_main *info)
{
	while (check_finish(info) != 1)
	{
		while (find_size_stack(info->stack_b_head) > 0)
			get_from_b(info);
		if (check_finish(info) != 1)
		{
			if (size_lot(info) == 1)
				check_top_3_side(info, 1);
			else if (info->stack_a_tail->lot == 0 && size_lot(info) > 30)
				work_0_lot(info);
			else if (info->stack_a_tail->lot == info->stack_a_tail->prev->lot)
			{
				check_2_in_lot(info);
				info->lots = info->stack_a_tail->lot;
				get_lot_from_a(info);
			}
			while (find_size_stack(info->stack_b_head) > 0)
				get_from_b(info);
		}
	}
}

void	get_lot_from_a(t_main *info)
{
	int	min;
	int	max;

	if (info->stack_a_tail->lot == -1)
		return ;
	min = find_min_in_lot(info->stack_a_tail);
	max = max_ord_in_stack(info->stack_a_head);
	info->mid_order = (max - min + 1) / 2 + min;
	while (info->stack_a_tail->lot == info->lots)
	{
		if (info->stack_a_tail->order == info->next)
		{
			(info->next)++;
			info->stack_a_tail->lot = -1;
			sort_command(info, RA);
			if (info->stack_b_tail && (info->stack_b_tail->order < \
						(info->mid_order - info->next + 1) / 2 + info->next))
				sort_command(info, RB);
		}
		else if (info->stack_a_tail->order != info->next)
			sort_command(info, PB);
	}
}

void	get_from_b(t_main *info)
{
	int	min;
	int	max;

	min = min_ord_in_stack(info->stack_b_head);
	max = max_ord_in_stack(info->stack_b_head);
	info->lots = info->stack_a_tail->lot + 1;
	info->mid_order = (max - min + 1) / 2 + min;
	if (find_size_stack(info->stack_b_head) > 5)
		new_mediana_b(info, max - info->mid_order);
	while (info->stack_b_head && find_size_stack(info->stack_b_head) <= 5)
	{
		if (check_top_3_side(info, 2) != 1)
		{
			info->lots = info->stack_a_tail->lot + 1;
			sort_command(info, PA);
		}
	}
}

void	new_mediana_b(t_main *info, int counter)
{
	while (counter > 0 && find_size_stack(info->stack_b_head) > 0)
	{
		while (check_top_3_side(info, 2) == 1)
			;
		if (info->stack_b_tail && info->stack_b_tail->order > \
								  info->mid_order)
		{
			info->stack_b_tail->lot = info->lots;
			sort_command(info, PA);
			counter--;
		}
		else if (info->stack_b_tail && info->stack_b_tail->order <= \
									   info->mid_order)
			sort_command(info, RB);
	}
}

void	work_0_lot(t_main *info)
{
	int	m;
	int	counter;

	m = find_min_in_lot(info->stack_a_tail);
	info->mid_order = (max_ord_in_stack(info->stack_a_head) - m + 1) / 2 + m;
	counter = info->mid_order - m + 1;
	while (info->stack_a_tail->lot == 0 && counter >= 0)
	{
		if (info->stack_a_tail->order > info->mid_order)
		{
			sort_command(info, RA);
			if (info->stack_b_tail && (info->stack_b_tail->order < \
			(info->mid_order - info->next + 1) / 2 + info->next))
				sort_command(info, RB);
		}
		else if (counter-- >= 0)
			sort_command(info, PB);
	}
	while (info->stack_a_head->lot != -1)
	{
		sort_command(info, RRA);
		if (info->stack_b_tail && info->stack_b_tail->order < \
		(info->mid_order - info->next + 1) / 2 + info->next)
			sort_command(info, RRB);
	}
}
