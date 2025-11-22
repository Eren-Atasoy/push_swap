/* swap.c */
#include "push_swap.h"

static void swap(t_stack *stack)
{
    int tmp;

    if (!stack || stack->next == stack) // Eleman yoksa veya tek eleman varsa
        return;
    tmp = stack->value;
    stack->value = stack->next->value;
    stack->next->value = tmp;
}

void sa(t_stack **a)
{
    swap(*a);
    ft_putstr_fd("sa\n", 1); // [cite: 244]
}

void sb(t_stack **b)
{
    swap(*b);
    ft_putstr_fd("sb\n", 1); // [cite: 244]
}

void ss(t_stack **a, t_stack **b)
{
    swap(*a);
    swap(*b);
    ft_putstr_fd("ss\n", 1); // [cite: 244]
}