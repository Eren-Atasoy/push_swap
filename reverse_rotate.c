/* reverse_rotate.c */
#include "push_swap.h"

static void reverse_rotate(t_stack **stack)
{
    if (!*stack)
        return;
    *stack = (*stack)->prev;
}

void rra(t_stack **a)
{
    reverse_rotate(a);
    ft_putstr_fd("rra\n", 1); // [cite: 244]
}

void rrb(t_stack **b)
{
    reverse_rotate(b);
    ft_putstr_fd("rrb\n", 1); // [cite: 244]
}

void rrr(t_stack **a, t_stack **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    ft_putstr_fd("rrr\n", 1); // [cite: 244]
}