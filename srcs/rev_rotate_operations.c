/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcameira <jcameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:35:56 by jcameira          #+#    #+#             */
/*   Updated: 2023/11/21 10:43:07 by jcameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack_a, int read_flag)
{
	rev_rotate(stack_a);
	if (!read_flag)
		ft_printf("rra\n");
}

void	rrb(t_stack **stack_b, int read_flag)
{
	rev_rotate(stack_b);
	if (!read_flag)
		ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int read_flag)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	if (!read_flag)
		ft_printf("rrr\n");
}
