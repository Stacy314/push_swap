/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiia <anastasiia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:20:29 by apechkov          #+#    #+#             */
/*   Updated: 2024/10/17 22:53:59 by anastasiia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exit_with_error(char *error_message)
{
	ft_printf("Error: %s\n", error_message);
	exit(FAILURE);
}

void initialize_stacks(int argc, char **argv, t_stack *a, t_stack *b)
{
    int *numbers;
    int *ranks;
    int total_numbers;

    // Парсинг аргументів і перевірка на помилки
    numbers = parse_arguments(argc, argv, &total_numbers);
    if (!numbers)
        exit_with_error("parse failed");
    // Присвоєння рангів числам
    ranks = assign_ranks(numbers, total_numbers);
    push_numbers_to_stack(a, ranks, total_numbers);
    // Звільняємо пам'ять для масивів numbers і ranks
    free(numbers);
    free(ranks);
    // Якщо стек відсортований, виводимо повідомлення і завершуємо програму
    if (is_sorted(a))
    {
        free_stack(a);
        free_stack(b);
        exit_with_error("stack is sorted");
    }
}

int main(int argc, char **argv)
{
    t_stack a;
    t_stack b;

    if (argc < 2)
       exit_with_error("enter the numbers to sort");
    // Ініціалізація стеків
    a.top = NULL;
    a.size = 0;
    b.top = NULL;
    b.size = 0;
    // Підготовка стеків та аргументів
    initialize_stacks(argc, argv, &a, &b);
    // Логіка для сортування залежно від кількості елементів
    if (a.size == 2)
        sa(&a);
    else if (a.size == 3)
        sort_three(&a);
    else if (a.size == 4)
        sort_four(&a, &b);  // Викликаємо sort_four
    else if (a.size == 5)
        sort_five(&a, &b);  // Використовуємо аналогічну логіку для 5 елементів
    else
        radix_sort(&a, &b);
    // printf("Total number of operations: %d\n", operation_count);    // Виведення загальної кількості операцій (опціонально)
    // Звільнення пам'яті для стеків
    free_stack(&a);
    free_stack(&b);
    return (0);
}
