/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eratasoy <eratasoy@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 04:43:49 by eratasoy          #+#    #+#             */
/*   Updated: 2025/11/23 00:00:00 by eratasoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_up(t_stack **a, char *arg)
{
	char	**temp_argv;
	t_stack	*new_node;
	int		i;
	long	number;

	temp_argv = ft_split(arg, ' ');
	if (!temp_argv || !*temp_argv)
		error_handler(a, temp_argv, 1);
	i = 0;
	while (temp_argv[i])
	{
		if (!syntax_control(temp_argv[i]))
			error_handler(a, temp_argv, 1);
		number = ft_atol(temp_argv[i]);
		if (number > 2147483647 || number < -2147483648)
			error_handler(a, temp_argv, 1);
		if (duplicate_control(*a, (int)number))
			error_handler(a, temp_argv, 1);
		new_node = create_stack_node((int)number);
		if (!new_node)
			error_handler(a, temp_argv, 1);
		add_stack_node_end(a, new_node);
		i++;
	}
	free_split(temp_argv);
}

static void	sort(t_stack **a, t_stack **b)
{
	if (is_sorted(*a))
		return ;
	if (size_of_stack(*a) == 2)
		op_sa(a);
	else if (size_of_stack(*a) == 3)
		sort_three(a);
	else
		run_turk(a, b);
}

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	int i;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	i = 1;
	while (i < argc)
	{
		stack_up(&a, argv[i]);
		i++;
	}
	sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}