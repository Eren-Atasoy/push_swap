/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eratasoy <eratasoy@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 04:43:49 by eratasoy          #+#    #+#             */
/*   Updated: 2025/11/23 00:00:00 by eratasoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*remove_from_src(t_stack **src)
{
	t_stack	*tmp;
	t_stack	*src_last;

	if (!*src)
		return (NULL);
	tmp = *src;
	if (tmp->next == tmp)
		*src = NULL;
	else
	{
		src_last = tmp->prev;
		src_last->next = tmp->next;
		tmp->next->prev = src_last;
		*src = tmp->next;
	}
	return (tmp);
}

static void	add_to_dst(t_stack **dst, t_stack *node)
{
	t_stack	*dst_last;

	if (!*dst)
	{
		*dst = node;
		node->next = node;
		node->prev = node;
	}
	else
	{
		dst_last = (*dst)->prev;
		node->next = *dst;
		node->prev = dst_last;
		dst_last->next = node;
		(*dst)->prev = node;
		*dst = node;
	}
}

static void	push(t_stack **dst, t_stack **src)
{
	t_stack	*tmp;

	tmp = remove_from_src(src);
	if (tmp)
		add_to_dst(dst, tmp);
}

void	op_pa(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_putstr_fd("pa\n", 1);
}

void	op_pb(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_putstr_fd("pb\n", 1);
}