#include "push_swap.h"

// Stack Operations Implementations
void push(t_stack *stack, int value)
{
    t_node *new = malloc(sizeof(t_node));
    if (!new)
    {
        write(2, "Error\n", 6);
        exit(EXIT_FAILURE);
    }
    new->value = value;
    new->next = stack->top;
    stack->top = new;
    stack->size++;
}

int pop(t_stack *stack)
{
    if (!stack->top)
        return (0);
    t_node *temp = stack->top;
    int val = temp->value;
    stack->top = temp->next;
    free(temp);
    stack->size--;
    return (val);
}

int is_sorted(t_stack *a)
{
    if (!a->top)
        return (1);
    t_node *current = a->top;
    while (current->next)
    {
        if (current->value > current->next->value)
            return (0);
        current = current->next;
    }
    return (1);
}

// Operation Functions
void sa(t_stack *a)
{
    if (a->size < 2)
        return;
    t_node *first = a->top;
    t_node *second = first->next;
    first->next = second->next;
    second->next = first;
    a->top = second;
    write(1, "sa\n", 3);
}

void sb(t_stack *b)
{
    if (b->size < 2)
        return;
    t_node *first = b->top;
    t_node *second = first->next;
    first->next = second->next;
    second->next = first;
    b->top = second;
    write(1, "sb\n", 3);
}

void ss(t_stack *a, t_stack *b)
{
    sa(a);
    sb(b);
    write(1, "ss\n", 3);
}

void pa(t_stack *a, t_stack *b)
{
    if (b->size == 0)
        return;
    int val = pop(b);
    push(a, val);
    write(1, "pa\n", 3);
}

void pb(t_stack *a, t_stack *b)
{
    if (a->size == 0)
        return;
    int val = pop(a);
    push(b, val);
    write(1, "pb\n", 3);
}

void ra(t_stack *a)
{
    if (a->size < 2)
        return;
    t_node *first = a->top;
    a->top = first->next;
    first->next = NULL;
    t_node *current = a->top;
    while (current->next)
        current = current->next;
    current->next = first;
    write(1, "ra\n", 3);
}

void rb(t_stack *b)
{
    if (b->size < 2)
        return;
    t_node *first = b->top;
    b->top = first->next;
    first->next = NULL;
    t_node *current = b->top;
    while (current->next)
        current = current->next;
    current->next = first;
    write(1, "rb\n", 3);
}

void rr(t_stack *a, t_stack *b)
{
    ra(a);
    rb(b);
    write(1, "rr\n", 3);
}

void rra(t_stack *a)
{
    if (a->size < 2)
        return;
    t_node *current = a->top;
    while (current->next->next)
        current = current->next;
    t_node *last = current->next;
    current->next = NULL;
    last->next = a->top;
    a->top = last;
    write(1, "rra\n", 4);
}

void rrb(t_stack *b)
{
    if (b->size < 2)
        return;
    t_node *current = b->top;
    while (current->next->next)
        current = current->next;
    t_node *last = current->next;
    current->next = NULL;
    last->next = b->top;
    b->top = last;
    write(1, "rrb\n", 4);
}

void rrr(t_stack *a, t_stack *b)
{
    rra(a);
    rrb(b);
    write(1, "rrr\n", 4);
}

// Error Handling
void print_error(void)
{
    write(2, "Error\n", 6);
    exit(EXIT_FAILURE);
}

// Normalize the array
int *normalize(int *arr, int size)
{
    int *sorted = malloc(sizeof(int) * size);
    if (!sorted)
    {
        print_error();
    }
    memcpy(sorted, arr, sizeof(int) * size);
    // Simple Bubble Sort for normalization
    for (int i = 0; i < size -1; i++)
    {
        for (int j = 0; j < size - i -1; j++)
        {
            if (sorted[j] > sorted[j+1])
            {
                int temp = sorted[j];
                sorted[j] = sorted[j+1];
                sorted[j+1] = temp;
            }
        }
    }
    // Assign index
    int *normalized = malloc(sizeof(int) * size);
    if (!normalized)
    {
        free(sorted);
        print_error();
    }
    for (int i = 0; i < size; i++)
    {
        int j = 0;
        while (j < size)
        {
            if (arr[i] == sorted[j])
            {
                normalized[i] = j;
                break;
            }
            j++;
        }
    }
    free(sorted);
    return normalized;
}

// Radix Sort Implementation
void radix_sort(t_stack *a, t_stack *b, int size)
{
    int *normalized = normalize((int[]) {
        // Extract values from stack a
        // Since stack is LIFO, we need to reverse the order
        // For simplicity, let's assume we have the original array
    }, size);
    // To implement radix sort properly, you'd need access to the original array
    // Here, we'll assume that 'a' has been normalized already
    // Implementing radix sort with bit manipulation

    // Find the maximum number to know number of bits
    int max = 0;
    t_node *current = a->top;
    while (current)
    {
        if (current->value > max)
            max = current->value;
        current = current->next;
    }

    int max_bits = 0;
    while ((max >> max_bits) != 0)
        max_bits++;

    for (int i = 0; i < max_bits; i++)
    {
        int j = 0;
        int size_a = a->size;
        while (j < size_a)
        {
            int num = pop(a);
            if (((num >> i) & 1) == 1)
            {
                push(a, num);
                ra(a);
            }
            else
            {
                push(b, num);
                pb(a, b);
            }
            j++;
        }
        while (b->size > 0)
            pa(a, b);
    }
    free(normalize); // Placeholder, adjust accordingly
}