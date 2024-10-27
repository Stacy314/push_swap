/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <apechkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:20:29 by apechkov          #+#    #+#             */
/*   Updated: 2024/10/21 15:37:57 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack *a)
{
	t_node	*first;
	t_node	*current;

	if (a->size < 2)
		return ;
	first = a->top;
	a->top = first->next;
	first->next = NULL;
	current = a->top;
	while (current->next)
		current = current->next;
	current->next = first;
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	t_node	*first;
	t_node	*current;

	if (b->size < 2)
		return ;
	first = b->top;
	b->top = first->next;
	first->next = NULL;
	current = b->top;
	while (current->next)
		current = current->next;
	current->next = first;
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}
