#include "../includes/push_swap.h"

void push(t_stack *stack, int value)
{
    t_node *new = malloc(sizeof(t_node));
    if (!new)
        exit(EXIT_FAILURE);
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
    return val;
}

int is_sorted(t_stack *a)
{
    if (!a->top || a->size < 2)
        return 1;
    t_node *current = a->top;
    while (current->next)
    {
        if (current->value > current->next->value)
            return 0;
        current = current->next;
    }
    return 1;
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

// Normalize the array
int *normalize(int *arr, int size)
{
    int *sorted = malloc(sizeof(int) * size);
    if (!sorted)
    {
        ft_printf("Error\n");
    }
    ft_memcpy(sorted, arr, sizeof(int) * size); 
    // Simple Bubble Sort for normalization
    int i = 0;
    while (i < size - 1)
    {
        int j = 0;
        while (j < size - i - 1)
        {
            if (sorted[j] > sorted[j + 1])
            {
                int temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
    // Assign index
    int *normalized = malloc(sizeof(int) * size);
    if (!normalized)
    {
        free(sorted);
        ft_printf("Error\n");
    }
    int k = 0;
    while (k < size)
    {
        int l = 0;
        while (l < size)
        {
            if (arr[k] == sorted[l])
            {
                normalized[k] = l;
                break;
            }
            l++;
        }
        k++;
    }
    free(sorted);
    return normalized;
}

// Radix Sort Implementation
void radix_sort(t_stack *a, t_stack *b, int size)
{
    // Extract stack a into an array to have normalized indices
    int *arr = malloc(sizeof(int) * size);
    if (!arr)
        ft_printf("Error\n");

    t_node *current = a->top;
    int idx = 0;
    while (current)
    {
        arr[idx++] = current->value;
        current = current->next;
    }

    // Normalize
    int *normalized = normalize(arr, size);
    free(arr);

    // Replace stack a's values with normalized indices
    current = a->top;
    idx = 0;
    while (current)
    {
        current->value = normalized[idx++];
        current = current->next;
    }

    // Find the maximum number to know number of bits
    int max = 0;
    idx = 0;
    while (idx < size)
    {
        if (normalized[idx] > max)
            max = normalized[idx];
        idx++;
    }

    int max_bits = 0;
    while ((max >> max_bits) != 0)
        max_bits++;

    int bit = 0;
    while (bit < max_bits)
    {
        int i = 0;
        while (i < size)
        {
            if (((a->top->value >> bit) & 1) == 1)
                ra(a);
            else
                pb(a, b);
            i++;
        }
        while (b->size > 0)
            pa(a, b);
        bit++;
    }
    free(normalized);
}
