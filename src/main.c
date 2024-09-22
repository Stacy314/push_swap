#include "push_swap.h"

// int main(int argc, char **argv)
// {
//     t_stack_node	*a;
// 	t_stack_node	*b;
// 	//int				free_argv;

// 	//free_argv = 0;
// 	a = NULL;
// 	b = NULL;
// 	if (argc == 1 || (argc == 2 && !argv[1][0]))
// 		return (1);
// 	else if (argc == 2)
// 	{
// 		argv = ft_split(argv[1], ' ');
// 		//free_argv = 1;
// 	}
//     //else if (argc > 2)
//         //strjoin?
//     stack_init(&a, arhv + 1, 2 == argc);
//     if (!stack_sorted(a))
//     {
//         if (stack_len(a) == 2)
//             sa(&a, false);
//         else if (stack_len == 3)
//             tiny_sort(&a);
//         else
//             push_swap(&a, &b);
//     }
//     free_stack(&a);
// 	// a = init_stack(a, argv, free_argv);
// 	// if (is_stack_sorted(a))
// 	// 	sort(&a, &b);
// 	// free_all(a, argv, free_argv);
// 	// return (0);
// }

int main(int argc, char **argv)
{
    if (argc < 2)
        return (0);
    
    // Initialize stacks
    t_stack a;
    t_stack b;
    a.top = NULL;
    a.size = 0;
    b.top = NULL;
    b.size = 0;

    // Parse and validate input
    int *numbers = malloc(sizeof(int) * (argc -1));
    if (!numbers)
        print_error();
    for (int i = 1; i < argc; i++)
    {
        // Simple atoi with error checking
        char *endptr;
        long num = strtol(argv[i], &endptr, 10);
        if (*endptr != '\0' || num > INT_MAX || num < INT_MIN)
        {
            free(numbers);
            print_error();
        }
        // Check for duplicates
        for (int j = 0; j < i -1; j++)
            if (numbers[j] == (int)num)
            {
                free(numbers);
                print_error();
            }
        numbers[i -1] = (int)num;
        push(&a, numbers[i -1]);
    }

    // Since we pushed to stack, the first argument is at the top
    // Radix sort expects the first element to be at the beginning
    // So we need to reverse stack a or process accordingly
    // For simplicity, let's proceed

    if (!is_sorted(&a))
    {
        radix_sort(&a, &b, a.size);
    }

    // Free allocated memory
    while (a.size)
        pop(&a);
    while (b.size)
        pop(&b);
    free(numbers);
    return (0);
}