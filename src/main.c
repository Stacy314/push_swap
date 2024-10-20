/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <apechkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:20:29 by apechkov          #+#    #+#             */
/*   Updated: 2024/10/20 17:46:16 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exit_with_error(char *error_message)
{
	ft_printf("Error: %s\n", error_message);
	exit(FAILURE);
}

void initialize_stacks(int argc, char **argv, t_stack *a, t_stack *b)
{
    int *numbers;
    int *ranks;
    int total_numbers;

    numbers = parse_arguments(argc, argv, &total_numbers);
    if (!numbers)
        exit_with_error("parse failed");
    ranks = assign_ranks(numbers, total_numbers);
    push_numbers_to_stack(a, ranks, total_numbers);
    free(numbers);
    free(ranks);
    if (is_sorted(a))
    {
        free_stack(a);
        free_stack(b);
        exit_with_error("stack is sorted");
    }
}

int main(int argc, char **argv)
{
    t_stack a;
    t_stack b;

    a.top = NULL;
    a.size = 0;
    b.top = NULL;
    b.size = 0;

    if (argc < 2)
       exit_with_error("enter the numbers to sort");
    if (argc == 2)
        exit_with_error("stack is too small to sort");
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
