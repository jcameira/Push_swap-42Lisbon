/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcameira <jcameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:16:14 by jcameira          #+#    #+#             */
/*   Updated: 2023/11/21 10:54:38 by jcameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*tmp;

	if (!(*stack) || stacksize(*stack) == 1)
		return ;
	*stack = find_first(*stack);
	tmp = *stack;
	while ((*stack)->next != tmp)
	{
		*stack = (*stack)->next;
		(*stack)->index--;
	}
	*stack = (*stack)->next;
	(*stack)->index = stacksize(*stack);
	*stack = find_first(*stack);
}

void	rev_rotate(t_stack **stack)
{
	if (!(*stack) || stacksize((*stack)) == 1)
		return ;
	*stack = find_first(*stack);
	while ((*stack)->index != stacksize(*stack))
	{
		(*stack)->index++;
		*stack = (*stack)->next;
	}
	(*stack)->index = 1;
	*stack = find_first(*stack);
}

void	swap(t_stack **stack)
{
	int	tmp;

	if (!(*stack) || stacksize(*stack) == 1)
		return ;
	*stack = find_first(*stack);
	tmp = (*stack)->nbr;
	(*stack)->nbr = (*stack)->next->nbr;
	(*stack)->next->nbr = tmp;
	*stack = find_first(*stack);
}

void	push(t_stack **from, t_stack **to)
{
	t_stack	*last;
	t_stack	*first;

	if (!(*from))
		return ;
	if (find_first(*from) == lastnode(*from))
	{
		addnode_front(to, newnode((*from)->nbr, 1));
		free_stack(from);
		return ;
	}
	*from = find_first(*from);
	addnode_front(to, newnode((*from)->nbr, 1));
	last = lastnode(*from);
	first = *from;
	*from = (*from)->next;
	last->next = *from;
	(*from)->previous = last;
	free(first);
	first = (*from);
	while ((*from)->next != first && (*from)->index--)
		*from = (*from)->next;
	(*from)->index--;
	*from = find_first(*from);
}
