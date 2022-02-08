/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_standart.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 20:12:54 by pveeta            #+#    #+#             */
/*   Updated: 2021/09/18 20:09:41 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	modif_atoi(char *s, int *flag, int i, unsigned int	number)
{
	int				sign;

	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-')
		sign = -1;
	else
		sign = 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i] != 0 && *flag != -1)
	{
		if (s[i] < '0' || s[i] > '9')
			ft_putstr("Error", -1);
		while (s[i] >= '0' && s[i] <= '9' && *flag != -1)
		{
			number = 10 * number + (s[i++] - '0');
			if ((number > 2147483647 && sign == 1) || (number > 2147483648 && \
	sign == -1))
				*flag = -1;
		}
	}
	return (sign * number);
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
