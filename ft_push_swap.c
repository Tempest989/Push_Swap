/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 23:12:48 by druth             #+#    #+#             */
/*   Updated: 2022/03/23 23:12:50 by druth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_choose_sort(t_stack *numbers)
{
	t_num	*temp;

	if (numbers->size_max == 2)
	{
		temp = numbers->head_a->next;
		ft_2_sort(&numbers->head_a, &temp, 'a');
	}
	else if (numbers->size_max == 3)
		ft_3_sort(numbers);
	else if (numbers->size_max == 4)
		ft_4_sort(numbers);
	else if (numbers->size_max == 5)
		ft_5_sort(numbers);
	else
	{
		ft_start(numbers, 0, 1, 1);
		ft_finish(numbers);
	}
	ft_free(numbers);
}

int	ft_already_done(t_stack *numbers)
{
	t_num	*temp;
	t_num	*next;

	temp = numbers->head_a;
	next = numbers->head_a->next;
	while (next != NULL && temp->num < next->num)
	{
		temp = temp->next;
		next = next->next;
	}
	if (temp->num == numbers->tail_a->num)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	numbers;
	int		error;

	if (ac <= 1)
		return (0);
	if (ac == 2)
	{
		ft_atoi(av[1], &error);
		return (0);
	}
	numbers.size_max = ac - 1;
	ft_chunky(&numbers);
	ft_null_assign(&numbers);
	if (ft_assign(&numbers, av, 0, 0) == -1
		|| ft_already_done(&numbers) == 1 || ft_sort(&numbers) == -1)
	{
		ft_free(&numbers);
		return (0);
	}
	ft_choose_sort(&numbers);
	return (0);
}
