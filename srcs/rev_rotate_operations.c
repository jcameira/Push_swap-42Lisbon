/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcameira <jcameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 00:33:45 by jcameira          #+#    #+#             */
/*   Updated: 2024/03/09 20:09:33 by jcameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	rra(t_stack **stack_a, int read_flag)
{
	if (!*stack_a)
		return ;
	rev_rotate(stack_a);
	if (!read_flag)
		ft_printf("rra\n");
}

void	rrb(t_stack **stack_b, int read_flag)
{
	if (!*stack_b)
		return ;
	rev_rotate(stack_b);
	if (!read_flag)
		ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int read_flag)
{
	if (!*stack_a || !*stack_b)
		return ;
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	if (!read_flag)
		ft_printf("rrr\n");
}
