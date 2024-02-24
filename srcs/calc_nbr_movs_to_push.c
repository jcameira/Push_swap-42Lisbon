/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_nbr_movs_to_push.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcameira <jcameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:28:10 by jcameira          #+#    #+#             */
/*   Updated: 2024/02/24 00:52:12 by jcameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_nbr_movs_rarb(t_stack *stack_a, t_stack *stack_b,
	t_stack *node_to_push, int flag)
{
	int	nbr_movs;

	if (!flag)
	{
		nbr_movs = nbr_movs_to_pb(stack_b, node_to_push->nbr);
		if (nbr_movs < node_to_push->index - 1)
			nbr_movs = node_to_push->index - 1;
	}
	else
	{
		nbr_movs = nbr_movs_to_pa(stack_a, node_to_push->nbr);
		if (nbr_movs < node_to_push->index - 1)
			nbr_movs = node_to_push->index - 1;
	}
	return (nbr_movs);
}

int	get_nbr_movs_rrarrb(t_stack *stack_a, t_stack *stack_b,
	t_stack *node_to_push, int flag)
{
	int	nbr_movs;

	nbr_movs = 0;
	if (!flag)
	{
		if (nbr_movs_to_pb(stack_b, node_to_push->nbr))
			nbr_movs = stacksize(stack_b)
				- nbr_movs_to_pb(stack_b, node_to_push->nbr);
		if (nbr_movs < stacksize(stack_a)
			- (node_to_push->index - 1) && node_to_push->index != 1)
			nbr_movs = stacksize(stack_a) - (node_to_push->index - 1);
	}
	else
	{
		if (nbr_movs_to_pb(stack_a, node_to_push->nbr))
			nbr_movs = stacksize(stack_a)
				- nbr_movs_to_pa(stack_a, node_to_push->nbr);
		if (nbr_movs < stacksize(stack_b)
			- (node_to_push->index - 1) && node_to_push->index != 1)
			nbr_movs = stacksize(stack_b) - (node_to_push->index - 1);
	}
	return (nbr_movs);
}

int	get_nbr_movs_rrarb(t_stack *stack_a, t_stack *stack_b,
	t_stack *node_to_push, int flag)
{
	int	nbr_movs;

	nbr_movs = 0;
	if (!flag)
	{
		if (node_to_push->index != 1)
			nbr_movs = stacksize(stack_a) - (node_to_push->index - 1);
		nbr_movs += nbr_movs_to_pb(stack_b, node_to_push->nbr);
	}
	else
	{
		if (node_to_push->index != 1)
			nbr_movs = stacksize(stack_b) - (node_to_push->index - 1);
		nbr_movs += nbr_movs_to_pa(stack_a, node_to_push->nbr);
	}
	return (nbr_movs);
}

int	get_nbr_movs_rarrb(t_stack *stack_a, t_stack *stack_b,
	t_stack *node_to_push, int flag)
{
	int	nbr_movs;

	nbr_movs = 0;
	if (!flag)
	{
		if (nbr_movs_to_pb(stack_b, node_to_push->nbr))
			nbr_movs = stacksize(stack_b)
				- nbr_movs_to_pb(stack_b, node_to_push->nbr);
		nbr_movs += node_to_push->index - 1;
	}
	else
	{
		if (nbr_movs_to_pb(stack_a, node_to_push->nbr))
			nbr_movs = stacksize(stack_a)
				- nbr_movs_to_pa(stack_a, node_to_push->nbr);
		nbr_movs += node_to_push->index - 1;
	}
	return (nbr_movs);
}
