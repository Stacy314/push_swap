#include "../includes/push_swap.h"

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
    t_stack a;
    t_stack b;
    int i;
    int j;
    int *numbers;
    long num;
    int size;

    if (argc < 2)
        return (ft_printf("Enter the numbers to sort.\n"), 1);
    a.top = NULL;
    a.size = 0;
    b.top = NULL;
    b.size = 0;

    // Парсинг вхідних даних
    numbers = malloc(sizeof(int) * (argc -1));
    if (!numbers)
        return(1);
    i = 1;
    while(i < argc)
    {
        num = ft_atoi(argv[i]);
        if (num > INT_MAX || num < INT_MIN)
        {
            free(numbers);
            ft_printf("Error: doesn't fit into an int.\n");
        }
        j = 0;
        while (j < (i - 1))
        {
            if (numbers[j] == (int)num)
            {
                free(numbers);
                ft_printf("Error: doubles.\n");
            }
            j++;
        }
        numbers[i -1] = (int)num;
        push(&a, numbers[i -1]);
        i++;
    }

    // Перевірка, чи стек відсортований
    if (is_sorted(&a))
    {
        free(numbers);
        return (0);  // Якщо відсортовано, нічого не робимо
    }

    // Якщо не відсортовано, запускаємо алгоритм сортування
    size = a.size;
    radix_sort(&a, &b, size);

    // Звільнення пам'яті
    free(numbers);
    while (a.size)
        pop(&a);
    while (b.size)
        pop(&b);

    return (0);
}
