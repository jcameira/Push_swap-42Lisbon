/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_nbr_moves_to_push.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcameira <jcameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 23:38:01 by jcameira          #+#    #+#             */
/*   Updated: 2024/03/06 01:19:25 by jcameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_moves	get_nbr_movs_rarb(t_stack *stack_a, t_stack *stack_b,
	t_stack *node_to_push, int flag)
{
	t_moves	nbr_movs;

	if (!flag)
	{
		nbr_movs.moves = nbr_movs_to_pb(stack_b, node_to_push->nbr);
		if (nbr_movs.moves < node_to_push->index)
			nbr_movs.moves = node_to_push->index;
	}
	else
	{
		nbr_movs.moves = nbr_movs_to_pa(stack_a, node_to_push->nbr);
		if (nbr_movs.moves < node_to_push->index)
			nbr_movs.moves = node_to_push->index;
	}
	nbr_movs.node = node_to_push;
	nbr_movs.type = R_R;
	return (nbr_movs);
}

t_moves	get_nbr_movs_rrarrb(t_stack *stack_a, t_stack *stack_b,
	t_stack *node_to_push, int flag)
{
	t_moves	nbr_movs;

	nbr_movs.moves = 0;
	if (!flag)
	{
		if (nbr_movs_to_pb(stack_b, node_to_push->nbr))
			nbr_movs.moves = stacksize(stack_b)
				- nbr_movs_to_pb(stack_b, node_to_push->nbr);
		if (nbr_movs.moves < stacksize(stack_a)
			- (node_to_push->index) && node_to_push->index)
			nbr_movs.moves = stacksize(stack_a) - (node_to_push->index);
	}
	else
	{
		if (nbr_movs_to_pb(stack_a, node_to_push->nbr))
			nbr_movs.moves = stacksize(stack_a)
				- nbr_movs_to_pa(stack_a, node_to_push->nbr);
		if (nbr_movs.moves < stacksize(stack_b)
			- (node_to_push->index) && node_to_push->index)
			nbr_movs.moves = stacksize(stack_b) - (node_to_push->index);
	}
	nbr_movs.node = node_to_push;
	nbr_movs.type = RR_RR;
	return (nbr_movs);
}

t_moves	get_nbr_movs_rrarb(t_stack *stack_a, t_stack *stack_b,
	t_stack *node_to_push, int flag)
{
	t_moves	nbr_movs;

	nbr_movs.moves = 0;
	if (!flag)
	{
		if (node_to_push->index)
			nbr_movs.moves = stacksize(stack_a) - (node_to_push->index);
		nbr_movs.moves += nbr_movs_to_pb(stack_b, node_to_push->nbr);
	}
	else
	{
		if (node_to_push->index)
			nbr_movs.moves = stacksize(stack_b) - (node_to_push->index);
		nbr_movs.moves += nbr_movs_to_pa(stack_a, node_to_push->nbr);
	}
	nbr_movs.node = node_to_push;
	nbr_movs.type = RR_R;
	return (nbr_movs);
}

t_moves	get_nbr_movs_rarrb(t_stack *stack_a, t_stack *stack_b,
	t_stack *node_to_push, int flag)
{
	t_moves	nbr_movs;

	nbr_movs.moves = 0;
	if (!flag)
	{
		if (nbr_movs_to_pb(stack_b, node_to_push->nbr))
			nbr_movs.moves = stacksize(stack_b)
				- nbr_movs_to_pb(stack_b, node_to_push->nbr);
		nbr_movs.moves += node_to_push->index;
	}
	else
	{
		if (nbr_movs_to_pb(stack_a, node_to_push->nbr))
			nbr_movs.moves = stacksize(stack_a)
				- nbr_movs_to_pa(stack_a, node_to_push->nbr);
		nbr_movs.moves += node_to_push->index;
	}
	nbr_movs.node = node_to_push;
	nbr_movs.type = R_RR;
	return (nbr_movs);
}
