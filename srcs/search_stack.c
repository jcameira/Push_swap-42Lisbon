/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcameira <jcameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 00:30:04 by jcameira          #+#    #+#             */
/*   Updated: 2024/03/05 23:52:26 by jcameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack	*min_node(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*min;

	min = stack;
	tmp = stack->next;
	while (tmp != stack)
	{
		if (tmp->nbr < min->nbr)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

t_stack	*max_node(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*max;

	max = stack;
	tmp = stack->next;
	while (tmp != stack)
	{
		if (tmp->nbr > max->nbr)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

t_stack	*lastnode(t_stack *stack)
{
	t_stack	*tmp;
	int		size;
	int		i;

	size = stacksize(stack);
	if (!stack)
		return (NULL);
	tmp = stack;
	i = -1;
	while (++i < size - 1)
		tmp = tmp->next;
	return (tmp);
}
