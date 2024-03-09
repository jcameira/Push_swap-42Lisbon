/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcameira <jcameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 00:34:33 by jcameira          #+#    #+#             */
/*   Updated: 2024/03/09 20:09:48 by jcameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ra(t_stack **stack_a, int read_flag)
{
	if (!*stack_a)
		return ;
	rotate(stack_a);
	if (!read_flag)
		ft_printf("ra\n");
}

void	rb(t_stack **stack_b, int read_flag)
{
	if (!*stack_b)
		return ;
	rotate(stack_b);
	if (!read_flag)
		ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b, int read_flag)
{
	if (!*stack_a || !*stack_b)
		return ;
	rotate(stack_a);
	rotate(stack_b);
	if (!read_flag)
		ft_printf("rr\n");
}
