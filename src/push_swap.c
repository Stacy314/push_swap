/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <apechkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:20:29 by apechkov          #+#    #+#             */
/*   Updated: 2024/10/22 22:25:12 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_numbers_to_stack(t_stack *a, int *ranks, int total_numbers)
{
	int	i;

	i = total_numbers - 1;
	while (i >= 0)
	{
		push(a, ranks[i]);
		i--;
	}
}

void	bubble_sort(int *arr, int size)
{
	int	temp;
	int	swapped;
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		swapped = 0;
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = 1;
			}
			j++;
		}
		if (swapped == 0)
			break ;
		i++;
	}
}

int	*copy_and_sort(int *numbers, int total_numbers)
{
	int	*sorted;
	int	i;

	sorted = malloc(sizeof(int) * total_numbers);
	if (!sorted)
		exit(1);
	i = 0;
	while (i < total_numbers)
	{
		sorted[i] = numbers[i];
		i++;
	}
	bubble_sort(sorted, total_numbers);
	return (sorted);
}

int	ft_find_rank(int *sorted, int num, int total_numbers)
{
	int	j;

	j = 0;
	while (j < total_numbers)
	{
		if (num == sorted[j])
			return (j);
		j++;
	}
	return (0);
}

int	*assign_ranks(int *numbers, int total_numbers)
{
	int	*sorted;
	int	*ranks;
	int	i;

	sorted = copy_and_sort(numbers, total_numbers);
	if (!sorted)
		return (NULL);
	ranks = malloc(sizeof(int) * total_numbers);
	if (!ranks)
		return (free(sorted), NULL);
	i = 0;
	while (i < total_numbers)
	{
		ranks[i] = ft_find_rank(sorted, numbers[i], total_numbers);
		i++;
	}
	return (free(sorted), ranks);
}
