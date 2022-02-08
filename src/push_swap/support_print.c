/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 20:25:52 by pveeta            #+#    #+#             */
/*   Updated: 2021/09/12 20:27:02 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	screen_command(t_instruct command)
{
	if (command == RRA)
		write(1, "rra\n", 4);
	if (command == RRB)
		write(1, "rrb\n", 4);
	if (command == RRR)
		write(1, "rrr\n", 4);
	if (command == RA)
		write(1, "ra\n", 3);
	if (command == RB)
		write(1, "rb\n", 3);
	if (command == RR)
		write(1, "rr\n", 3);
	if (command == SA)
		write(1, "sa\n", 3);
	if (command == SB)
		write(1, "sb\n", 3);
	if (command == SS)
		write(1, "ss\n", 3);
	if (command == PA)
		write(1, "pa\n", 3);
	if (command == PB)
		write(1, "pb\n", 3);
}

void	ft_putstr(char *str, int type_exit)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (write(1, &str[i], 1) > 0)
			i++;
	}
	if (write(1, "\n", 1) > 0)
		exit(type_exit);
}
