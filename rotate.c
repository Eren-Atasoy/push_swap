/* rotate.c */
#include "push_swap.h"

static void rotate(t_stack **stack)
{
    if (!*stack)
        return;
    *stack = (*stack)->next;
}

void ra(t_stack **a)
{
    rotate(a);
    ft_putstr_fd("ra\n", 1); // [cite: 244]
}

void rb(t_stack **b)
{
    rotate(b);
    ft_putstr_fd("rb\n", 1); // [cite: 244]
}

void rr(t_stack **a, t_stack **b)
{
    rotate(a);
    rotate(b);
    ft_putstr_fd("rr\n", 1); // [cite: 244]
}