#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "../libft/libft.h"

# include <unistd.h>
//# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
//# include <stdbool.h>
# include <limits.h>
# include <string.h>

// Node structure for stack
typedef struct s_node {
    int value;
    struct s_node *next;
} t_node;

// Stack structure
typedef struct s_stack {
    t_node *top;
    int size;
} t_stack;

void    push(t_stack *stack, int value);
int     pop(t_stack *stack);
int     is_sorted(t_stack *a);
void    sa(t_stack *a);
void    sb(t_stack *b);
void    ss(t_stack *a, t_stack *b);
void    pa(t_stack *a, t_stack *b);
void    pb(t_stack *a, t_stack *b);
void    ra(t_stack *a);
void    rb(t_stack *b);
void    rr(t_stack *a, t_stack *b);
void    rra(t_stack *a);
void    rrb(t_stack *b);
void    rrr(t_stack *a, t_stack *b);
//void    print_error(void);
int     *normalize(int *arr, int size);
void    radix_sort(t_stack *a, t_stack *b, int size);

// typedef struct s_stack_node {
// 	struct s_stack_node	*prev;
// 	struct s_stack_node	*next;
//     struct s_stack_node	*target_node;
//     //int					target_node;
// 	int					value;
// 	size_t				current_pos;
// 	size_t				push_price;
//     bool    above_median;
//     bool    cheapest;
// 	// size_t				ra;
// 	// size_t				rb;
// 	// size_t				rr;
// 	// size_t				rra;
// 	// size_t				rrb;
// 	// size_t				rrr;
// }	t_stack_node;



// typedef struct s_stack
// {
// 	long			nbr;
// 	long			index;
// 	struct s_stack	*next;
// 	struct s_stack	*prev;
// }	t_stack;


#endif