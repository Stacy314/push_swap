/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <apechkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:20:29 by apechkov          #+#    #+#             */
/*   Updated: 2024/10/26 20:21:19 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_split_args(char **split_args)
{
	int	j;

	j = 0;
	while (split_args[j])
	{
		free(split_args[j]);
		j++;
	}
	free(split_args);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	stack->top = NULL;
	stack->size = 0;
}

void	exit_with_error(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(FAILURE);
}

bool	check_duplicate(int *numbers, int size, int num)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (numbers[i] == (int)num)
		{
			free(numbers);
			return (false);
		}
		i++;
	}
	return (true);
}
