/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:22:51 by druth             #+#    #+#             */
/*   Updated: 2022/03/31 21:22:52 by druth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_bonus.h"

int	ft_command_pb(t_stack *numbers, int *track)
{
	t_num	*temp;

	*track = -1;
	if (numbers->head_a == NULL)
		return (1);
	if (numbers->head_b == NULL)
	{
		temp = numbers->head_a->next;
		if (temp != NULL)
			temp->previous = NULL;
		ft_initialize_stack(numbers, numbers->head_a, 'b');
		numbers->head_a = temp;
	}
	else
	{
		ft_push(&numbers->head_b, &numbers->head_a);
		numbers->size_b++;
	}
	numbers->size_a--;
	if (numbers->size_a == 0)
	{
		numbers->head_a = NULL;
		numbers->tail_a = NULL;
	}
	return (1);
}

int	ft_command_pa(t_stack *numbers, int *track)
{
	t_num	*temp;

	*track = -1;
	if (numbers->head_b == NULL)
		return (1);
	if (numbers->head_a == NULL)
	{
		temp = numbers->head_b->next;
		if (temp != NULL)
			temp->previous = NULL;
		ft_initialize_stack(numbers, numbers->head_b, 'a');
		numbers->head_b = temp;
	}
	else
	{
		ft_push(&numbers->head_a, &numbers->head_b);
		numbers->size_a++;
	}
	numbers->size_b--;
	if (numbers->size_b == 0)
	{
		numbers->head_b = NULL;
		numbers->tail_b = NULL;
	}
	return (1);
}

int	ft_command_sss(t_stack *numbers, char *command, int *track)
{
	if (ft_strcmp(command, "ss") == 'y')
		*track = -1;
	if (ft_strcmp(command, "sa") == 'y' || *track == -1)
	{
		if (numbers->head_a != NULL && numbers->head_a->next != NULL)
			ft_swap(&numbers->head_a);
		if (*track != -1)
		{
			*track = -1;
			return (1);
		}
	}
	if (ft_strcmp(command, "sb") == 'y' || *track == -1)
	{
		if (numbers->head_b != NULL && numbers->head_b->next != NULL)
			ft_swap(&numbers->head_b);
		*track = -1;
		return (1);
	}
	return (0);
}

int	ft_command_r(t_stack *numbers, char *command, int *track)
{
	if (ft_strcmp(command, "rr") == 'y')
		*track = -1;
	if (ft_strcmp(command, "ra") == 'y' || *track == -1)
	{
		if (numbers->head_a != NULL && numbers->tail_a != NULL
			&& numbers->head_a->num != numbers->tail_a->num)
			ft_rotate_up(&numbers->head_a, &numbers->tail_a);
		if (*track != -1)
		{
			*track = -1;
			return (1);
		}
	}
	if (ft_strcmp(command, "rb") == 'y' || *track == -1)
	{
		*track = -1;
		if (numbers->head_b != NULL && numbers->tail_b != NULL
			&& numbers->head_b->num != numbers->tail_b->num)
			ft_rotate_up(&numbers->head_b, &numbers->tail_b);
		return (1);
	}
	return (0);
}

int	ft_command_r_r(t_stack *numbers, char *command, int *track)
{
	if (ft_strcmp(command, "rrr") == 'y')
		*track = -1;
	if (ft_strcmp(command, "rra") == 'y' || *track == -1)
	{
		if (numbers->head_a != NULL && numbers->tail_a != NULL
			&& numbers->head_a->num != numbers->tail_a->num)
			ft_rotate_down(&numbers->head_a, &numbers->tail_a);
		if (*track != -1)
		{
			*track = -1;
			return (1);
		}
	}
	if (ft_strcmp(command, "rrb") == 'y' || *track == -1)
	{
		*track = -1;
		if (numbers->head_b != NULL && numbers->tail_b != NULL
			&& numbers->head_b->num != numbers->tail_b->num)
			ft_rotate_down(&numbers->head_b, &numbers->tail_b);
		return (1);
	}
	return (0);
}
