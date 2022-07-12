/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:29:55 by druth             #+#    #+#             */
/*   Updated: 2022/03/31 21:29:55 by druth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_num
{
	int		num;
	void	*next;
	void	*previous;
}	t_num;

typedef struct s_stack
{
	t_num	*head_a;
	t_num	*tail_a;
	t_num	*head_b;
	t_num	*tail_b;
	t_num	*head_sort;
	t_num	*tail_sort;
	int		size_a;
	int		size_b;
	int		size_max;
	int		chunk_num;
}	t_stack;

t_num	*ft_num_new(int content);
int		ft_stack_clear(t_num **head);
int		ft_stack_back(t_num **tail, t_num *new);
void	ft_stack_front(t_num **head, t_num *new);
void	ft_swap(t_num **head);
void	ft_push(t_num **head_target, t_num **head_bullet);
void	ft_rotate_down(t_num **head, t_num **tail);
void	ft_rotate_up(t_num **head, t_num **tail);
int		ft_error(int *error);
int		ft_strlen(char *str);
int		ft_limit(char *av, int *error, int track, int flag);
int		ft_atoi(char *av, int *error);
int		ft_initialize_stack(t_stack *numbers, t_num *first, char stack);
int		ft_double_check(t_num *head, int check);
int		ft_assign(t_stack *numbers, char **av, int error, int max);
int		ft_down_search(t_num *head, int num, int size);
int		ft_order(t_num **head, t_num **tail, t_num *new, int size);
int		ft_down_find(t_num *head, int find, int size);
void	ft_final_sort(t_num **head, t_num **tail, int max, int size);
void	ft_printer(t_stack *numbers, int size);
int		ft_sort(t_stack *numbers);
int		ft_chunky(t_stack *numbers);
void	ft_null_assign(t_stack *numbers);
int		ft_finder(t_num *head, int num);
int		ft_downer(t_num *head, t_num *tail, int max, int size);
void	ft_push_a_down(t_stack *numbers, int max);
void	ft_push_a_up(t_stack *numbers, int search);
void	ft_init_b(t_stack *numbers, int max, int search);
int		ft_start(t_stack *numbers, int max, int track, int count);
void	ft_start_loop(t_stack *numbers, int max, int track, int count);
int		ft_downer_f(t_num *head, t_num *tail, int max, int size);
void	ft_push_b_down(t_stack *numbers, int max);
void	ft_push_b_up(t_stack *numbers, int max, int search);
void	ft_init_a(t_stack *numbers, int max, int search);
int		ft_finish(t_stack *numbers);
void	ft_2_sort(t_num **head, t_num **second, char type);
void	ft_3_sort(t_stack *numbers);
void	ft_3_more(t_stack *numbers, t_num *second, t_num *third);
void	ft_4_sort(t_stack *numbers);
void	ft_5_sort(t_stack *numbers);
void	ft_add_sort(t_stack *numbers, int num, int max);
void	ft_finding(t_stack *numbers, t_num *find);
void	ft_check(t_stack *numbers, t_num **current);
void	ft_choose_sort(t_stack *numbers);
void	ft_free(t_stack *numbers);

void	ft_ko_ok(t_stack *numbers, int behind);
char	ft_strcmp(char *command, char *check);
int		ft_compare(t_stack *numbers, char *command, int *track);
void	ft_bonus_loop(t_stack *numbers, int track, int input);
int		ft_command_pb(t_stack *numbers, int *track);
int		ft_command_pa(t_stack *numbers, int *track);
int		ft_command_sss(t_stack *numbers, char *command, int *track);
int		ft_command_r(t_stack *numbers, char *command, int *track);
int		ft_command_r_r(t_stack *numbers, char *command, int *track);

#endif
