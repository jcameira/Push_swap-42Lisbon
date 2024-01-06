/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcameira <jcameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:37:21 by jcameira          #+#    #+#             */
/*   Updated: 2023/11/21 10:43:23 by jcameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a, int read_flag)
{
	swap(stack_a);
	if (!read_flag)
		ft_printf("sa\n");
}

void	sb(t_stack **stack_b, int read_flag)
{
	swap(stack_b);
	if (!read_flag)
		ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b, int read_flag)
{
	swap(stack_a);
	swap(stack_b);
	if (!read_flag)
		ft_printf("ss\n");
}

void	pa(t_stack **stack_a, t_stack **stack_b, int read_flag)
{
	push(stack_b, stack_a);
	if (!read_flag)
		ft_printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b, int read_flag)
{
	push(stack_a, stack_b);
	if (!read_flag)
		ft_printf("pb\n");
}
