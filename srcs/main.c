/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcameira <jcameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:35:05 by jcameira          #+#    #+#             */
/*   Updated: 2024/03/03 16:21:25 by jcameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc < 2)
		return (0);
	if (!check_input(argc, argv))
		return (1);
	stack_a = create_stack(argv);
	if (!stack_a)
		return (1);
	if (!check_dups(stack_a))
	{
		free_stack(&stack_a);
		return (1);
	}
	if (stack_a && !issorted(stack_a))
		push_swap(&stack_a);
	free_stack(&stack_a);
	return (0);
}
