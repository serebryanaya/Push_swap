/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 19:31:16 by pveeta            #+#    #+#             */
/*   Updated: 2021/09/16 12:49:16 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_int(char *argv, int flag)
{
	char	**str;
	int		j;
	int		i;

	j = 0;
	i = 0;
	if (ft_strlen(argv) == 0)
		return (-1);
	str = ft_split(argv, ' ');
	if (str[0] == 0)
	{
		free(str);
		return (-1);
	}
	while (str[j] && flag != -1)
		modif_atoi(str[j++], &flag, 0, 0);
	while (j - i >= 0)
	{
		free(str[j - i]);
		str[j - i++] = NULL;
	}
	if (flag == -1)
		j = -1;
	free(str);
	return (j);
}

int	check_argv(int *arguments, int *digit, char *argv)
{
	char	**split;
	int		j;

	split = ft_split(argv, ' ');
	j = 0;
	while (split[j])
		j++;
	if (check_valid(digit, j, arguments, split) == -1)
	{
		free(split);
		return (-1);
	}
	if (split)
		free(split);
	return (0);
}

int	first_check_arguments(char **argv, int flag, int counter)
{
	int	*arguments;
	int	i;
	int	digit;
	int	res;

	digit = 0;
	i = 1;
	arguments = malloc(sizeof(int) * counter);
	if (!arguments)
		return (-1);
	while (argv[i])
	{
		if (check_argv(arguments, &digit, argv[i++]) < 0)
		{
			free(arguments);
			arguments = NULL;
			return (-1);
		}
	}
	res = presort(arguments, counter, flag);
	if (arguments)
		free(arguments);
	return (res);
}
