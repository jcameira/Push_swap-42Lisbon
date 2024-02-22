/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcameira <jcameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:21:05 by jcameira          #+#    #+#             */
/*   Updated: 2023/11/21 22:59:14 by jcameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../complete_lib/ft_printf/ft_printf.h"
# include "../complete_lib/libft/libft.h"
# include "../complete_lib/get_next_line/get_next_line_bonus.h"

typedef struct s_stack
{
	int				nbr;
	int				index;
	struct s_stack	*next;
	struct s_stack	*previous;
}		t_stack;

int		check_string(char *str);
int		check_dups(char **nbr);
int		check_numeric(char *nbr);
int		check_input(int argc, char **argv);
int		issorted(t_stack *stack);
t_stack	*min_node(t_stack *stack);
t_stack	*max_node(t_stack *stack);
int		stacksize(t_stack *stack);
t_stack	*find_first(t_stack *stack);
void	addnode_back(t_stack **stack, t_stack *new);
void	addnode_front(t_stack **stack, t_stack *new);
t_stack	*lastnode(t_stack *stack);
void	free_stack(t_stack **stack);
t_stack	*newnode(int nbr, int index);
t_stack	*fill_stack(int arg_count, char **arg_arr, int init_pos);
t_stack	*parse_input(char *arguments, int init_pos);
void	rotate(t_stack **stack);
void	rev_rotate(t_stack **stack);
void	swap(t_stack **stack);
void	push(t_stack **from, t_stack **to);
void	ra(t_stack **stack_a, int read_flag);
void	rb(t_stack **stack_b, int read_flag);
void	rr(t_stack **stack_a, t_stack **stack_b, int read_flag);
void	rra(t_stack **stack_a, int read_flag);
void	rrb(t_stack **stack_b, int read_flag);
void	rrr(t_stack **stack_a, t_stack **stack_b, int read_flag);
void	sa(t_stack **stack_a, int read_flag);
void	sb(t_stack **stack_b, int read_flag);
void	ss(t_stack **stack_a, t_stack **stack_b, int read_flag);
void	pa(t_stack **stack_a, t_stack **stack_b, int read_flag);
void	pb(t_stack **stack_a, t_stack **stack_b, int read_flag);
void	sort_three(t_stack **stack);
void	push_swap(t_stack **stack_a);
void	fill_stack_b(t_stack **stack_a, t_stack **stack_b);
int		calculations_a_to_b(t_stack *stack_a, t_stack *stack_b, int flag);
int		calculations_b_to_a(t_stack *stack_a, t_stack *stack_b, int flag);
int		nbr_movs_to_pb(t_stack *stack_b, int nbr_to_push);
int		nbr_movs_to_pa(t_stack *stack_a, int nbr_to_push);
int		get_nbr_movs_rarb(t_stack *stack_a, t_stack *stack_b,
			t_stack *node_to_push, int flag);
int		get_nbr_movs_rrarrb(t_stack *stack_a, t_stack *stack_b,
			t_stack *node_to_push, int flag);
int		get_nbr_movs_rrarb(t_stack *stack_a, t_stack *stack_b,
			t_stack *node_to_push, int flag);
int		get_nbr_movs_rarrb(t_stack *stack_a, t_stack *stack_b,
			t_stack *node_to_push, int flag);
int		apply_movs_rarb(t_stack **stack_a, t_stack **stack_b,
			t_stack *node_to_push, int flag);
int		apply_movs_rrarrb(t_stack **stack_a, t_stack **stack_b,
			t_stack *node_to_push, int flag);
int		apply_movs_rrarb(t_stack **stack_a, t_stack **stack_b,
			t_stack *node_to_push, int flag);
int		apply_movs_rarrb(t_stack **stack_a, t_stack **stack_b,
			t_stack *node_to_push, int flag);

#endif