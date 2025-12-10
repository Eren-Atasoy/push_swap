/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eratasoy <eratasoy@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 00:00:00 by eratasoy          #+#    #+#             */
/*   Updated: 2025/11/22 00:00:00 by eratasoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	cost_analysis(t_stack *a, t_stack *b)
{
	int		size_of_a;
	int		size_of_b;
	t_stack	*temp;
	int		i;

	size_of_a = size_of_stack(a);
	size_of_b = size_of_stack(b);
	temp = a;
	i = 0;
	while (i < size_of_a)
	{
		temp->cost = temp->index;
		if (!temp->is_above_mid)
			temp->cost = size_of_a - temp->index;
		if (temp->target->is_above_mid)
			temp->cost += temp->target->index;
		else
			temp->cost += size_of_b - temp->target->index;
		temp = temp->next;
		i++;
	}
}

static void	exec_pass_one(t_stack **a, t_stack **b)
{
	int	length;

	length = size_of_stack(*a);
	while (length-- > 3 && !is_sorted(*a))
	{
		set_index(*a);
		set_index(*b);

		set_target_b(*a, *b);
		cost_analysis(*a, *b);
		mark_optimal(*a);
		move_a_to_b(a, b);
		
	}
}

static void	min_on_top(t_stack **a)
{
	t_stack	*min_node;

	min_node = find_min(*a);
	while (*a != min_node)
	{
		if (min_node->is_above_mid)
			op_ra(a);
		else
			op_rra(a);
	}
}

static void	exec_pass_two(t_stack **a, t_stack **b)
{
	while (*b)
	{
		set_index(*a);
		set_index(*b);
		set_target_a(*a, *b);
		move_b_to_a(a, b);
	}
	set_index(*a);
	min_on_top(a);
}

void	run_turk(t_stack **a, t_stack **b)
{
	int	length;

	length = size_of_stack(*a);
	if (length > 3 && !is_sorted(*a))
	{
		op_pb(a, b);
	}
	length = length - 1;
	if (length > 3 && !is_sorted(*a))
	{
		op_pb(a, b);
	}
	length = length - 1;
	exec_pass_one(a, b);
	sort_three(a);
	exec_pass_two(a, b);
}