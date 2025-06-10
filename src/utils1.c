/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <apechkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:20:29 by apechkov          #+#    #+#             */
/*   Updated: 2024/10/26 21:24:18 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	find_min(t_stack *a)
{
	t_node	*current;
	int		min;

	current = a->top;
	min = current->value;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	find_second_min(t_stack *stack)
{
	t_node	*current;
	int		min;
	int		second_min;

	min = find_min(stack);
	second_min = INT_MAX;
	current = stack->top;
	while (current)
	{
		if (current->value > min && current->value < second_min)
			second_min = current->value;
		current = current->next;
	}
	return (second_min);
}

int	get_max_bits(t_stack *a)
{
	int		max;
	int		max_bits;
	t_node	*current;	

	max = 0;
	current = a->top;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	max_bits = 0;
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}
