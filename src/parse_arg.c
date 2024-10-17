/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiia <anastasiia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:20:29 by apechkov          #+#    #+#             */
/*   Updated: 2024/10/17 22:52:22 by anastasiia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void	check_duplicate(int *numbers, int size, long num)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (numbers[i] == (int)num)
		{
			free(numbers);
			exit_with_error("duplicate number found");
		}
		i++;
	}
}

int count_total_numbers(int argc, char **argv)
{
    int total_numbers;
    char **split_args;
    int i;
	int j;

	total_numbers = 0;
    // Підраховуємо загальну кількість чисел після split
	i = 1;
    while (i < argc)
    {
        split_args = ft_split(argv[i], ' ');
        if (!split_args)
            exit_with_error("split failed");
        j = 0;
        while (split_args[j])
        {
            total_numbers++;
            j++;
        }
        free_split_args(split_args);  // Звільняємо пам'ять
        i++;
    }
    return (total_numbers);  // Повертаємо кількість чисел
}

long validate_number(char *str, int *numbers, int index)
{
    long num;

    // Перетворюємо рядок у число
    num = strtol(str, NULL, 10);
    if (num > INT_MAX || num < INT_MIN)
        exit_with_error("number doesn't fit into int");
    // Перевіряємо дублікат перед додаванням у масив
    check_duplicate(numbers, index, num);
    return (num);
}

void fill_numbers(int argc, char **argv, int *numbers)
{
    char **split_args;
    int i;
    int index;
    int j;
    long num;
	
	index = 0;
    // Проходимо через всі аргументи
	i = 1;
    while (i < argc)
    {
        split_args = ft_split(argv[i], ' ');
        if (!split_args)
            exit_with_error("split failed");
        j = 0;
        while (split_args[j])
        {
            // Використовуємо нову функцію для перевірки і перетворення
            num = validate_number(split_args[j], numbers, index);
            numbers[index++] = (int)num;  // Додаємо число у масив
            j++;
        }
        free_split_args(split_args);  // Звільняємо пам'ять після split
        i++;
    }
}

int *parse_arguments(int argc, char **argv, int *total_numbers)
{
	int *numbers;
	
    // Спочатку рахуємо загальну кількість чисел
    *total_numbers = count_total_numbers(argc, argv);
    // Виділяємо пам'ять під числа
    numbers = malloc(sizeof(int) * (*total_numbers));
    if (!numbers)
        exit_with_error("malloc failed");
    // Заповнюємо масив числами
    fill_numbers(argc, argv, numbers);
    return (numbers);
}