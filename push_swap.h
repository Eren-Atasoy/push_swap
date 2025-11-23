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
	int				value;
	int				index;
	int				push_cost;
	int				above_median;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

/* *** Operations *** */
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

/* *** Parsing & Error *** */
long	ft_atol(const char *str);
int		check_syntax(char *str_n);
int		check_duplicate(t_stack *a, int n);
void	error_handler(char *message);
void	error_exit(t_stack **a, char **tmp_argv, int flag_split);
void	free_matrix(char **argv);
void	free_stack(t_stack **stack);

/* *** Stack Utils *** */
t_stack	*create_stack_node(int value);
void	add_stack_node_end(t_stack **stack, t_stack *new_node);
int		stack_size(t_stack *stack);
t_stack	*find_last(t_stack *stack);
t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);
int		is_sorted(t_stack *stack);

/* *** Turk Algorithm *** */
void	sort_stack(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);
void	set_index(t_stack *stack);
void	set_target_a(t_stack *a, t_stack *b);
void	set_target_b(t_stack *a, t_stack *b);
void	cost_analysis_a(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *stack);
t_stack	*get_cheapest(t_stack *stack);
void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name);
void	move_a_to_b(t_stack **a, t_stack **b);
void	move_b_to_a(t_stack **a, t_stack **b);

#endif
