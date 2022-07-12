/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b_2_a_finish.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 23:08:58 by druth             #+#    #+#             */
/*   Updated: 2022/03/23 23:09:02 by druth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_downer_f(t_num *head, t_num *tail, int max, int size)
{
	int		down;
	int		up;

	if (head->num == max)
		return (0);
	down = 1;
	head = head->next;
	while (head != NULL && down <= size)
	{
		if (head->num == max)
			break ;
		down++;
		head = head->next;
	}
	up = 1;
	while (tail != NULL && up < down)
	{
		if (tail->num == max)
			return (-1);
		up++;
		tail = tail->previous;
	}
	return (down);
}

void	ft_push_b_down(t_stack *numbers, int max)
{
	while (numbers->head_b->num != max)
	{
		ft_rotate_down(&numbers->head_b, &numbers->tail_b);
		write(1, "rrb\n", 4);
	}
	ft_push(&numbers->head_a, &numbers->head_b);
	write(1, "pa\n", 3);
}

void	ft_push_b_up(t_stack *numbers, int max, int search)
{
	if (search > 0)
		search = 0;
	while (numbers->head_b->num != max)
	{
		ft_rotate_up(&numbers->head_b, &numbers->tail_b);
		write(1, "rb\n", 3);
	}
	ft_push(&numbers->head_a, &numbers->head_b);
	write(1, "pa\n", 3);
}

void	ft_init_a(t_stack *numbers, int max, int search)
{
	t_num	*temp;

	if (search >= 0)
	{
		while (numbers->head_b->num != max)
		{
			ft_rotate_up(&numbers->head_b, &numbers->tail_b);
			write(1, "rb\n", 3);
		}
	}
	else
	{
		while (numbers->head_b->num != max)
		{
			ft_rotate_down(&numbers->head_b, &numbers->tail_b);
			write(1, "rrb\n", 4);
		}
	}
	temp = numbers->head_b->next;
	temp->previous = NULL;
	ft_initialize_stack(numbers, numbers->head_b, 'a');
	write(1, "pa\n", 3);
	numbers->head_b = temp;
	numbers->size_b--;
}

int	ft_finish(t_stack *numbers)
{
	t_num	*max;
	int		search;

	max = numbers->head_sort;
	search = ft_downer_f(numbers->head_b, numbers->tail_b,
			max->num, numbers->size_b / 2);
	ft_init_a(numbers, max->num, search);
	while (numbers->size_b >= 1)
	{
		max = max->next;
		search = ft_downer_f(numbers->head_b, numbers->tail_b,
				max->num, numbers->size_b / 2);
		if (search >= 0)
			ft_push_b_up(numbers, max->num, search);
		else
			ft_push_b_down(numbers, max->num);
		numbers->size_b--;
		numbers->size_a++;
	}
	ft_stack_front(&numbers->head_a, numbers->head_b);
	write(1, "pa\n", 3);
	numbers->head_b = NULL;
	numbers->tail_b = NULL;
	return (1);
}
