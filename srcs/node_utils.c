/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcameira <jcameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:28:56 by jcameira          #+#    #+#             */
/*   Updated: 2024/02/24 00:27:27 by jcameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stacksize(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	if (!stack)
		return (0);
	tmp = stack;
	i = 1;
	while (stack->next != tmp)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void	addnode_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		(*stack)->next = *stack;
		(*stack)->previous = *stack;
		return ;
	}
	last = lastnode(*stack);
	last->next = new;
	new->previous = last;
	new->next = *stack;
	(*stack)->previous = new;
}

void	addnode_front(t_stack **stack, t_stack *new)
{
	t_stack	*last;
	int		size;

	if (!(*stack))
	{
		*stack = new;
		(*stack)->next = *stack;
		(*stack)->previous = *stack;
		return ;
	}
	last = lastnode(*stack);
	size = stacksize(*stack);
	while ((*stack)->index != size)
	{
		(*stack)->index++;
		(*stack) = (*stack)->next;
	}
	(*stack)->index++;
	(*stack) = (*stack)->next;
	last->next = new;
	new->previous = last;
	new->next = *stack;
	(*stack)->previous = new;
	*stack = new;
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!(*stack))
		return ;
	*stack = find_first(*stack);
	last = lastnode(*stack);
	(*stack)->previous = NULL;
	last->next = NULL;
	while (*stack)
	{
		tmp = (*stack)->next;
		(*stack)->nbr = 0;
		(*stack)->index = 0;
		free(*stack);
		*stack = tmp;
	}
}

t_stack	*newnode(int nbr, int index)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof (t_stack));
	if (!new)
		return (NULL);
	new->nbr = nbr;
	new->index = index;
	new->next = NULL;
	new->previous = NULL;
	return (new);
}
