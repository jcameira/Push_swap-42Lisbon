/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcameira <jcameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:41:24 by jcameira          #+#    #+#             */
/*   Updated: 2024/03/03 16:20:09 by jcameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	rotate(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next != *stack)
	{
		tmp = tmp->next;
		tmp->index--;
	}
	tmp = tmp->next;
	tmp->index = stacksize(*stack) - 1;
	*stack = (*stack)->next;
}

void	rev_rotate(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next != *stack)
	{
		tmp->index++;
		tmp = tmp->next;
	}
	tmp->index = 0;
	*stack = (*stack)->previous;
}

void	swap(t_stack **stack)
{
	int	tmp;

	tmp = (*stack)->nbr;
	(*stack)->nbr = (*stack)->next->nbr;
	(*stack)->next->nbr = tmp;
}

void	push(t_stack **from, t_stack **to)
{
	t_stack	*last;
	t_stack	*tmp;

	if (stacksize(*from) == 1)
	{
		addnode_front(to, newnode((*from)->nbr));
		free_stack(from);
		return ;
	}
	addnode_front(to, newnode((*from)->nbr));
	last = lastnode(*from);
	tmp = *from;
	*from = (*from)->next;
	last->next = *from;
	(*from)->previous = last;
	free(tmp);
	tmp = *from;
	tmp = *from;
	while (tmp->next != *from && tmp->index--)
		tmp = tmp->next;
	tmp->index--;
}
