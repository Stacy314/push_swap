/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <apechkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:20:29 by apechkov          #+#    #+#             */
/*   Updated: 2024/10/22 22:10:37 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	initialize_stacks(int argc, char **argv, t_stack *a, t_stack *b)
{
	int	*numbers;
	int	*ranks;
	int	total_numbers;

	total_numbers = 0;
	total_numbers = count_total_numbers(argc, argv, total_numbers);
	if (total_numbers == 0)
		exit_with_error();
	numbers = parse_arguments(argc, argv, total_numbers);
	if (!numbers)
		exit_with_error();
	ranks = assign_ranks(numbers, total_numbers);
	if (!ranks)
		return (free(numbers), exit_with_error());
	push_numbers_to_stack(a, ranks, total_numbers);
	free(numbers);
	free(ranks);
	if (is_sorted(a))
	{
		free_stack(a);
		free_stack(b);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	a.top = NULL;
	a.size = 0;
	b.top = NULL;
	b.size = 0;
	if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
		return (1);
	initialize_stacks(argc, argv, &a, &b);
	if (a.size == 2)
		sa(&a);
	else if (a.size == 3)
		sort_three(&a);
	else if (a.size == 4)
		sort_four(&a, &b);
	else if (a.size == 5)
		sort_five(&a, &b);
	else
		radix_sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
