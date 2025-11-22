/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eratasoy <eratasoy@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 00:00:00 by eratasoy          #+#    #+#             */
/*   Updated: 2025/11/22 00:00:00 by eratasoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int		count;
	t_stack	*tmp;

	if (!stack)
		return (0);
	count = 0;
	tmp = stack;
	while (1)
	{
		count++;
		tmp = tmp->next;
		if (tmp == stack)
			break ;
	}
	return (count);
}

t_stack	*find_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	return (stack->prev);
}

t_stack	*find_min(t_stack *stack)
{
	t_stack	*min_node;
	t_stack	*tmp;

	if (!stack)
		return (NULL);
	min_node = stack;
	tmp = stack->next;
	while (tmp != stack)
	{
		if (tmp->value < min_node->value)
			min_node = tmp;
		tmp = tmp->next;
	}
	return (min_node);
}

t_stack	*find_max(t_stack *stack)
{
	t_stack	*max_node;
	t_stack	*tmp;

	if (!stack)
		return (NULL);
	max_node = stack;
	tmp = stack->next;
	while (tmp != stack)
	{
		if (tmp->value > max_node->value)
			max_node = tmp;
		tmp = tmp->next;
	}
	return (max_node);
}

int	is_sorted(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		return (1);
	tmp = stack;
	while (tmp->next != stack)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

