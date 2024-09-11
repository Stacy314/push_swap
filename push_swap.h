#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack_node {
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
    struct s_stack_node	*target_node;
    //int					target_node;
	int					value;
	size_t				current_pos;
	size_t				push_price;
    bool    above_median;
    bool    cheapest;
	// size_t				ra;
	// size_t				rb;
	// size_t				rr;
	// size_t				rra;
	// size_t				rrb;
	// size_t				rrr;
}	t_stack_node;

