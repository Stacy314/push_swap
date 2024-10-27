/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <apechkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:20:29 by apechkov          #+#    #+#             */
/*   Updated: 2024/10/22 22:25:08 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdint.h>

int	is_sorted(t_stack *a)
{
	t_node	*current;

	current = a->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	fill_from_multiple_args(int argc, char **argv, int *numbers, int *index)
{
	int		i;
	int		num;
	char	*str;
	size_t	len;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			return (free(numbers), exit_with_error());
		num = ft_atoi(argv[i]);
		str = ft_itoa(num);
		len = ft_strlen(argv[i]);
		if (ft_strncmp(str, argv[i], len) != 0)
		{
			free(str);
			free(numbers);
			exit_with_error();
		}
		free(str);
		if (!check_duplicate(numbers, *index, num))
			exit_with_error();
		numbers[(*index)++] = num;
		i++;
	}
}

void	fill_from_single_arg(char *arg, int *numbers, int *index)
{
	char	**split_args;
	int		j;
	int		num;
	char	*str;

	split_args = ft_split(arg, ' ');
	if (!split_args)
		return (free(numbers), exit_with_error());
	j = 0;
	while (split_args[j])
	{
		num = ft_atoi(split_args[j]);
		str = ft_itoa(num);
		if (ft_strncmp(str, split_args[j], ft_strlen(split_args[j])))
			return (free_split_args(split_args), free(numbers),
				free(str), exit_with_error());
		free(str);
		if (!check_duplicate(numbers, *index, num))
			return (free_split_args(split_args), exit_with_error());
		numbers[(*index)++] = num;
		j++;
	}
	free_split_args(split_args);
}

int	*parse_arguments(int argc, char **argv, int total_numbers)
{
	int	*numbers;
	int	index;

	numbers = malloc(sizeof(int) * (total_numbers));
	if (!numbers)
		exit_with_error();
	index = 0;
	if (argc > 2)
		fill_from_multiple_args(argc, argv, numbers, &index);
	else
		fill_from_single_arg(argv[1], numbers, &index);
	return (numbers);
}

int	count_total_numbers(int argc, char **argv, int total_numbers)
{
	char	**split_args;
	int		i;
	int		j;

	if (argc == 2)
	{
		i = 1;
		while (i < argc)
		{
			split_args = ft_split(argv[i], ' ');
			if (!split_args)
				exit_with_error();
			j = 0;
			while (split_args[j])
			{
				total_numbers++;
				j++;
			}
			free_split_args(split_args);
			i++;
		}
	}
	else
		total_numbers = argc - 1;
	return (total_numbers);
}
