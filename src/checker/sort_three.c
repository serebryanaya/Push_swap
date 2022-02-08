/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 19:38:31 by pveeta            #+#    #+#             */
/*   Updated: 2021/09/12 19:41:15 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_for_three_a(t_main *info)
{
	t_list	*a;
	t_list	*c;

	c = info->stack_a_head;
	a = info->stack_a_tail;
	if ((check_min_value(a->value, info->stack_a_head) == 1 && \
		 check_max_value(c->value, info->stack_a_head) == 1) || \
			find_size_stack(info->stack_a_head) != 3)
		return ;
	else if (check_max_value(a->value, info->stack_a_head) == 1 && \
			 check_min_value(c->value, info->stack_a_head) == 1)
	{
		sort_command(info, SA);
		sort_command(info, RRA);
	}
	else
		sort_for_three_a_2(info, info->stack_a_tail, \
				info->stack_a_tail->prev, info->stack_a_head);
}

void	sort_for_three_a_2(t_main *info, t_list *a, t_list *b, t_list *c)
{
	if (check_max_value(b->value, info->stack_a_head) == 1 && \
		check_min_value(a->value, info->stack_a_head) == 1)
	{
		sort_command(info, RRA);
		sort_command(info, SA);
	}
	else if (check_max_value(c->value, info->stack_a_head) == 1 && \
			 check_min_value(b->value, info->stack_a_head) == 1)
		sort_command(info, SA);
	else if (check_max_value(a->value, info->stack_a_head) == 1 && \
			 check_min_value(b->value, info->stack_a_head) == 1)
		sort_command(info, RA);
	else if (check_max_value(b->value, info->stack_a_head) == 1 && \
			 check_min_value(c->value, info->stack_a_head) == 1)
		sort_command(info, RRA);
}
