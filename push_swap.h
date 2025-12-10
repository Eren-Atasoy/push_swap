/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eratasoy <eratasoy@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 04:43:49 by eratasoy          #+#    #+#             */
/*   Updated: 2025/11/10 22:07:20 by eratasoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				number;
	int				index;
	int				cost;
	int				is_above_mid;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;


/* *** Operations *** */
void	op_sa(t_stack **a);
void	op_pa(t_stack **a, t_stack **b);
void	op_pb(t_stack **a, t_stack **b);
void	op_ra(t_stack **a);
void	op_rb(t_stack **b);
void	op_rr(t_stack **a, t_stack **b);
void	op_rra(t_stack **a);
void	op_rrb(t_stack **b);
void	op_rrr(t_stack **a, t_stack **b);

/* *** Parsing & Error *** */
long	ft_atol(const char *str);
int	syntax_control(char *str_n);
int	duplicate_control(t_stack *a, int n);
void	error_handler(t_stack **a, char **temp_argv, int flag_split);
void	free_split(char **temp_argv);
void	free_stack(t_stack **stack);

/* *** Stack Utils *** */
t_stack	*create_stack_node(int value);
void	add_stack_node_end(t_stack **stack, t_stack *new_node);
int		size_of_stack(t_stack *stack);
t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);
int		is_sorted(t_stack *stack);

/* *** Turk Algorithm *** */
void	run_turk(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);
void	set_index(t_stack *stack);
void	set_target_a(t_stack *a, t_stack *b);
void	set_target_b(t_stack *a, t_stack *b);
void	mark_optimal(t_stack *a);
t_stack	*fetch_optimal(t_stack *a);
void	elevate_to_top(t_stack **stack, t_stack *top_node, char stack_name);
void	move_a_to_b(t_stack **a, t_stack **b);
void	move_b_to_a(t_stack **a, t_stack **b);

#endif
