/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcameira <jcameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:21:28 by jcameira          #+#    #+#             */
/*   Updated: 2024/02/24 00:22:42 by jcameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculations_a_to_b(t_stack *stack_a, t_stack *stack_b, int flag)
{
	int		nbr_mov;
	int		tmp_mov;
	int		i;
	t_stack	*tmp;

	tmp = find_first(stack_a);
	nbr_mov = get_nbr_movs_rarb(stack_a, stack_b, tmp, flag);
	i = -1;
	while (++i < stacksize(stack_a))
	{
		tmp_mov = get_nbr_movs_rarb(stack_a, stack_b, tmp, flag);
		if (nbr_mov > tmp_mov)
			nbr_mov = tmp_mov;
		tmp_mov = get_nbr_movs_rrarrb(stack_a, stack_b, tmp, flag);
		if (nbr_mov > tmp_mov)
			nbr_mov = tmp_mov;
		tmp_mov = get_nbr_movs_rrarb(stack_a, stack_b, tmp, flag);
		if (nbr_mov > tmp_mov)
			nbr_mov = tmp_mov;
		tmp_mov = get_nbr_movs_rarrb(stack_a, stack_b, tmp, flag);
		if (nbr_mov > tmp_mov)
			nbr_mov = tmp_mov;
		tmp = tmp->next;
	}
	return (nbr_mov);
}

int	calculations_b_to_a(t_stack *stack_a, t_stack *stack_b, int flag)
{
	int		nbr_mov;
	int		tmp_mov;
	int		i;
	t_stack	*tmp;

	tmp = find_first(stack_b);
	nbr_mov = get_nbr_movs_rarb(stack_a, stack_b, tmp, flag);
	i = -1;
	while (++i < stacksize(stack_b))
	{
		tmp_mov = get_nbr_movs_rarb(stack_a, stack_b, tmp, flag);
		if (nbr_mov > tmp_mov)
			nbr_mov = tmp_mov;
		tmp_mov = get_nbr_movs_rrarrb(stack_a, stack_b, tmp, flag);
		if (nbr_mov > tmp_mov)
			nbr_mov = tmp_mov;
		tmp_mov = get_nbr_movs_rrarb(stack_a, stack_b, tmp, flag);
		if (nbr_mov > tmp_mov)
			nbr_mov = tmp_mov;
		tmp_mov = get_nbr_movs_rarrb(stack_a, stack_b, tmp, flag);
		if (nbr_mov > tmp_mov)
			nbr_mov = tmp_mov;
		tmp = tmp->next;
	}
	return (nbr_mov);
}
