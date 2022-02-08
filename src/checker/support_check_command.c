/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_check_command.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 20:33:16 by pveeta            #+#    #+#             */
/*   Updated: 2021/09/12 20:34:21 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_command(t_main *info, t_instruct new)
{
	if (info->command == NO)
	{
		info->command = new;
		if (new == RRA)
			ft_rra(info);
		if (new == RRB)
			ft_rrb(info);
		if (new == RA)
			ft_ra(info);
		if (new == RB)
			ft_rb(info);
		if (new == SA)
			ft_sa(info);
		if (new == SB)
			ft_sb(info);
		if (new == PA)
			ft_pa(info);
		if (new == PB)
			ft_pb(info);
	}
	else
		sort_command2(info, new);
}

void	sort_command2(t_main *info, t_instruct new)
{
	if (new == RRA || new == RRB)
		fill_reverse(info, new);
	else if (new == RA || new == RB)
		fill_rotate(info, new);
	else if (new == SA || new == SB)
		fill_swap(info, new);
	else if (new == PA || new == PB)
		fill_push(info, new);
}

void	select_command2(t_main *info, char *command)
{
	if (command[0] == 'r' && command[1] == 'r' \
	&& command[2] == 0)
		ft_rr(info);
	else if (command[0] == 'r' && command[1] == 'r' \
	&& command[2] == 'a' && command[3] == 0)
		ft_rra(info);
	else if (command[0] == 'r' && command[1] == 'r' \
	&& command[2] == 'b' && command[3] == 0)
		ft_rrb(info);
	else if (command[0] == 'r' && command[1] == 'r' \
	&& command[2] == 'r' && command[3] == 0)
		ft_rrr(info);
	else
		ft_putstr("Error", 1);
}

void	select_command(t_main *info, char *command)
{
	if (command[0] == 's' && command[1] == 'a' \
	&& command[2] == 0)
		ft_sa(info);
	else if (command[0] == 's' && command[1] == 'b' \
	&& command[2] == 0)
		ft_sb(info);
	else if (command[0] == 's' && command[1] == 's' \
	&& command[2] == 0)
		ft_ss(info);
	else if (command[0] == 'p' && command[1] == 'a' \
	&& command[2] == 0)
		ft_pa(info);
	else if (command[0] == 'p' && command[1] == 'b' \
	&& command[2] == 0)
		ft_pb(info);
	else if (command[0] == 'r' && command[1] == 'a' \
	&& command[2] == 0)
		ft_ra(info);
	else if (command[0] == 'r' && command[1] == 'b' \
	&& command[2] == 0)
		ft_rb(info);
	else
		select_command2(info, command);
}
