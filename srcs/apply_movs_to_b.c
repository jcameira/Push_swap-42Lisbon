/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_movs_to_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcameira <jcameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 01:26:05 by jcameira          #+#    #+#             */
/*   Updated: 2023/11/21 10:49:24 by jcameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	apply_movs_rarb(t_stack **stack_a, t_stack **stack_b,
	t_stack *node_to_push, int flag)
{
	if (!flag)
	{
		while (find_first(*stack_a)->nbr != node_to_push->nbr
			&& nbr_movs_to_pb(*stack_b, node_to_push->nbr) > 0)
			rr(stack_a, stack_b, 0);
		while (find_first(*stack_a)->nbr != node_to_push->nbr)
			ra(stack_a, 0);
		while (nbr_movs_to_pb(*stack_b, node_to_push->nbr) > 0)
			rb(stack_b, 0);
		pb(stack_a, stack_b, 0);
	}
	else
	{
		while (find_first(*stack_b)->nbr != node_to_push->nbr
			&& nbr_movs_to_pa(*stack_a, node_to_push->nbr) > 0)
			rr(stack_a, stack_b, 0);
		while (find_first(*stack_b)->nbr != node_to_push->nbr)
			rb(stack_b, 0);
		while (nbr_movs_to_pa(*stack_a, node_to_push->nbr) > 0)
			ra(stack_a, 0);
		pa(stack_a, stack_b, 0);
	}
	return (-1);
}

int	apply_movs_rrarrb(t_stack **stack_a, t_stack **stack_b,
	t_stack *node_to_push, int flag)
{
	if (!flag)
	{
		while (find_first(*stack_a)->nbr != node_to_push->nbr
			&& nbr_movs_to_pb(*stack_b, node_to_push->nbr) > 0)
			rrr(stack_a, stack_b, 0);
		while (find_first(*stack_a)->nbr != node_to_push->nbr)
			rra(stack_a, 0);
		while (nbr_movs_to_pb(*stack_b, node_to_push->nbr) > 0)
			rrb(stack_b, 0);
		pb(stack_a, stack_b, 0);
	}
	else
	{
		while (find_first(*stack_b)->nbr != node_to_push->nbr
			&& nbr_movs_to_pa(*stack_a, node_to_push->nbr) > 0)
			rrr(stack_a, stack_b, 0);
		while (find_first(*stack_b)->nbr != node_to_push->nbr)
			rrb(stack_b, 0);
		while (nbr_movs_to_pa(*stack_a, node_to_push->nbr) > 0)
			rra(stack_a, 0);
		pa(stack_a, stack_b, 0);
	}
	return (-1);
}

int	apply_movs_rrarb(t_stack **stack_a, t_stack **stack_b,
	t_stack *node_to_push, int flag)
{
	if (!flag)
	{
		while (find_first(*stack_a)->nbr != node_to_push->nbr)
			rra(stack_a, 0);
		while (nbr_movs_to_pb(*stack_b, node_to_push->nbr) > 0)
			rb(stack_b, 0);
		pb(stack_a, stack_b, 0);
	}
	else
	{
		while (find_first(*stack_b)->nbr != node_to_push->nbr)
			rrb(stack_b, 0);
		while (nbr_movs_to_pa(*stack_a, node_to_push->nbr) > 0)
			ra(stack_a, 0);
		pa(stack_a, stack_b, 0);
	}
	return (-1);
}

int	apply_movs_rarrb(t_stack **stack_a, t_stack **stack_b,
	t_stack *node_to_push, int flag)
{
	if (!flag)
	{
		while (find_first(*stack_a)->nbr != node_to_push->nbr)
			ra(stack_a, 0);
		while (nbr_movs_to_pb(*stack_b, node_to_push->nbr) > 0)
			rrb(stack_b, 0);
		pb(stack_a, stack_b, 0);
	}
	else
	{
		while (find_first(*stack_b)->nbr != node_to_push->nbr)
			rb(stack_b, 0);
		while (nbr_movs_to_pa(*stack_a, node_to_push->nbr) > 0)
			rra(stack_a, 0);
		pa(stack_a, stack_b, 0);
	}
	return (-1);
}
