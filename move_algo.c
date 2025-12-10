/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eratasoy <eratasoy@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 00:00:00 by eratasoy          #+#    #+#             */
/*   Updated: 2025/11/22 00:00:00 by eratasoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	elevate_to_top(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->is_above_mid)
				op_ra(stack);
			else
				op_rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->is_above_mid)
				op_rb(stack);
			else
				op_rrb(stack);
		}
	}
}

static void	shift_rotate_ab(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node && *b != cheapest_node->target)
		op_rr(a, b);
	set_index(*a);
	set_index(*b);
}

static void	rev_shift_rotate_ab(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node && *b != cheapest_node->target)
		op_rrr(a, b);
	set_index(*a);
	set_index(*b);
}

void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*optimal_node;

	optimal_node = fetch_optimal(*a);
	if (optimal_node->target && optimal_node->is_above_mid
		&& optimal_node->target->is_above_mid)
	{
		shift_rotate_ab(a, b, optimal_node);
	}
	else if (optimal_node->target && !(optimal_node->is_above_mid)
		&& !(optimal_node->target->is_above_mid))
	{
		rev_shift_rotate_ab(a, b, optimal_node);
	}
	elevate_to_top(a, optimal_node, 'a');
	if (optimal_node->target)
	{
		elevate_to_top(b, optimal_node->target, 'b');
	}
	op_pb(a, b);
}

void	move_b_to_a(t_stack **a, t_stack **b)
{
	elevate_to_top(a, (*b)->target, 'a');
	op_pa(a, b);
}
