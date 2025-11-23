/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eratasoy <eratasoy@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 00:00:00 by eratasoy          #+#    #+#             */
/*   Updated: 2025/11/22 00:00:00 by eratasoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack *stack)
{
	int		i;
	int		median;
	t_stack	*tmp;

	if (!stack)
		return ;
	i = 0;
	median = stack_size(stack) / 2;
	tmp = stack;
	while (1)
	{
		tmp->index = i;
		if (i <= median)
			tmp->above_median = 1;
		else
			tmp->above_median = 0;
		tmp = tmp->next;
		i++;
		if (tmp == stack)
			break ;
	}
}

static t_stack	*find_target_a(t_stack *a, int b_value)
{
	t_stack	*target_node;
	t_stack	*tmp;
	long	best_match;

	best_match = 2147483648;
	tmp = a;
	target_node = NULL;
	while (1)
	{
		if (tmp->value > b_value && tmp->value < best_match)
		{
			best_match = tmp->value;
			target_node = tmp;
		}
		tmp = tmp->next;
		if (tmp == a)
			break ;
	}
	if (best_match == 2147483648)
		return (find_min(a));
	return (target_node);
}

void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack	*current_b;

	current_b = b;
	while (1)
	{
		current_b->target_node = find_target_a(a, current_b->value);
		current_b = current_b->next;
		if (current_b == b)
			break ;
	}
}

static t_stack	*find_target_b(t_stack *b, int a_value)
{
	t_stack	*target_node;
	t_stack	*tmp;
	long	best_match;

	best_match = -2147483649;
	tmp = b;
	target_node = NULL;
	while (1)
	{
		if (tmp->value < a_value && tmp->value > best_match)
		{
			best_match = tmp->value;
			target_node = tmp;
		}
		tmp = tmp->next;
		if (tmp == b)
			break ;
	}
	if (best_match == -2147483649)
		return (find_max(b));
	return (target_node);
}

void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack	*current_a;

	current_a = a;
	while (1)
	{
		current_a->target_node = find_target_b(b, current_a->value);
		current_a = current_a->next;
		if (current_a == a)
			break ;
	}
}
