/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 19:34:51 by pveeta            #+#    #+#             */
/*   Updated: 2021/09/12 19:35:25 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_main *info)
{
	t_list	*copy;
	t_list	*prelast;

	if (find_size_stack(info->stack_a_head) < 2)
		return ;
	copy = info->stack_a_tail;
	info->stack_a_tail = info->stack_a_tail->prev;
	prelast = copy->prev;
	info->stack_a_head->prev = copy;
	copy->prev = NULL;
	prelast->next = NULL;
	copy->next = info->stack_a_head;
	info->stack_a_head = copy;
}

void	ft_rb(t_main *info)
{
	t_list	*copy;
	t_list	*prelast;

	if (find_size_stack(info->stack_b_head) < 2)
		return ;
	copy = info->stack_b_tail;
	info->stack_b_tail = info->stack_b_tail->prev;
	prelast = copy->prev;
	info->stack_b_head->prev = copy;
	copy->prev = NULL;
	if (prelast)
		prelast->next = NULL;
	copy->next = info->stack_b_head;
	info->stack_b_head = copy;
}

void	ft_rr(t_main *info)
{
	ft_ra(info);
	ft_rb(info);
}
