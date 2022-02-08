/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort_and_checker.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 20:10:52 by pveeta            #+#    #+#             */
/*   Updated: 2021/09/18 20:11:11 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	presort(int *arguments, int counter, int flag)
{
	t_list	*stack_a;
	int		res;

	stack_a = init_stack_a(arguments, counter);
	if (sort_array(counter, arguments) < 0 && flag == 1)
	{
		ft_lstclear(stack_a);
		return (0);
	}
	add_order_in_list(arguments, stack_a);
	res = sort_begin(stack_a, counter);
	return (res);
}

void	half_to_b(t_main *info)
{
	int	counter;

	info->mid_order = (max_ord_in_stack(info->stack_a_head) / 2 + 1);
	counter = info->mid_order;
	while (info->stack_a_head->order <= info->mid_order && \
		   info->stack_a_head->order < 2)
	{
		sort_command(info, RRA);
		sort_command(info, PB);
		counter--;
	}
	while (counter > 0)
	{
		if (info->stack_a_tail->order > info->mid_order)
		{
			sort_command(info, RA);
			if (find_size_stack(info->stack_b_head) > 1 && \
				info->stack_b_tail->order < (info->mid_order / 2 + 1))
				sort_command(info, RB);
		}
		else if (counter-- > 0)
			sort_command(info, PB);
	}
}

int	sort_begin(t_list *stack_a, int size_arr)
{
	t_main	*info;

	info = init_common_struct(stack_a, size_arr);
	if (size_arr == 2)
		sort_command(info, SA);
	else if (size_arr == 3)
		sort_for_three_a(info);
	else if (size_arr == 4)
		sort_for_four_a(info);
	else if (size_arr == 5)
		sort_for_five_a(info);
	else
	{
		half_to_b(info);
		big_sort(info);
	}
	screen_command(info->command);
	if (info->stack_a_head)
		ft_lstclear(info->stack_a_head);
	if (info->stack_b_head)
		ft_lstclear(info->stack_b_head);
	if (info)
		free(info);
	return (1);
}
