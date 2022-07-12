/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 23:13:14 by druth             #+#    #+#             */
/*   Updated: 2022/03/23 23:13:14 by druth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_num	*ft_num_new(int content)
{
	t_num	*output;

	output = (t_num *)malloc(sizeof(t_num));
	if (output == NULL)
		return (NULL);
	output->num = content;
	output->next = NULL;
	output->previous = NULL;
	return (output);
}

int	ft_stack_clear(t_num **head)
{
	t_num	*tmp;

	if (!head || !*head)
		return (-1);
	while (head && *head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
	return (-1);
}

int	ft_stack_back(t_num **tail, t_num *new)
{
	if (new == NULL)
		return (-1);
	if (tail != NULL)
	{
		if (*tail != NULL)
		{
			(*tail)->next = new;
			new->previous = *tail;
		}
		*tail = new;
	}
	return (1);
}

void	ft_stack_front(t_num **head, t_num *new)
{
	if (head != NULL)
	{
		if (*head != NULL)
		{
			new->next = *head;
			(*head)->previous = new;
		}
		*head = new;
	}
}

void	ft_swap(t_num **head)
{
	t_num	*second;
	t_num	*third;

	if ((*head)->next != NULL)
	{
		second = (*head)->next;
		if (second->next != NULL)
		{
			third = second->next;
			third->previous = *head;
		}
		(*head)->next = second->next;
		(*head)->previous = second;
		second->previous = NULL;
		second->next = *head;
		*head = second;
	}
}
