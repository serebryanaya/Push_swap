/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_argv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 20:34:31 by pveeta            #+#    #+#             */
/*   Updated: 2021/09/12 20:35:14 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_doubles(int c, int *array, int m)
{
	int	i;

	i = 0;
	while (i < m)
	{
		if (c == array[i])
			return (-1);
		i++;
	}
	return (i);
}

int	check_valid(int *digit, int j, int *arguments, char **split)
{
	int	tmp;
	int	m;
	int	flag;

	m = 0;
	flag = 0;
	while (m < j)
	{
		tmp = modif_atoi(split[m], &flag, 0, 0);
		free(split[m]);
		if (flag == -1 || check_doubles(tmp, arguments, *digit) < 0)
			return (-1);
		arguments[*digit] = tmp;
		(*digit)++;
		m++;
	}
	return (0);
}

int	sort_array(int counter, int *arguments)
{
	int	n;
	int	i;
	int	flag;

	n = 0;
	i = 1;
	flag = 0;
	while (n < counter - 1)
	{
		if (arguments[n] > arguments[n + i])
		{
			ft_swap(&arguments[n], &arguments[n + i]);
			flag = 1;
			n = 0;
		}
		else
			n++;
	}
	if (flag == 0)
		return (-1);
	return (0);
}

void	add_order_in_list(int *arguments, t_list *list)
{
	int		i;
	t_list	*copy;

	i = 0;
	copy = list;
	while (copy != NULL)
	{
		if (copy->value == arguments[i])
		{
			copy->order = i + 1;
			copy = copy->next;
			i = 0;
		}
		else
			i++;
	}
}
