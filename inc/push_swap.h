/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 19:12:18 by pveeta            #+#    #+#             */
/*   Updated: 2021/09/18 20:12:06 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 1

typedef struct s_list
{
	int				value;
	int				order;
	int				lot;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef enum e_instruct
{
	NO,
	RA,
	RB,
	RR,
	PA,
	PB,
	RRA,
	RRB,
	RRR,
	SA,
	SB,
	SS
}	t_instruct;

typedef struct s_main
{
	t_list		*stack_a_head;
	t_list		*stack_b_head;
	t_list		*stack_a_tail;
	t_list		*stack_b_tail;
	int			mid_order;
	int			lots;
	int			next;
	int			flag_finish;
	t_instruct	command;
}	t_main;

typedef struct s_get_next_line
{
	int						fd;
	size_t					index;
	char					*memory;
	struct s_get_next_line	*next;
}			t_gnl;

int		ft_strlen(const char *s);
int		modif_atoi(char *s, int *sign, int i, unsigned int	number);

int		my_split(char *buf, char **line_or_mem);
int		check_in_memory(char **line, char **memory, size_t *index);
t_gnl	*list_check(int fd, t_gnl *list);
t_gnl	*create_list(int fd);
int		dellist(t_gnl **list, t_gnl **c_list);
int		clean(t_gnl **list, char **buf_or_line);
int		ft_read(char **line, t_gnl **list, t_gnl **first_list);
int		get_next_line(int fd, char **line);
void	ft_swap(int *a, int *b);
void	ft_putstr(char *str, int type_exit);
void	screen_command(t_instruct command);
int		first_check_arguments(char **argv, int flag, int counter);
int		is_int(char *argv, int flag);
int		check_argv(int *arguments, int *digit, char *argv);
char	**ft_split(char const *s, char c);
int		check_valid(int *digit, int j, int *arguments, char **split);
int		check_doubles(int c, int *array, int m);
int		sort_array(int counter, int *arguments);
void	add_order_in_list(int *arguments, t_list *list);
int		presort(int *arguments, int counter, int flag);
int		checker_begin(t_list *stack_a, int size_arr, int res);
int		sort_begin(t_list *stack_a, int size_arr);
void	half_to_b(t_main *info);
t_list	*init_stack_a(int *arguments, int counter);
t_list	*ft_lstnew_mod(int content);
void	ft_lstclear(t_list *list);
t_list	*ft_lstadd_front_mod(t_list *list, int argument);
t_main	*init_common_struct(t_list *stack_a, int size_arr);
int		check_max_value(int value, t_list *stack);
int		check_min_value(int value, t_list *stack);
t_list	*find_last(t_list *stack);
int		find_size_stack(t_list *stack);
int		check_finish(t_main *info);
void	sort_for_three_a(t_main *info);
void	sort_for_three_a_2(t_main *info, t_list *a, t_list *b, t_list *c);
void	sort_for_four_a(t_main *info);
int		sort_for_four_a2(t_list *a, t_list *b, t_list *d, t_main *info);
int		sort_for_four_a3(t_list *b, t_list *d, t_main *info);
int		mini_arr_check_sort(int value, t_list *head, t_list *tail);
int		mini_arr_check_sort2(t_list *copy, t_list *current, t_list *tail);
void	sort_for_five_a(t_main *info);
void	sort_for_five_a2(t_main *info);
int		check_top_3_side_a(t_main *info);
int		check_top_3_side_b2(t_main *info);
int		check_top_3_side_b1(t_main *info);
int		check_top_3_side(t_main *info, int flag);
void	big_sort(t_main *info);
void	get_lot_from_a(t_main *info);
void	get_from_b(t_main *info);
void	new_mediana_b(t_main *info, int counter);
void	work_0_lot(t_main *info);
int		max_ord_in_stack(t_list *stack);
int		min_ord_in_stack(t_list *stack);
int		size_lot(t_main *info);
int		find_min_in_lot(t_list *tail);
void	check_2_in_lot(t_main *info);
void	ft_sa(t_main *info);
void	ft_sa2(t_main *info, t_list *last, t_list *prelast);
void	ft_sb(t_main *info);
void	ft_sb2(t_main *info, t_list *last, t_list *prelast);
void	ft_ss(t_main *info);
void	ft_pa(t_main *info);
void	ft_pa2(t_main *info, t_list *last_b);
void	ft_pb(t_main *info);
void	ft_pb2(t_main *info, t_list *last_a);
void	ft_ra(t_main *info);
void	ft_rb(t_main *info);
void	ft_rr(t_main *info);
void	ft_rra(t_main *info);
void	ft_rrb(t_main *info);
void	ft_rrr(t_main *info);
void	sort_command(t_main *info, t_instruct new);
void	sort_command2(t_main *info, t_instruct new);
void	select_command(t_main *info, char *command);
void	fill_reverse(t_main *info, t_instruct new);
void	fill_rotate(t_main *info, t_instruct new);
void	fill_push(t_main *info, t_instruct new);
void	fill_swap(t_main *info, t_instruct new);

#endif
