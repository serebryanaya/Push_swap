/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 19:30:02 by pveeta            #+#    #+#             */
/*   Updated: 2021/09/12 19:30:53 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	counter;
	int	i;
	int	res;

	counter = 0;
	i = 1;
	res = 0;
	if (argc < 2)
		ft_putstr("No arguments", 0);
	while (argv[i])
	{
		if (is_int(argv[i], 0) == -1)
			ft_putstr("Error", -1);
		counter += is_int(argv[i++], 0);
	}
	res = first_check_arguments(argv, 2, counter);
	if (res == -1)
		ft_putstr("Error", -1);
	if (res == -2)
		ft_putstr("Error", -1);
	else if (res == 1)
		ft_putstr("OK", 1);
	else if (res == 0)
		ft_putstr("KO", 1);
	return (0);
}
