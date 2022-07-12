/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_a_2_b_start.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 23:08:38 by druth             #+#    #+#             */
/*   Updated: 2022/03/23 23:08:40 by druth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_downer(t_num *head, t_num *tail, int max, int size)
{
	int		down;
	int		up;

	if (head->num <= max)
		return (0);
	down = 1;
	head = head->next;
	while (head != NULL && down <= size)
	{
		if (head->num <= max)
			break ;
		down++;
		head = head->next;
	}
	up = 1;
	while (tail != NULL && up < down)
	{
		if (tail->num <= max)
			return (-1);
		up++;
		tail = tail->previous;
	}
	return (down);
}

void	ft_push_a_down(t_stack *numbers, int max)
{
	while (numbers->head_a->num > max)
	{
		ft_rotate_down(&numbers->head_a, &numbers->tail_a);
		write(1, "rra\n", 4);
	}
	ft_push(&numbers->head_b, &numbers->head_a);
	write(1, "pb\n", 3);
}

void	ft_push_a_up(t_stack *numbers, int max)
{
	while (numbers->head_a->num > max)
	{
		ft_rotate_up(&numbers->head_a, &numbers->tail_a);
		write(1, "ra\n", 3);
	}
	ft_push(&numbers->head_b, &numbers->head_a);
	write(1, "pb\n", 3);
}

void	ft_init_b(t_stack *numbers, int max, int search)
{
	t_num	*temp;

	while (search > 0)
	{
		ft_rotate_up(&numbers->head_a, &numbers->tail_a);
		write(1, "ra\n", 3);
		search--;
	}
	while (numbers->head_a->num != max)
	{
		ft_rotate_down(&numbers->head_a, &numbers->tail_a);
		write(1, "rra\n", 4);
	}
	temp = numbers->head_a->next;
	temp->previous = NULL;
	ft_initialize_stack(numbers, numbers->head_a, 'b');
	write(1, "pb\n", 3);
	numbers->head_a = temp;
	numbers->size_a--;
}

int	ft_start(t_stack *numbers, int max, int track, int count)
{
	int		search;

	max = ft_finder(numbers->tail_sort, numbers->chunk_num);
	search = ft_downer(numbers->head_a, numbers->tail_a,
			max, numbers->size_a / 2);
	ft_init_b(numbers, max, search);
	ft_start_loop(numbers, max, track, count);
	ft_stack_front(&numbers->head_b, numbers->head_a);
	write(1, "pb\n", 3);
	numbers->head_a = NULL;
	numbers->tail_a = NULL;
	return (1);
}
