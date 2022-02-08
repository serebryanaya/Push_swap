/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 19:35:41 by pveeta            #+#    #+#             */
/*   Updated: 2021/09/12 19:36:34 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_main *info)
{
	t_list	*posthead;

	if (find_size_stack(info->stack_a_head) < 2)
		return ;
	posthead = info->stack_a_head->next;
	info->stack_a_head->prev = info->stack_a_tail;
	info->stack_a_tail->next = info->stack_a_head;
	info->stack_a_head->next = NULL;
	info->stack_a_tail = info->stack_a_head;
	posthead->prev = NULL;
	info->stack_a_head = posthead;
}

void	ft_rrb(t_main *info)
{
	t_list	*posthead;

	if (find_size_stack(info->stack_b_head) < 2)
		return ;
	posthead = info->stack_b_head->next;
	info->stack_b_head->prev = info->stack_b_tail;
	info->stack_b_tail->next = info->stack_b_head;
	info->stack_b_head->next = NULL;
	info->stack_b_tail = info->stack_b_head;
	posthead->prev = NULL;
	info->stack_b_head = posthead;
}

void	ft_rrr(t_main *info)
{
	ft_rra(info);
	ft_rrb(info);
}
