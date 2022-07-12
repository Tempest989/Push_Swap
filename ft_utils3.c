/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 23:13:27 by druth             #+#    #+#             */
/*   Updated: 2022/03/23 23:13:28 by druth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_start_loop(t_stack *numbers, int max, int track, int count)
{
	int	search;

	while (numbers->size_a > 1)
	{
		while (track < numbers->chunk_num && numbers->size_a > 1)
		{
			search = ft_downer(numbers->head_a, numbers->tail_a,
					max, numbers->size_a / 2);
			if (search >= 0)
				ft_push_a_up(numbers, max);
			else
				ft_push_a_down(numbers, max);
			track++;
			numbers->size_a--;
			numbers->size_b++;
		}
		count++;
		max = ft_finder(numbers->tail_sort, numbers->chunk_num * count);
		track = 0;
	}
}

int	ft_initialize_stack(t_stack *numbers, t_num *first, char stack)
{
	if (first == NULL)
		return (-1);
	if (first->next != NULL)
		first->next = NULL;
	if (first->previous != NULL)
		first->previous = NULL;
	if (stack == 'a')
	{
		numbers->head_a = first;
		numbers->tail_a = first;
		numbers->size_a = 1;
	}
	else if (stack == 'b')
	{
		numbers->head_b = first;
		numbers->tail_b = first;
		numbers->size_b = 1;
	}
	else if (stack == 's')
	{
		numbers->head_sort = first;
		numbers->tail_sort = first;
	}
	return (1);
}

int	ft_chunky(t_stack *numbers)
{
	if (numbers->size_max <= 20)
		numbers->chunk_num = numbers->size_max / 2;
	else if (numbers->size_max <= 100)
		numbers->chunk_num = numbers->size_max / 5;
	else if (numbers->size_max <= 500)
		numbers->chunk_num = numbers->size_max / 14;
	else
		numbers->chunk_num = numbers->size_max
			/ (14 + ((numbers->size_max - 500) / 100));
	return (1);
}

void	ft_null_assign(t_stack *numbers)
{
	numbers->head_a = NULL;
	numbers->head_b = NULL;
	numbers->head_sort = NULL;
	numbers->tail_a = NULL;
	numbers->tail_b = NULL;
	numbers->tail_sort = NULL;
	numbers->size_a = 0;
	numbers->size_b = 0;
}

void	ft_free(t_stack *numbers)
{
	if (numbers->head_a != NULL)
		ft_stack_clear(&numbers->head_a);
	if (numbers->head_b != NULL)
		ft_stack_clear(&numbers->head_b);
	if (numbers->head_sort != NULL)
		ft_stack_clear(&numbers->head_sort);
	numbers->chunk_num = 0;
}
