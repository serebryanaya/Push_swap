/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 19:36:54 by pveeta            #+#    #+#             */
/*   Updated: 2021/09/12 19:37:47 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_main *info)
{
	t_list	*last;
	t_list	*prelast;
	t_list	*fix;

	if (find_size_stack(info->stack_a_head) < 2)
		return ;
	last = info->stack_a_tail;
	prelast = last->prev;
	if (find_size_stack(info->stack_a_head) == 2)
		info->stack_a_head = last;
	if (last->prev->prev != NULL)
	{
		fix = last->prev->prev;
		fix->next = last;
		last->prev = fix;
		last->next = prelast;
		prelast->next = NULL;
		prelast->prev = last;
		info->stack_a_tail = prelast;
		return ;
	}
	ft_sa2(info, last, prelast);
}

void	ft_sa2(t_main *info, t_list *last, t_list *prelast)
{
	last->next = prelast;
	prelast->next = NULL;
	prelast->prev = last;
	info->stack_a_tail = last;
	info->stack_a_tail = prelast;
	last->prev = NULL;
}

void	ft_sb(t_main *info)
{
	t_list	*last;
	t_list	*prelast;
	t_list	*fix;

	if (find_size_stack(info->stack_b_head) < 2)
		return ;
	last = info->stack_b_tail;
	prelast = last->prev;
	if (find_size_stack(info->stack_b_head) == 2)
		info->stack_b_head = last;
	if (last->prev->prev != NULL)
	{
		fix = last->prev->prev;
		fix->next = last;
		last->prev = fix;
		last->next = prelast;
		prelast->next = NULL;
		prelast->prev = last;
		info->stack_b_tail = prelast;
		return ;
	}
	ft_sb2(info, last, prelast);
}

void	ft_sb2(t_main *info, t_list *last, t_list *prelast)
{
	last->next = prelast;
	prelast->next = NULL;
	prelast->prev = last;
	info->stack_b_tail = last;
	info->stack_b_tail = prelast;
	last->prev = NULL;
}

void	ft_ss(t_main *info)
{
	ft_sa(info);
	ft_sb(info);
}
