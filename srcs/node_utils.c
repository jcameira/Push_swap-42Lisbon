/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcameira <jcameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 00:25:30 by jcameira          #+#    #+#             */
/*   Updated: 2024/03/03 16:18:53 by jcameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	stacksize(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	if (!stack)
		return (0);
	tmp = stack;
	i = 1;
	while (tmp->next != stack)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	get_index(t_stack **stack)
{
	t_stack	*tmp;
	int		i;
	int		size;

	size = stacksize(*stack);
	tmp = *stack;
	i = -1;
	while (++i < size)
	{
		tmp->index = i;
		tmp = tmp->next;
	}
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
	t_stack	*tmp;

	if (!(*stack))
	{
		*stack = new;
		(*stack)->next = *stack;
		(*stack)->previous = *stack;
		(*stack)->index = 0;
		return ;
	}
	last = lastnode(*stack);
	tmp = *stack;
	while (tmp->next != *stack)
	{
		tmp->index++;
		tmp = tmp->next;
	}
	tmp->index++;
	last->next = new;
	new->previous = last;
	new->next = *stack;
	(*stack)->previous = new;
	*stack = new;
	(*stack)->index = 0;
}

t_stack	*newnode(int nbr)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nbr = nbr;
	new->next = NULL;
	new->previous = NULL;
	return (new);
}
