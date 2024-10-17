#include "../includes/push_swap.h"

void    push(t_stack *stack, int value)
{
    t_node  *new;

    new = malloc(sizeof(t_node));
    if (!new)
        exit_with_error("malloc failed");
    new->value = value;
    new->next = stack->top;
    stack->top = new;
    stack->size++;
}

int     pop(t_stack *stack)
{
    t_node  *temp;
    int     value;

    if (!stack->top)
        return (0);
    temp = stack->top;
    value = temp->value;
    stack->top = temp->next;
    free(temp);
    stack->size--;
    return (value);
}

int is_sorted(t_stack *a)
{
    t_node *current;

    if (!a->top || a->size < 2)
        exit_with_error("stack is too small to sort");
    current = a->top;
    while (current->next)
    {
        if (current->value > current->next->value)
        {
            //ft_printf("Stack is not sorted\n");
            return (0);
        }
        current = current->next;
    }
    //ft_printf("Stack is sorted\n");
    return (1);
}
int is_array_sorted(int *ranks, int total_numbers)
{
    for (int i = 0; i < total_numbers - 1; i++)
    {
        if (ranks[i] > ranks[i + 1])
            return 0;  // Якщо хоч одне число більше наступного, масив не відсортований
    }
    return 1;  // Масив відсортований
}

void push_numbers_to_stack(t_stack *a, int *ranks, int total_numbers)
{
    // Перевіряємо, чи масив чисел відсортований
    if (is_array_sorted(ranks, total_numbers))
    {
        // Якщо відсортований, додаємо числа у стек у зворотному порядку
        for (int i = total_numbers - 1; i >= 0; i--)
        {
            push(a, ranks[i]);  // Додаємо числа у стек
            //printf("Pushed to stack: %d (sorted order)\n", ranks[i]);  // Виводимо результат
        }
    }
    else
    {
        // Якщо не відсортований, додаємо числа у порядку, як вони передані
        for (int i = total_numbers - 1; i >= 0; i--)
        {
            push(a, ranks[i]);  // Додаємо числа у стек
            //printf("Pushed to stack: %d\n", ranks[i]);  // Виводимо результат
        }
    }
}


void    free_split_args(char **split_args)
{
    int j;

    j = 0;
    while (split_args[j])
    {
        free(split_args[j]);
        j++;
    }
    free(split_args);
}

void    free_stack(t_stack *stack)
{
    while (stack->size)
        pop(stack);
}
void bubble_sort(int *arr, int size)
{
    int temp;
    int swapped;

    // Зовнішній цикл повторюється для всіх елементів
    for (int i = 0; i < size - 1; i++)
    {
        swapped = 0;  // Позначаємо, чи відбулися зміни під час цього проходу
        // Внутрішній цикл порівнює елементи і змінює їх місцями, якщо потрібно
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Міняємо місцями arr[j] і arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;  // Позначаємо, що відбулася зміна
            }
        }
        // Якщо на жодному етапі зміни не відбулися, масив уже відсортований
        if (swapped == 0)
            break;
    }
}

int *assign_ranks(int *numbers, int total_numbers)
{
    int *sorted = malloc(sizeof(int) * total_numbers);
    int *ranks = malloc(sizeof(int) * total_numbers);

    if (!sorted || !ranks)
        exit_with_error("malloc failed");
    // Копіюємо оригінальний масив у sorted
    for (int i = 0; i < total_numbers; i++)
        sorted[i] = numbers[i];
    // Сортуємо копію масиву
    bubble_sort(sorted, total_numbers);  // Ви можете використовувати будь-який сортувальний алгоритм
    // Присвоюємо ранги на основі посортованого масиву
    for (int i = 0; i < total_numbers; i++)
    {
        for (int j = 0; j < total_numbers; j++)
        {
            if (numbers[i] == sorted[j])
            {
                ranks[i] = j;  // Присвоюємо ранг
                // Виводимо число і його ранг
                //printf("Number %d is assigned rank %d\n", numbers[i], ranks[i]);
                break;
            }
        }
    }
    free(sorted);  // Звільняємо пам'ять, виділену для копії масиву
    return (ranks);
}
