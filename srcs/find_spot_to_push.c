/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_spot_to_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcameira <jcameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:35:47 by jcameira          #+#    #+#             */
/*   Updated: 2023/11/20 22:00:13 by jcameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nbr_movs_to_pb(t_stack *stack_b, int nbr_to_push)
{
	int		i;
	t_stack	*tmp;

	stack_b = find_first(stack_b);
	i = 1;
	if (nbr_to_push > stack_b->nbr && nbr_to_push < lastnode(stack_b)->nbr)
		i = 0;
	else if (nbr_to_push > max_node(stack_b)->nbr
		|| nbr_to_push < min_node(stack_b)->nbr)
		i = max_node(stack_b)->index - 1;
	else
	{
		tmp = stack_b->next;
		while (nbr_to_push > stack_b->nbr || nbr_to_push < tmp->nbr)
		{
			stack_b = stack_b->next;
			tmp = stack_b->next;
			i++;
		}
	}
	return (i);
}

int	nbr_movs_to_pa(t_stack *stack_a, int nbr_to_push)
{
	int		i;
	t_stack	*tmp;

	stack_a = find_first(stack_a);
	i = 1;
	if (nbr_to_push < stack_a->nbr && nbr_to_push > lastnode(stack_a)->nbr)
		i = 0;
	else if (nbr_to_push > max_node(stack_a)->nbr
		|| nbr_to_push < min_node(stack_a)->nbr)
		i = min_node(stack_a)->index - 1;
	else
	{
		tmp = stack_a->next;
		while (nbr_to_push < stack_a->nbr || nbr_to_push > tmp->nbr)
		{
			stack_a = stack_a->next;
			tmp = stack_a->next;
			i++;
		}
	}
	return (i);
}
