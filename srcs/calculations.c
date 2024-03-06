/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcameira <jcameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:52:35 by jcameira          #+#    #+#             */
/*   Updated: 2024/03/06 03:48:22 by jcameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_moves	calculations_a_to_b(t_stack *stack_a, t_stack *stack_b, int flag)
{
	t_moves	nbr_mov;
	t_moves	tmp_mov;
	t_stack	*tmp;
	int		i;

	tmp = stack_a;
	nbr_mov.moves = INT_MAX;
	i = -1;
	while (++i < stacksize(stack_a))
	{
		tmp_mov = get_nbr_movs_rarb(stack_a, stack_b, tmp, flag);
		if (nbr_mov.moves > tmp_mov.moves)
			nbr_mov = tmp_mov;
		tmp_mov = get_nbr_movs_rrarrb(stack_a, stack_b, tmp, flag);
		if (nbr_mov.moves > tmp_mov.moves)
			nbr_mov = tmp_mov;
		tmp_mov = get_nbr_movs_rrarb(stack_a, stack_b, tmp, flag);
		if (nbr_mov.moves > tmp_mov.moves)
			nbr_mov = tmp_mov;
		tmp_mov = get_nbr_movs_rarrb(stack_a, stack_b, tmp, flag);
		if (nbr_mov.moves > tmp_mov.moves)
			nbr_mov = tmp_mov;
		tmp = tmp->next;
	}
	return (nbr_mov);
}

t_moves	calculations_b_to_a(t_stack *stack_a, t_stack *stack_b, int flag)
{
	t_moves	nbr_mov;
	t_moves	tmp_mov;
	t_stack	*tmp;
	int		i;

	tmp = stack_b;
	nbr_mov.moves = INT_MAX;
	i = -1;
	while (++i < stacksize(stack_b))
	{
		tmp_mov = get_nbr_movs_rarb(stack_a, stack_b, tmp, flag);
		if (nbr_mov.moves > tmp_mov.moves)
			nbr_mov = tmp_mov;
		tmp_mov = get_nbr_movs_rrarrb(stack_a, stack_b, tmp, flag);
		if (nbr_mov.moves > tmp_mov.moves)
			nbr_mov = tmp_mov;
		tmp_mov = get_nbr_movs_rrarb(stack_a, stack_b, tmp, flag);
		if (nbr_mov.moves > tmp_mov.moves)
			nbr_mov = tmp_mov;
		tmp_mov = get_nbr_movs_rarrb(stack_a, stack_b, tmp, flag);
		if (nbr_mov.moves > tmp_mov.moves)
			nbr_mov = tmp_mov;
		tmp = tmp->next;
	}
	return (nbr_mov);
}
