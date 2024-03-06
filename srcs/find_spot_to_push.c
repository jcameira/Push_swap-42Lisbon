/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_spot_to_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcameira <jcameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 23:39:37 by jcameira          #+#    #+#             */
/*   Updated: 2024/03/06 01:41:34 by jcameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	nbr_movs_to_pb(t_stack *stack_b, int nbr_to_push)
{
	int		i;
	t_stack	*tmp;

	if (nbr_to_push > stack_b->nbr && nbr_to_push < lastnode(stack_b)->nbr)
		i = 0;
	else if (nbr_to_push > max_node(stack_b)->nbr
		|| nbr_to_push < min_node(stack_b)->nbr)
		i = max_node(stack_b)->index;
	else
	{
		i = 1;
		tmp = stack_b;
		while (nbr_to_push > tmp->nbr || nbr_to_push < tmp->next->nbr)
		{
			tmp = tmp->next;
			i++;
		}
		i++;
	}
	return (i);
}

int	nbr_movs_to_pa(t_stack *stack_a, int nbr_to_push)
{
	int		i;
	t_stack	*tmp;

	if (nbr_to_push < stack_a->nbr && nbr_to_push > lastnode(stack_a)->nbr)
		i = 0;
	else if (nbr_to_push > max_node(stack_a)->nbr
		|| nbr_to_push < min_node(stack_a)->nbr)
		i = min_node(stack_a)->index;
	else
	{
		i = 1;
		tmp = stack_a;
		while (nbr_to_push < tmp->nbr || nbr_to_push > tmp->next->nbr)
		{
			tmp = tmp->next;
			i++;
		}
	}
	return (i);
}
