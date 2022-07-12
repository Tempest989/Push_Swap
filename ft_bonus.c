/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:22:38 by druth             #+#    #+#             */
/*   Updated: 2022/03/31 21:22:40 by druth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_bonus.h"

void	ft_ko_ok(t_stack *numbers, int behind)
{
	t_num	*temp;

	if (numbers->head_b != NULL || numbers->tail_b != NULL)
	{
		write(1, "KO\n", 3);
		return ;
	}
	behind = numbers->head_a->num;
	if (numbers->head_a->next == NULL)
	{
		write(1, "OK\n", 3);
		return ;
	}
	temp = numbers->head_a->next;
	while (temp != NULL)
	{
		if (temp->num < behind)
		{
			write(1, "KO\n", 3);
			return ;
		}
		behind = temp->num;
		temp = temp->next;
	}
	write(1, "OK\n", 3);
}

char	ft_strcmp(char *command, char *check)
{
	int	track;

	track = 0;
	while (command[track] == check[track] && command[track] != '\n')
		track++;
	if (command[track] == '\n' && check[track] == '\0')
		return ('y');
	return ('n');
}

int	ft_compare(t_stack *numbers, char *command, int *track)
{
	if (ft_strcmp(command, "pb") == 'y')
		return (ft_command_pb(numbers, track));
	else if (ft_strcmp(command, "pa") == 'y')
		return (ft_command_pa(numbers, track));
	if (ft_command_sss(numbers, command, track) == 1)
		return (1);
	if (ft_command_r(numbers, command, track) == 1)
		return (1);
	if (ft_command_r_r(numbers, command, track) == 1)
		return (1);
	write(2, "Error\n", 6);
	return (-1);
}

void	ft_bonus_loop(t_stack *numbers, int track, int input)
{
	char	command[6];

	while (track < 5)
	{
		input = read(0, &command[track], 1);
		if (input == 0)
			break ;
		if (input == -1)
		{
			ft_free(numbers);
			return ;
		}
		if (command[track] == '\n'
			&& ft_compare(numbers, command, &track) == -1)
			return ;
		track++;
	}
	if (track > 0 && command[track] != '\n')
	{
		write(2, "Error\n", 6);
		return ;
	}
	ft_ko_ok(numbers, 0);
}

int	main(int ac, char **av)
{
	t_stack	numbers;
	int		error;

	if (ac <= 1)
		return (0);
	numbers.size_max = ac - 1;
	ft_null_assign(&numbers);
	if (ac == 2)
	{
		numbers.head_a = ft_num_new(ft_atoi(av[1], &error));
		if (numbers.head_a == NULL)
			return (0);
		if (error == -1)
			return (0);
		numbers.tail_a = numbers.head_a;
	}
	else if (ft_assign(&numbers, av, 0, 0) == -1)
	{
		ft_free(&numbers);
		return (0);
	}
	ft_bonus_loop(&numbers, 0, 0);
	return (0);
}
