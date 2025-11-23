/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eratasoy <eratasoy@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 04:43:49 by eratasoy          #+#    #+#             */
/*   Updated: 2025/11/23 00:00:00 by eratasoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_handler(char *message)
{
	ft_putstr_fd(message, 2);
	exit(EXIT_FAILURE);
}

void	error_exit(t_stack **a, char **tmp_argv, int flag_split)
{
	if (a && *a)
		free_stack(a);
	if (flag_split && tmp_argv)
		free_matrix(tmp_argv);
	write(2, "Error\n", 6);
	exit(1);
}