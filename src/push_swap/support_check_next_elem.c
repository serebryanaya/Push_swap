/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_next_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 19:23:29 by pveeta            #+#    #+#             */
/*   Updated: 2021/09/12 19:29:46 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_top_3_side_a(t_main *info)
{
	if (info->stack_a_tail->prev && info->stack_a_tail->prev->order == \
			info->next && info->stack_a_tail->order == info->next + 1)
	{
		info->stack_a_tail->prev->lot = -1;
		(info->next)++;
		sort_command(info, SA);
		if (info->stack_b_tail && info->stack_b_tail->order != info->next)
			sort_command(info, SB);
		sort_command(info, RA);
		if (info->stack_b_tail && info->stack_b_tail->order < \
				info->mid_order / 2)
			sort_command(info, RB);
		return (1);
	}
	else if (info->stack_a_tail && info->stack_a_tail->order == info->next)
	{
		(info->next)++;
		info->stack_a_tail->lot = -1;
		sort_command(info, RA);
		if (info->stack_b_tail && info->stack_b_tail->order < \
				info->mid_order / 2)
			sort_command(info, RB);
		return (1);
	}
	return (0);
}

int	check_top_3_side_b2(t_main *info)
{
	if (info->stack_b_tail && info->stack_b_tail->order == info->next)
	{
		(info->next)++;
		info->stack_b_tail->lot = -1;
		sort_command(info, PA);
		sort_command(info, RA);
		if (info->stack_b_tail && info->stack_b_tail->order < \
				info->mid_order / 2)
			sort_command(info, RB);
		return (1);
	}
	else if (info->stack_b_head && info->stack_b_head->order == info->next)
	{
		(info->next)++;
		info->stack_b_head->lot = -1;
		sort_command(info, RRB);
		sort_command(info, PA);
		sort_command(info, RA);
		if (info->stack_b_tail && info->stack_b_tail->order < \
				info->mid_order / 2)
			sort_command(info, RB);
		return (1);
	}
	return (0);
}

int	check_top_3_side_b1(t_main *info)
{
	if (info->stack_b_tail && info->stack_b_tail->prev && \
		info->stack_b_tail->prev->order == \
		info->next && info->stack_b_tail->order == info->next + 1)
	{
		info->stack_b_tail->prev->lot = -1;
		(info->next)++;
		sort_command(info, SB);
		if (info->stack_a_tail && info->stack_a_tail->prev && \
				info->stack_a_tail->order != info->next && \
				info->stack_a_tail->lot != -1 && info->stack_a_tail->lot == \
				info->stack_a_tail->prev->lot)
			sort_command(info, SA);
		sort_command(info, PA);
		sort_command(info, RA);
		if (info->stack_b_tail && info->stack_b_tail->order < \
				(info->mid_order / 2))
			sort_command(info, RB);
		return (1);
	}
	return (0);
}

int	check_top_3_side(t_main *info, int flag)
{
	if ((flag == 1 && info->stack_a_head == NULL) || (flag == 2 && \
				info->stack_b_head == NULL))
		return (0);
	if (flag == 1)
		return (check_top_3_side_a(info));
	if (flag == 2)
	{
		if (check_top_3_side_b1(info) == 1)
			return (1);
		else if (check_top_3_side_b2(info) == 1)
			return (1);
	}
	return (0);
}
