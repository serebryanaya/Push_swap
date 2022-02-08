/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_init_add_del_list.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 20:30:59 by pveeta            #+#    #+#             */
/*   Updated: 2021/09/13 21:09:56 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*init_stack_a(int *arguments, int counter)
{
	t_list	*list;
	int		i;

	i = 1;
	list = ft_lstnew_mod(arguments[0]);
	if (!list)
	{
		if (arguments)
			free(arguments);
		ft_putstr("Error", -1);
	}
	while (i < counter)
	{
		list = ft_lstadd_front_mod(list, arguments[i]);
		if (list == NULL)
		{
			if (arguments)
				free(arguments);
			ft_lstclear(list);
			ft_putstr("Error", -1);
		}
		i++;
	}
	return (list);
}

t_list	*ft_lstnew_mod(int content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->value = content;
	list->order = -1;
	list->next = NULL;
	list->prev = NULL;
	list->lot = 0;
	return (list);
}

void	ft_lstclear(t_list *list)
{
	t_list	*copy;

	if (list == NULL)
		return ;
	while (list->next != NULL)
	{
		copy = list;
		list = list->next;
		list->prev = NULL;
		free(copy);
		copy = NULL;
	}
	if (list)
	{
		free (list);
		list = NULL;
	}
}

t_list	*ft_lstadd_front_mod(t_list *list, int argument)
{
	t_list	*copy;
	t_list	*new;

	new = ft_lstnew_mod(argument);
	if (!new)
		return (NULL);
	copy = list;
	new->next = copy;
	copy->prev = new;
	list = new;
	return (list);
}

t_main	*init_common_struct(t_list *stack_a, int size_arr)
{
	t_main	*info;
	t_list	*stack_b;

	stack_b = NULL;
	info = malloc(sizeof(t_main));
	if (!info)
		ft_putstr("Error", -1);
	info->stack_a_head = stack_a;
	info->stack_b_head = stack_b;
	info->stack_a_tail = find_last(stack_a);
	info->stack_b_tail = find_last(stack_b);
	info->next = 1;
	info->mid_order = (size_arr / 2) + 2;
	info->lots = 0;
	info->flag_finish = 0;
	info->command = NO;
	return (info);
}
