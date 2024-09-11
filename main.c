#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack_node	*a;
	t_stack_node	*b;
	//int				free_argv;

	//free_argv = 0;
	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		//free_argv = 1;
	}
    //else if (argc > 2)
        //strjoin?
    stack_init(&a, arhv + 1, 2 == argc);
    if (!stack_sorted(a))
    {
        if (stack_len(a) == 2)
            sa(&a, false);
        else if (stack_len == 3)
            tiny_sort(&a);
        else
            push_swap(&a, &b);
    }
    free_stack(&a);
	// a = init_stack(a, argv, free_argv);
	// if (is_stack_sorted(a))
	// 	sort(&a, &b);
	// free_all(a, argv, free_argv);
	// return (0);
}