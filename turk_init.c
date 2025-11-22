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

void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*target_node;
	t_stack	*tmp_a;
	long	best_match_index;

	current_b = b;
	while (1)
	{
		best_match_index = 2147483648;
		tmp_a = a;
		while (1)
		{
			if (tmp_a->value > current_b->value
				&& tmp_a->value < best_match_index)
			{
				best_match_index = tmp_a->value;
				target_node = tmp_a;
			}
			tmp_a = tmp_a->next;
			if (tmp_a == a)
				break ;
		}
		if (best_match_index == 2147483648)
			current_b->target_node = find_min(a);
		else
			current_b->target_node = target_node;
		current_b = current_b->next;
		if (current_b == b)
			break ;
	}
}

void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	t_stack	*tmp_b;
	long	best_match_index;

	current_a = a;
	while (1)
	{
		best_match_index = -2147483649;
		tmp_b = b;
		while (1)
		{
			if (tmp_b->value < current_a->value
				&& tmp_b->value > best_match_index)
			{
				best_match_index = tmp_b->value;
				target_node = tmp_b;
			}
			tmp_b = tmp_b->next;
			if (tmp_b == b)
				break ;
		}
		if (best_match_index == -2147483649)
			current_a->target_node = find_max(b);
		else
			current_a->target_node = target_node;
		current_a = current_a->next;
		if (current_a == a)
			break ;
	}
}

