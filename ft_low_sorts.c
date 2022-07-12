/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_low_sorts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 23:12:15 by druth             #+#    #+#             */
/*   Updated: 2022/03/23 23:12:16 by druth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

void	ft_2_sort(t_num **head, t_num **second, char type)
{
	if ((*head)->num < (*second)->num)
		return ;
	ft_swap(head);
	if (type == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

void	ft_3_more(t_stack *numbers, t_num *second, t_num *third)
{
	if (numbers->head_a->num > second->num && second->num > third->num)
	{
		ft_swap(&numbers->head_a);
		ft_rotate_down(&numbers->head_a, &numbers->tail_a);
		write(1, "sa\nrra\n", 7);
	}
	else if (numbers->head_a->num > third->num && third->num > second->num)
	{
		ft_rotate_up(&numbers->head_a, &numbers->tail_a);
		write(1, "ra\n", 3);
	}
}

void	ft_3_sort(t_stack *numbers)
{
	t_num	*second;
	t_num	*third;

	second = numbers->head_a->next;
	third = second->next;
	if (second->num > third->num && third->num > numbers->head_a->num)
	{
		ft_swap(&numbers->head_a);
		ft_rotate_up(&numbers->head_a, &numbers->tail_a);
		write(1, "sa\nra\n", 6);
	}
	else if (numbers->head_a->num > second->num
		&& third->num > numbers->head_a->num)
	{
		ft_swap(&numbers->head_a);
		write(1, "sa\n", 3);
	}
	else if (numbers->head_a->num < second->num
		&& numbers->head_a->num > third->num)
	{
		ft_rotate_down(&numbers->head_a, &numbers->tail_a);
		write(1, "rra\n", 4);
	}
	ft_3_more(numbers, second, third);
}

void	ft_4_sort(t_stack *numbers)
{
	ft_init_b(numbers, numbers->head_a->num, 0);
	ft_3_sort(numbers);
	ft_add_sort(numbers, 1, numbers->head_b->num == numbers->head_sort->num);
}

void	ft_5_sort(t_stack *numbers)
{
	ft_init_b(numbers, numbers->head_a->num, 0);
	ft_push(&numbers->head_b, &numbers->head_a);
	write(1, "pb\n", 3);
	ft_3_sort(numbers);
	ft_add_sort(numbers, 2, numbers->head_b->num == numbers->head_sort->num);
	ft_add_sort(numbers, 1, numbers->head_b->num == numbers->head_sort->num);
}
