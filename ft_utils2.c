/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 23:13:19 by druth             #+#    #+#             */
/*   Updated: 2022/03/23 23:13:21 by druth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_error(int *error)
{
	write(2, "Error\n", 6);
	*error = -1;
	return (-1);
}

void	ft_push(t_num **head_target, t_num **head_bullet)
{
	t_num	*temp;

	temp = (*head_bullet)->next;
	ft_stack_front(head_target, *head_bullet);
	if (temp != NULL)
		temp->previous = NULL;
	*head_bullet = temp;
}

void	ft_rotate_down(t_num **head, t_num **tail)
{
	t_num	*bottom;

	bottom = (*tail)->previous;
	(*tail)->next = *head;
	(*tail)->previous = NULL;
	(*head)->previous = *tail;
	*head = *tail;
	bottom->next = NULL;
	*tail = bottom;
}

void	ft_rotate_up(t_num **head, t_num **tail)
{
	t_num	*top;

	top = (*head)->next;
	(*head)->next = NULL;
	(*head)->previous = *tail;
	(*tail)->next = *head;
	*tail = *head;
	top->previous = NULL;
	*head = top;
}

int	ft_finder(t_num *tail, int num)
{
	while (tail->previous != NULL && num > 1)
	{
		tail = tail->previous;
		num--;
	}
	return (tail->num);
}
