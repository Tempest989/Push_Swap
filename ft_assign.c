/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 23:12:01 by druth             #+#    #+#             */
/*   Updated: 2022/03/23 23:12:02 by druth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_strlen(char *str)
{
	int	track;

	track = 0;
	while (str[track] != '\0')
		track++;
	return (track);
}

int	ft_limit(char *av, int *error, int track, int flag)
{
	int		len;
	char	*check;

	len = ft_strlen(av);
	if ((len == 11 && (av[0] != '-' && av[0] != '+')) || len > 11)
		return (ft_error(error));
	if (len == 10 || (len == 11 && (av[0] == '-' || av[0] == '+')))
	{
		check = "2147483647";
		if (av[0] == '-' || av[0] == '+')
			flag = 1;
		track += flag;
		while (track < len)
		{
			if (av[track] < check[track - flag]
				|| (track == 10 && av[0] == '-' && av[track] <= '8'))
				break ;
			if (av[track] > check[track - flag])
				return (ft_error(error));
			track++;
		}
	}
	return (0);
}

int	ft_atoi(char *av, int *error)
{
	int	track;
	int	output;
	int	sign;

	if (av == NULL || av[0] == '\0')
		return (ft_error(error));
	if (ft_limit(av, error, 0, 0) == -1)
		return (0);
	sign = 1;
	output = 0;
	track = 0;
	if (av[0] == '-')
		sign = -1;
	if (av[0] == '-' || av[0] == '+')
		track++;
	while (av[track] >= '0' && av[track] <= '9' && av[track] != '\0')
		output = (output * 10) + sign * (av[track++] - '0');
	if (av[track] != '\0' || ((av[0] == '-' || av[0] == '+')
			&& (av[track - 1] < '0' || av[track - 1] > '9')))
		return (ft_error(error));
	return (output);
}

int	ft_double_check(t_num *head, int check)
{
	while (head != NULL)
	{
		if (check == head->num)
			return (-1);
		head = head->next;
	}
	return (1);
}

int	ft_assign(t_stack *numbers, char **av, int error, int max)
{
	int	check;
	int	min;

	check = ft_atoi(av[1], &error);
	if (error != 0
		|| ft_initialize_stack(numbers, ft_num_new(check), 'a') == -1)
		return (-1);
	max = check;
	min = check;
	while (numbers->size_a < numbers->size_max)
	{
		check = ft_atoi(av[numbers->size_a + 1], &error);
		if (error != 0)
			return (-1);
		if (check > max)
			max = check;
		else if (check < min)
			min = check;
		else if (ft_double_check(numbers->head_a, check) == -1)
			return (ft_error(&error));
		if (ft_stack_back(&numbers->tail_a, ft_num_new(check)) == -1)
			return (-1);
		numbers->size_a++;
	}
	return (0);
}
