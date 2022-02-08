/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 19:33:25 by pveeta            #+#    #+#             */
/*   Updated: 2021/09/12 19:34:31 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_main *info)
{
	t_list	*last_b;

	if (find_size_stack(info->stack_b_head) < 1)
		return ;
	last_b = info->stack_b_tail;
	if (last_b->prev)
	{
		info->stack_b_tail = last_b->prev;
		last_b->prev->next = NULL;
	}
	else
	{
		info->stack_b_head = NULL;
		info->stack_b_tail = NULL;
	}
	ft_pa2(info, last_b);
}

void	ft_pa2(t_main *info, t_list *last_b)
{
	if (info->stack_a_head != NULL)
	{
		last_b->prev = info->stack_a_tail;
		info->stack_a_tail->next = last_b;
		info->stack_a_tail = info->stack_a_tail->next;
	}
	else
	{
		info->stack_a_head = last_b;
		info->stack_a_tail = last_b;
		last_b->prev = NULL;
	}
}

void	ft_pb(t_main *info)
{
	t_list	*last_a;

	if (find_size_stack(info->stack_a_head) < 1)
		return ;
	last_a = info->stack_a_tail;
	if (last_a->prev != NULL)
	{
		info->stack_a_tail = last_a->prev;
		last_a->prev->next = NULL;
	}
	else
	{
		info->stack_a_head = NULL;
		info->stack_a_tail = NULL;
	}
	ft_pb2(info, last_a);
}

void	ft_pb2(t_main *info, t_list *last_a)
{
	if (info->stack_b_head != NULL)
	{
		last_a->prev = info->stack_b_tail;
		info->stack_b_tail->next = last_a;
		info->stack_b_tail = last_a;
	}
	else
	{
		info->stack_b_head = last_a;
		info->stack_b_tail = last_a;
		last_a->prev = NULL;
	}
}
