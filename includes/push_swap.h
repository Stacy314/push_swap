/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiia <anastasiia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:20:29 by apechkov          #+#    #+#             */
/*   Updated: 2024/10/17 21:47:03 by anastasiia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define FAILURE 1

# include "../libft/libft.h"

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

//extern int	operation_count;  

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
void	push(t_stack *stack, int value);
int		pop(t_stack *stack);
int		is_sorted(t_stack *a);
void	exit_with_error(char *error_message);

// push_swap.c
int		is_array_sorted(int *numbers, int total_numbers);
void	push_numbers_to_stack(t_stack *a, int *numbers, int total_numbers);
void	free_split_args(char **split_args);
void	free_stack(t_stack *stack);
int		*assign_ranks(int *numbers, int total_numbers);

// operation.c
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

// radix.c
void	check_duplicate(int *numbers, int size, long num);
int		*parse_arguments(int argc, char **argv, int *total_numbers);
int		get_max_bits(t_stack *a);
void	sort_three(t_stack *a);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
void	radix_sort(t_stack *a, t_stack *b);

#endif