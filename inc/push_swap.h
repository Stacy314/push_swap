/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <apechkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:20:29 by apechkov          #+#    #+#             */
/*   Updated: 2024/10/27 15:04:33 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define FAILURE 1

# include "../libft/libft.h"

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

// main.c 
void	initialize_stacks(int argc, char **argv, t_stack *a, t_stack *b);

// push_swap.c
void	push_numbers_to_stack(t_stack *a, int *numbers, int total_numbers);
void	bubble_sort(int *arr, int size);
int		*copy_and_sort(int *numbers, int total_numbers);
int		ft_find_rank(int *sorted, int num, int total_numbers);
int		*assign_ranks(int *numbers, int total_numbers);

// radix.c
void	sort_three(t_stack *a);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
void	radix_sort(t_stack *a, t_stack *b);

// parse_arg.c
int		is_sorted(t_stack *a);
void	fill_from_multiple_args(int argc, char **argv, int *numbers,
			int *index);
void	fill_from_single_arg(char *arg, int *numbers, int *index);
int		*parse_arguments(int argc, char **argv, int total_numbers);
int		count_total_numbers(int argc, char **argv, int total_numbers);

// utils
void	free_split_args(char **split_args);
void	free_stack(t_stack *stack);
void	exit_with_error(void);
bool	check_duplicate(int *numbers, int size, int num);
int		find_min(t_stack *a);
int		find_second_min(t_stack *stack);
int		get_max_bits(t_stack *a);
// operations
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	push(t_stack *stack, int value);
int		pop(t_stack *stack);

#endif