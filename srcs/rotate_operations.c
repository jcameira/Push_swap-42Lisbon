/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcameira <jcameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:36:09 by jcameira          #+#    #+#             */
/*   Updated: 2023/11/21 10:42:53 by jcameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack_a, int read_flag)
{
	rotate(stack_a);
	if (!read_flag)
		ft_printf("ra\n");
}

void	rb(t_stack **stack_b, int read_flag)
{
	rotate(stack_b);
	if (!read_flag)
		ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b, int read_flag)
{
	rotate(stack_a);
	rotate(stack_b);
	if (!read_flag)
		ft_printf("rr\n");
}
