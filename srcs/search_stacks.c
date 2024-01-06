/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcameira <jcameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:33:05 by jcameira          #+#    #+#             */
/*   Updated: 2023/11/19 18:34:22 by jcameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*min_node(t_stack *stack)
{
	t_stack	*min;
	t_stack	*tmp;

	tmp = stack;
	min = stack;
	stack = stack->next;
	while (stack != tmp)
	{
		if (stack->nbr < min->nbr)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_stack	*max_node(t_stack *stack)
{
	t_stack	*max;
	t_stack	*tmp;

	tmp = stack;
	max = stack;
	stack = stack->next;
	while (stack != tmp)
	{
		if (stack->nbr > max->nbr)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

t_stack	*find_first(t_stack *stack)
{
	if (stack->index >= stacksize(stack) / 2)
		while (stack->index != 1)
			stack = stack->next;
	else
		while (stack->index != 1)
			stack = stack->previous;
	return (stack);
}

t_stack	*lastnode(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->index != stacksize(stack))
		stack = stack->next;
	return (stack);
}
