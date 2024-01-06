/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcameira <jcameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:00:42 by jcameira          #+#    #+#             */
/*   Updated: 2023/11/21 21:17:57 by jcameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	t_stack	*min;
	t_stack	*max;

	*stack = find_first(*stack);
	min = min_node(*stack);
	max = max_node(*stack);
	if ((*stack)->nbr == min->nbr)
	{
		rra(stack, 0);
		sa(stack, 0);
	}
	else if ((*stack)->nbr == max->nbr)
	{
		ra(stack, 0);
		if (!issorted((*stack)))
			sa(stack, 0);
	}
	else
	{
		if ((*stack)->next->nbr == max->nbr)
			rra(stack, 0);
		else
			sa(stack, 0);
	}
}

void	refill_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	int		nbr_mov;
	t_stack	*tmp;

	while (*stack_b)
	{
		tmp = *stack_b;
		nbr_mov = calculations_b_to_a(*stack_a, *stack_b, 1);
		while (nbr_mov >= 0)
		{
			if (nbr_mov == get_nbr_movs_rarb(*stack_a, *stack_b, tmp, 1))
				nbr_mov = apply_movs_rarb(stack_a, stack_b, tmp, 1);
			else if (nbr_mov == get_nbr_movs_rrarrb(*stack_a, *stack_b, tmp, 1))
				nbr_mov = apply_movs_rrarrb(stack_a, stack_b, tmp, 1);
			else if (nbr_mov == get_nbr_movs_rrarb(*stack_a, *stack_b, tmp, 1))
				nbr_mov = apply_movs_rrarb(stack_a, stack_b, tmp, 1);
			else if (nbr_mov == get_nbr_movs_rarrb(*stack_a, *stack_b, tmp, 1))
				nbr_mov = apply_movs_rarrb(stack_a, stack_b, tmp, 1);
			else
				tmp = tmp->next;
		}
	}
}

void	sort_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	int		nbr_mov;
	t_stack	*tmp;

	while (stacksize(*stack_a) > 3 && !issorted(*stack_a))
	{
		tmp = *stack_a;
		nbr_mov = calculations_a_to_b(*stack_a, *stack_b, 0);
		while (nbr_mov >= 0)
		{
			if (nbr_mov == get_nbr_movs_rarb(*stack_a, *stack_b, tmp, 0))
				nbr_mov = apply_movs_rarb(stack_a, stack_b, tmp, 0);
			else if (nbr_mov == get_nbr_movs_rrarrb(*stack_a, *stack_b, tmp, 0))
				nbr_mov = apply_movs_rrarrb(stack_a, stack_b, tmp, 0);
			else if (nbr_mov == get_nbr_movs_rrarb(*stack_a, *stack_b, tmp, 0))
				nbr_mov = apply_movs_rrarb(stack_a, stack_b, tmp, 0);
			else if (nbr_mov == get_nbr_movs_rarrb(*stack_a, *stack_b, tmp, 0))
				nbr_mov = apply_movs_rarrb(stack_a, stack_b, tmp, 0);
			else
				tmp = tmp->next;
		}
	}
}

void	fill_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	if (stacksize(*stack_a) > 3 && !issorted(*stack_a))
		pb(stack_a, stack_b, 0);
	if (stacksize(*stack_a) > 3 && !issorted(*stack_a))
		pb(stack_a, stack_b, 0);
	if (stacksize(*stack_a) > 3 && !issorted(*stack_a))
		sort_stack_b(stack_a, stack_b);
	if (!issorted(*stack_a))
		sort_three(stack_a);
}

void	push_swap(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (stacksize(*stack_a) == 2)
		sa(stack_a, 0);
	else
	{
		fill_stack_b(stack_a, &stack_b);
		refill_stack_a(stack_a, &stack_b);
		if (min_node(*stack_a)->index <= stacksize(*stack_a) / 2)
			while (find_first(*stack_a)->nbr != min_node(*stack_a)->nbr)
				ra(stack_a, 0);
		else
			while (find_first(*stack_a)->nbr != min_node(*stack_a)->nbr)
				rra(stack_a, 0);
	}
	free_stack(&stack_b);
}
