/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eratasoy <eratasoy@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 04:43:49 by eratasoy          #+#    #+#             */
/*   Updated: 2025/11/23 00:00:00 by eratasoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	int	tmp;

	if (!stack || stack->next == stack)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
}

void	sa(t_stack **a)
{
	swap(*a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **b)
{
	swap(*b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(*a);
	swap(*b);
	ft_putstr_fd("ss\n", 1);
}