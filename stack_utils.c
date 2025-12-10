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

int	size_of_stack(t_stack *stack)
{
	t_stack	*current;
	int		length;

	if (!stack)
		return (0);
	current = stack->next;
	length = 1;
	while (current != stack)
	{
		current = current->next;
		length++;
	}
	return (length);
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
		if (tmp->number < min_node->number)
			min_node = tmp;
		tmp = tmp->next;
	}
	return (min_node);
}

t_stack	*find_max(t_stack *stack)
{
	t_stack	*max_node;
	t_stack	*temp;

	if (!stack)
		return (NULL);
	max_node = stack;
	temp = stack->next;
	while (temp != stack)
	{
		if (temp->number > max_node->number)
			max_node = temp;
		temp = temp->next;
	}
	return (max_node);
}


int	is_sorted(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
		return (1);
	temp = stack;
	while (temp->next != stack)
	{
		if (temp->number > temp->next->number)
			return (0);
		temp = temp->next;
	}
	return (1);
}
