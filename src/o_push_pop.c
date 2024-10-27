/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_push_pop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <apechkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:20:29 by apechkov          #+#    #+#             */
/*   Updated: 2024/10/22 17:08:17 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	int	val;

	if (b->size == 0)
		return ;
	val = pop(b);
	push(a, val);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	int	val;

	if (a->size == 0)
		return ;
	val = pop(a);
	push(b, val);
	write(1, "pb\n", 3);
}

void	push(t_stack *stack, int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		exit_with_error();
	new->value = value;
	new->next = stack->top;
	stack->top = new;
	stack->size++;
}

int	pop(t_stack *stack)
{
	t_node	*temp;
	int		value;

	if (!stack->top)
		return (0);
	temp = stack->top;
	value = temp->value;
	stack->top = temp->next;
	free(temp);
	stack->size--;
	return (value);
}
