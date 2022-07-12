/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_low_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 23:12:32 by druth             #+#    #+#             */
/*   Updated: 2022/03/23 23:12:32 by druth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_finding(t_stack *numbers, t_num *find)
{
	int	finder;

	finder = ft_downer_f(numbers->head_a, numbers->tail_a,
			find->num, numbers->size_a / 2);
	if (finder >= 0)
	{
		while (numbers->head_a->num != find->num)
		{
			ft_rotate_up(&numbers->head_a, &numbers->tail_a);
			write(1, "ra\n", 3);
		}
	}
	else
	{
		while (numbers->head_a->num != find->num)
		{
			ft_rotate_down(&numbers->head_a, &numbers->tail_a);
			write(1, "rra\n", 4);
		}
	}
}

void	ft_check(t_stack *numbers, t_num **current)
{
	t_num	*head;

	head = numbers->head_a;
	while (head != NULL && head->num < (*current)->num)
		head = head->next;
	if (head == NULL)
		*current = numbers->head_a;
	else
		*current = head;
}

void	ft_add_sort(t_stack *numbers, int num, int max)
{
	t_num	*temp;

	temp = numbers->tail_sort;
	while (temp != NULL && temp->num != numbers->head_b->num)
		temp = temp->previous;
	if (max == 0)
		temp = temp->previous;
	else
		temp = numbers->tail_sort;
	if (num == 2)
		ft_check(numbers, &temp);
	ft_finding(numbers, temp);
	ft_stack_front(&numbers->head_a, numbers->head_b);
	write(1, "pa\n", 3);
	if (num == 1)
	{
		numbers->head_b = NULL;
		numbers->tail_b = NULL;
	}
	else if (num == 2)
		numbers->head_b = numbers->tail_b;
	if (num == 1)
		ft_finding(numbers, numbers->tail_sort);
}
