/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 23:13:02 by druth             #+#    #+#             */
/*   Updated: 2022/03/23 23:13:04 by druth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_down_search(t_num *head, int num, int size)
{
	t_num	*temp;
	int		track;

	if (head->num < num)
		return (0);
	temp = head;
	track = 0;
	while (track < size)
	{
		if (temp->num < num)
			return (track);
		temp = temp->next;
		track++;
	}
	return (-1);
}

int	ft_order(t_num **head, t_num **tail, t_num *new, int size)
{
	int	move;

	if (new == NULL)
		return (-1);
	move = ft_down_search(*head, new->num, size);
	if (move != -1)
	{
		while (move > 0)
		{
			ft_rotate_up(head, tail);
			move--;
		}
		ft_stack_front(head, new);
	}
	else
	{
		while ((*tail)->num < new->num)
			ft_rotate_down(head, tail);
		ft_stack_back(tail, new);
	}
	return (1);
}

int	ft_down_find(t_num *head, int find, int size)
{
	t_num	*temp;
	int		track;

	temp = head;
	track = 0;
	while (track <= size && temp->num != find)
	{
		temp = temp->next;
		track++;
	}
	if (track <= size)
		return (track);
	return (-1);
}

void	ft_final_sort(t_num **head, t_num **tail, int max, int size)
{
	int	down;

	down = ft_down_find(*head, max, size);
	if (down != -1)
	{
		while ((*head)->num != max)
			ft_rotate_up(head, tail);
	}
	else
	{
		while ((*head)->num != max)
			ft_rotate_down(head, tail);
	}
}

int	ft_sort(t_stack *numbers)
{
	t_num	*tracker;
	int		max;
	int		track;

	ft_initialize_stack(numbers, ft_num_new(numbers->head_a->num), 's');
	tracker = numbers->head_a->next;
	max = numbers->head_a->num;
	track = 0;
	while (tracker != NULL)
	{
		if (ft_order(&numbers->head_sort, &numbers->tail_sort,
				ft_num_new(tracker->num), (track / 2)) == -1)
			return (-1);
		if (tracker->num > max)
			max = tracker->num;
		ft_final_sort(&numbers->head_sort,
			&numbers->tail_sort, max, (track / 2));
		tracker = tracker->next;
		track++;
	}
	return (1);
}
