/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eratasoy <eratasoy@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 00:00:00 by eratasoy          #+#    #+#             */
/*   Updated: 2025/11/22 00:00:00 by eratasoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost_analysis_a(t_stack *a, t_stack *b)
{
	int		len_a;
	int		len_b;
	t_stack	*tmp;

	len_a = stack_size(a);
	len_b = stack_size(b);
	tmp = b;
	while (1)
	{
		tmp->push_cost = tmp->index;
		if (!tmp->above_median)
			tmp->push_cost = len_b - tmp->index;
		if (tmp->target_node->above_median)
			tmp->push_cost += tmp->target_node->index;
		else
			tmp->push_cost += len_a - tmp->target_node->index;
		tmp = tmp->next;
		if (tmp == b)
			break ;
	}
}

void	set_cheapest(t_stack *stack)
{
	long	cheapest_value;
	t_stack	*cheapest_node;
	t_stack	*tmp;

	if (!stack)
		return ;
	cheapest_value = 2147483647;
	tmp = stack;
	while (1)
	{
		if (tmp->push_cost < cheapest_value)
		{
			cheapest_value = tmp->push_cost;
			cheapest_node = tmp;
		}
		tmp = tmp->next;
		if (tmp == stack)
			break ;
	}
	cheapest_node->push_cost = -1;
}

t_stack	*get_cheapest(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		return (NULL);
	tmp = stack;
	while (1)
	{
		if (tmp->push_cost == -1)
			return (tmp);
		tmp = tmp->next;
		if (tmp == stack)
			break ;
	}
	return (NULL);
}

