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

static void	cost_analysis_b(t_stack *a, t_stack *b)
{
	int		len_a;
	int		len_b;
	t_stack	*tmp;

	len_a = stack_size(a);
	len_b = stack_size(b);
	tmp = a;
	while (1)
	{
		tmp->push_cost = tmp->index;
		if (!tmp->above_median)
			tmp->push_cost = len_a - tmp->index;
		if (tmp->target_node->above_median)
			tmp->push_cost += tmp->target_node->index;
		else
			tmp->push_cost += len_b - tmp->target_node->index;
		tmp = tmp->next;
		if (tmp == a)
			break ;
	}
}

static void	push_init(t_stack **a, t_stack **b)
{
	int	len;

	len = stack_size(*a);
	while (len-- > 3 && !is_sorted(*a))
	{
		set_index(*a);
		set_index(*b);
		set_target_b(*a, *b);
		cost_analysis_b(*a, *b);
		set_cheapest(*a);
		move_a_to_b(a, b);
	}
}

static void	push_back(t_stack **a, t_stack **b)
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

void	sort_stack(t_stack **a, t_stack **b)
{
	int	len;

	len = stack_size(*a);
	if (len-- > 3 && !is_sorted(*a))
		pb(a, b);
	if (len-- > 3 && !is_sorted(*a))
		pb(a, b);
	push_init(a, b);
	sort_three(a);
	push_back(a, b);
}

