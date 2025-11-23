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

static void	process_argument(t_stack **a, char *arg)
{
	char	**tmp_argv;
	int		j;
	long	n;

	tmp_argv = ft_split(arg, ' ');
	if (!tmp_argv || !*tmp_argv)
		error_exit(a, tmp_argv, 1);
	j = 0;
	while (tmp_argv[j])
	{
		if (!check_syntax(tmp_argv[j]))
			error_exit(a, tmp_argv, 1);
		n = ft_atol(tmp_argv[j]);
		if (n > 2147483647 || n < -2147483648)
			error_exit(a, tmp_argv, 1);
		if (check_duplicate(*a, (int)n))
			error_exit(a, tmp_argv, 1);
		add_stack_node_end(a, create_stack_node((int)n));
		j++;
	}
	free_matrix(tmp_argv);
}

static void	init_stacks(t_stack **a, t_stack **b, int argc, char **argv)
{
	int	i;

	*a = NULL;
	*b = NULL;
	i = 1;
	while (i < argc)
	{
		process_argument(a, argv[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	init_stacks(&a, &b, argc, argv);
	if (!is_sorted(a))
	{
		if (stack_size(a) == 2)
			sa(&a);
		else if (stack_size(a) == 3)
			sort_three(&a);
		else
			sort_stack(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}