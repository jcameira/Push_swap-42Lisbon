/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcameira <jcameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:21:28 by jcameira          #+#    #+#             */
/*   Updated: 2023/12/08 16:43:19 by jcameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculations_a_to_b(t_stack *stack_a, t_stack *stack_b, int flag)
{
	int		nbr_mov;
	int		i;
	t_stack	*tmp;

	tmp = find_first(stack_a);
	nbr_mov = get_nbr_movs_rarb(stack_a, stack_b, tmp, flag);
	i = 0;
	while (i < stacksize(stack_a))
	{
		if (nbr_mov > get_nbr_movs_rarb(stack_a, stack_b, tmp, flag))
			nbr_mov = get_nbr_movs_rarb(stack_a, stack_b, tmp, flag);
		if (nbr_mov > get_nbr_movs_rrarrb(stack_a, stack_b, tmp, flag))
			nbr_mov = get_nbr_movs_rrarrb(stack_a, stack_b, tmp, flag);
		if (nbr_mov > get_nbr_movs_rrarb(stack_a, stack_b, tmp, flag))
			nbr_mov = get_nbr_movs_rrarb(stack_a, stack_b, tmp, flag);
		if (nbr_mov > get_nbr_movs_rarrb(stack_a, stack_b, tmp, flag))
			nbr_mov = get_nbr_movs_rarrb(stack_a, stack_b, tmp, flag);
		tmp = tmp->next;
		i++;
	}
	return (nbr_mov);
}

int	calculations_b_to_a(t_stack *stack_a, t_stack *stack_b, int flag)
{
	int		nbr_mov;
	int		i;
	t_stack	*tmp;

	tmp = find_first(stack_b);
	nbr_mov = get_nbr_movs_rarb(stack_a, stack_b, tmp, flag);
	i = 0;
	while (i < stacksize(stack_b))
	{
		if (nbr_mov > get_nbr_movs_rarb(stack_a, stack_b, tmp, flag))
			nbr_mov = get_nbr_movs_rarb(stack_a, stack_b, tmp, flag);
		if (nbr_mov > get_nbr_movs_rrarrb(stack_a, stack_b, tmp, flag))
			nbr_mov = get_nbr_movs_rrarrb(stack_a, stack_b, tmp, flag);
		if (nbr_mov > get_nbr_movs_rrarb(stack_a, stack_b, tmp, flag))
			nbr_mov = get_nbr_movs_rrarb(stack_a, stack_b, tmp, flag);
		if (nbr_mov > get_nbr_movs_rarrb(stack_a, stack_b, tmp, flag))
			nbr_mov = get_nbr_movs_rarrb(stack_a, stack_b, tmp, flag);
		tmp = tmp->next;
		i++;
	}
	return (nbr_mov);
}
