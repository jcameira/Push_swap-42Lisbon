/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcameira <jcameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:21:05 by jcameira          #+#    #+#             */
/*   Updated: 2024/03/07 15:40:56 by jcameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../complete_lib/ft_printf/ft_printf.h"
# include "../complete_lib/libft/libft.h"
# include "../complete_lib/get_next_line/get_next_line_bonus.h"
# include <limits.h>

# define R_R "rarb"
# define R_RR "rarrb"
# define RR_R "rrarb"
# define RR_RR "rrarrb"

typedef struct s_stack
{
	int				nbr;
	int				index;
	struct s_stack	*next;
	struct s_stack	*previous;
}				t_stack;

typedef struct s_moves
{
	int		moves;
	char	*type;
	t_stack	*node;
}				t_moves;

int		issorted(t_stack *stack);
int		check_input(int argc, char **argv);
int		check_numeric(char *str);
int		check_dups(t_stack *stack);
void	free_split(char **split);
void	*free_stack(t_stack **stack);
int		error(char *itoa);
t_stack	*lastnode(t_stack *stack);
t_stack	*min_node(t_stack *stack);
t_stack	*max_node(t_stack *stack);
void	get_index(t_stack **stack);
int		stacksize(t_stack *stack);
void	addnode_back(t_stack **stack, t_stack *new);
void	addnode_front(t_stack **stack, t_stack *new);
t_stack	*newnode(int nbr);
t_stack	*create_stack(char **argc);
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
void	push_swap(t_stack **stack_a);
void	sort_three(t_stack **stack);
t_moves	calculations_a_to_b(t_stack *stack_a, t_stack *stack_b, int flag);
t_moves	calculations_b_to_a(t_stack *stack_a, t_stack *stack_b, int flag);
int		nbr_movs_to_pb(t_stack *stack_b, int nbr_to_push);
int		nbr_movs_to_pa(t_stack *stack_b, int nbr_to_push);
t_moves	get_nbr_movs_rarb(t_stack *stack_a, t_stack *stack_b,
			t_stack *node_to_push, int flag);
t_moves	get_nbr_movs_rrarrb(t_stack *stack_a, t_stack *stack_b,
			t_stack *node_to_push, int flag);
t_moves	get_nbr_movs_rrarb(t_stack *stack_a, t_stack *stack_b,
			t_stack *node_to_push, int flag);
t_moves	get_nbr_movs_rarrb(t_stack *stack_a, t_stack *stack_b,
			t_stack *node_to_push, int flag);
void	apply_movs_rarb(t_stack **stack_a, t_stack **stack_b,
			t_stack *node_to_push, int flag);
void	apply_movs_rrarrb(t_stack **stack_a, t_stack **stack_b,
			t_stack *node_to_push, int flag);
void	apply_movs_rrarb(t_stack **stack_a, t_stack **stack_b,
			t_stack *node_to_push, int flag);
void	apply_movs_rarrb(t_stack **stack_a, t_stack **stack_b,
			t_stack *node_to_push, int flag);

#endif