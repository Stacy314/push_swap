#include "../includes/push_swap.h"

int find_min(t_stack *a)
{
    t_node *current;
    int min;

    current = a->top;
    min = current->value;
    // Проходимо по стеку і знаходимо мінімальне значення
    while (current)
    {
        if (current->value < min)
            min = current->value;
        current = current->next;
    }
    return (min);
}


int     get_max_bits(t_stack *a)
{
    int     max;
    int     max_bits;
    t_node  *current;

    max = 0;
    current = a->top;
    while (current)
    {
        if (current->value > max)
            max = current->value;
        current = current->next;
    }
    max_bits = 0;
    while ((max >> max_bits) != 0)
        max_bits++;
    return (max_bits);
}

void sort_three(t_stack *a)
{
    int first;
    int second;
    int third;

    first = a->top->value;
    second = a->top->next->value;
    third = a->top->next->next->value;
    if (first > second && second < third && first < third) // 2 1 3 -> sa
        sa(a);
    else if (first > second && second > third) // 3 2 1 -> sa + rra
    {
        sa(a);
        rra(a);
    }
    else if (first > second && second < third && first > third) // 3 1 2 -> ra
        ra(a);
    else if (first < second && second > third && first < third) // 1 3 2 -> sa + ra
    {
        sa(a);
        ra(a);
    }
    else if (first < second && second > third && first > third) // 2 3 1 -> rra
        rra(a);
}
void sort_four(t_stack *a, t_stack *b)
{
    int min = find_min(a);  // Знаходимо мінімальне значення у стеку a
    // Переміщуємо мінімальний елемент у стек b
    while (a->top->value != min)
        ra(a);  // Виконуємо ратацію, поки мінімальний елемент не опиниться на вершині
    pb(a, b);  // Переміщаємо мінімальний елемент у стек b
    // Сортуємо залишок з 3 елементів
    sort_three(a);  // Використовуємо вже реалізовану функцію для сортування 3 елементів
    // Повертаємо мінімальний елемент зі стека b назад у стек a
    pa(a, b);  // Повертаємо елемент назад
}

void sort_five(t_stack *a, t_stack *b)
{
    int min = find_min(a); // Знайти мінімальний елемент
    // Витягуємо мінімальний елемент з стека
    while (a->top->value != min)
        ra(a);
    pb(a, b);  // Переносимо мінімальний елемент у стек b
    // Сортуємо залишок з 4 елементів
    if (a->size == 4)
        sort_four(a, b);  // Подібна логіка для чотирьох елементів
    // Повертаємо мінімальний елемент назад у стек a
    pa(a, b);
}

void radix_sort(t_stack *a, t_stack *b)
{
    int size;
    int max_bits;
    t_node *current;

    size = a->size;
    max_bits = 0;
    current = a->top;
    // Знаходимо максимальну кількість бітів для рангу
    while (current)
    {
        int rank = current->value;
        while ((rank >> max_bits) != 0)
            max_bits++;
        current = current->next;
    }
    // Сортуємо за кожним бітом
    for (int i = 0; i < max_bits; i++)
    {
        int j = 0;
        while (j < size)
        {
            if (((a->top->value >> i) & 1) == 1)  // Перевіряємо біт рангу
                ra(a);  // Поворот стека A
            else
                pb(a, b);  // Переміщення у стек B
            j++;
        }
        // Повертаємо всі елементи зі стека B назад у стек A
        while (b->size)
            pa(a, b);
    }
}
