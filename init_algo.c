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
	int		size;
	int		median;
	t_stack	*temp;

	if (!stack)
		return ;
	size = size_of_stack(stack);
	median = size / 2;
	temp = stack;
	i = 0;
	while (i < size)
	{
		temp->index = i;
		if (i <= median)
			temp->is_above_mid = 1;
		else
			temp->is_above_mid = 0;
		temp = temp->next;
		i++;
	}
}

static t_stack	*find_target_a(t_stack *a, int b_value)
{
	t_stack	*target_node;
	t_stack	*tmp;
	long	closest_value;

	if (!a)
		return (NULL);
	closest_value = 2147483648;
	tmp = a;
	target_node = NULL;
	while (1)
	{
		if (tmp->number > b_value && tmp->number < closest_value)
		{
			closest_value = tmp->number;
			target_node = tmp;
		}
		tmp = tmp->next;
		if (tmp == a)
			break ;
	}
	if (closest_value == 2147483648)
		return (find_min(a));
	return (target_node);
}

void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack	*current_b;

	current_b = b;
	while (1)
	{
		current_b->target = find_target_a(a, current_b->number);
		current_b = current_b->next;
		if (current_b == b)
			break ;
	}
}

static t_stack	*find_target_b(t_stack *b, int a_value)
{
	t_stack	*target_node;
	t_stack	*temp;
	long	closest_value;
	int		size;
	int		i;

	if (!b)
		return (NULL);
	closest_value = -2147483649;
	target_node = NULL;
	size = size_of_stack(b);
	temp = b;
	i = 0;
	while (i < size)
	{
		if (temp->number < a_value && temp->number > closest_value)
		{
			closest_value = temp->number;
			target_node = temp;
		}
		temp = temp->next;
		i++;
	}
	if (closest_value == -2147483649)
		return (find_max(b));
	return (target_node);
}

void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	int		size;
	int		i;

	if (!b)
		return ;
	size = size_of_stack(a);
	current_a = a;
	i = 0;
	while (i < size)
	{
		current_a->target = find_target_b(b, current_a->number);
		current_a = current_a->next;
		i++;
	}
}