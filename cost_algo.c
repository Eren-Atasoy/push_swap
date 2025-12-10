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

void	mark_optimal(t_stack *a)
{
	long	cheapest_value;
	t_stack	*cheapest_node;
	t_stack	*temp;
	int		size;
	int		i;

	if (!a)
		return ;
	cheapest_value = 2147483647;
	size = size_of_stack(a);
	temp = a;
	i = 0;
	while (i < size)
	{
		if (temp->cost < cheapest_value)
		{
			cheapest_value = temp->cost;
			cheapest_node = temp;
		}
		temp = temp->next;
		i++;
	}
	cheapest_node->cost = -1;
}

t_stack	*fetch_optimal(t_stack *a)
{
	t_stack	*tmp;

	if (!a)
		return (NULL);
	tmp = a;
	if (tmp->cost == -1)
		return (tmp);
	tmp = tmp->next;
	while (tmp != a)
	{
		if (tmp->cost == -1)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}