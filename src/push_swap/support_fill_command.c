/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_fill_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 20:32:36 by pveeta            #+#    #+#             */
/*   Updated: 2021/09/12 20:33:09 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_reverse(t_main *info, t_instruct new)
{
	if (new == RRA)
	{
		ft_rra(info);
		if (info->command != RRB)
		{
			screen_command(info->command);
			info->command = RRA;
		}
		else
			info->command = RRR;
		return ;
	}
	ft_rrb(info);
	if (info->command != RRA)
	{
		screen_command(info->command);
		info->command = RRB;
	}
	else
		info->command = RRR;
}

void	fill_rotate(t_main *info, t_instruct new)
{
	if (new == RA)
	{
		ft_ra(info);
		if (info->command != RB)
		{
			screen_command(info->command);
			info->command = RA;
		}
		else
			info->command = RR;
		return ;
	}
	ft_rb(info);
	if (info->command != RA)
	{
		screen_command(info->command);
		info->command = RB;
	}
	else
		info->command = RR;
}

void	fill_push(t_main *info, t_instruct new)
{
	if (new == PA)
	{
		ft_pa(info);
		if (info->command != PB)
		{
			screen_command(info->command);
			info->command = PA;
		}
		else
			info->command = NO;
		return ;
	}
	ft_pb(info);
	if (info->command != PA)
	{
		screen_command(info->command);
		info->command = PB;
	}
	else
		info->command = NO;
}

void	fill_swap(t_main *info, t_instruct new)
{
	if (new == SA)
	{
		ft_sa(info);
		if (info->command != SB)
		{
			screen_command(info->command);
			info->command = SA;
		}
		else
			info->command = SS;
		return ;
	}
	ft_sb(info);
	if (info->command != SA)
	{
		screen_command(info->command);
		info->command = SB;
	}
	else
		info->command = SS;
}
