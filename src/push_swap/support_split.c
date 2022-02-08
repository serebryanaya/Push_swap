/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 20:14:09 by pveeta            #+#    #+#             */
/*   Updated: 2021/09/12 20:22:49 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_words(char const	*s, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

void	*malloc_error(char **arr, int i)
{
	int	m;

	m = 0;
	while (m < i)
	{
		free(arr[m]);
		m++;
	}
	free (arr);
	ft_putstr("Error", -1);
	return (NULL);
}

int	find_char(char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

char	**in_array(char **arr, char const *s, int words)
{
	int		len;
	int		i;
	int		j;

	i = -1;
	while (++i < words)
	{
		while (*s == ' ')
			s++;
		len = find_char(s, ' ');
		arr[i] = malloc(sizeof(char) * (len + 1));
		if (!arr[i])
			return (malloc_error(arr, i));
		j = 0;
		while (j < len)
		{
			arr[i][j] = *s;
			j++;
			s++;
		}
		arr[i][j] = '\0';
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		words;

	if (!s)
		return (NULL);
	words = find_words(s, c);
	arr = malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	arr = in_array(arr, s, words);
	return (arr);
}
