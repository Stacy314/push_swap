#include "../includes/push_swap.h"

//int operation_count = 0;  // Оголошення глобальної змінної

void    sa(t_stack *a)
{
    t_node  *first;
    t_node  *second;

    if (a->size < 2)
        return ;
    first = a->top;
    second = first->next;
    first->next = second->next;
    second->next = first;
    a->top = second;
    //operation_count++;  // Збільшуємо кількість операцій
    write(1, "sa\n", 3);
}

void    sb(t_stack *b)
{
    t_node  *first;
    t_node  *second;

    if (b->size < 2)
        return ;
    first = b->top;
    second = first->next;
    first->next = second->next;
    second->next = first;
    b->top = second;
    //operation_count++;  // Збільшуємо кількість операцій
    write(1, "sb\n", 3);
}

void    ss(t_stack *a, t_stack *b)
{
    sa(a);
    sb(b);
    //operation_count++;  // Збільшуємо кількість операцій
    write(1, "ss\n", 3);
}

void    pa(t_stack *a, t_stack *b)
{
    int val;

    if (b->size == 0)
        return ;
    val = pop(b);
    push(a, val);
    //operation_count++;  // Збільшуємо кількість операцій
    write(1, "pa\n", 3);
}

void    pb(t_stack *a, t_stack *b)
{
    int val;

    if (a->size == 0)
        return ;
    val = pop(a);
    push(b, val);
    //operation_count++;  // Збільшуємо кількість операцій
    write(1, "pb\n", 3);
}

void    ra(t_stack *a)
{
    t_node  *first;
    t_node  *current;

    if (a->size < 2)
        return ;
    first = a->top;
    a->top = first->next;
    first->next = NULL;
    current = a->top;
    while (current->next)
        current = current->next;
    current->next = first;
    //operation_count++;  // Збільшуємо кількість операцій
    write(1, "ra\n", 3);
}

void    rb(t_stack *b)
{
    t_node  *first;
    t_node  *current;

    if (b->size < 2)
        return ;
    first = b->top;
    b->top = first->next;
    first->next = NULL;
    current = b->top;
    while (current->next)
        current = current->next;
    current->next = first;
    //operation_count++;  // Збільшуємо кількість операцій
    write(1, "rb\n", 3);
}

void    rr(t_stack *a, t_stack *b)
{
    ra(a);
    rb(b);
    //operation_count++;  // Збільшуємо кількість операцій
    write(1, "rr\n", 3);
}

void    rra(t_stack *a)
{
    t_node  *current;
    t_node  *last;

    if (a->size < 2)
        return ;
    current = a->top;
    while (current->next->next)
        current = current->next;
    last = current->next;
    current->next = NULL;
    last->next = a->top;
    a->top = last;
    //operation_count++;  // Збільшуємо кількість операцій
    write(1, "rra\n", 4);
}

void    rrb(t_stack *b)
{
    t_node  *current;
    t_node  *last;

    if (b->size < 2)
        return ;
    current = b->top;
    while (current->next->next)
        current = current->next;
    last = current->next;
    current->next = NULL;
    last->next = b->top;
    b->top = last;
    //operation_count++;  // Збільшуємо кількість операцій
    write(1, "rrb\n", 4);
}

void    rrr(t_stack *a, t_stack *b)
{
    rra(a);
    rrb(b);
    //operation_count++;  // Збільшуємо кількість операцій
    write(1, "rrr\n", 4);
}
