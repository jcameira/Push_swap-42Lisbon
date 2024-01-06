/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcameira <jcameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:17:34 by jcameira          #+#    #+#             */
/*   Updated: 2023/11/21 10:44:03 by jcameira         ###   ########.fr       */
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
