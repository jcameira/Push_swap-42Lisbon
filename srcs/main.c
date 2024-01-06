/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcameira <jcameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:58:01 by jcameira          #+#    #+#             */
/*   Updated: 2023/11/21 20:31:57 by jcameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (!check_input(argc, argv))
		return (0);
	if (argc == 2)
		stack_a = parse_input(argv[1], 0);
	else
		stack_a = fill_stack(argc, argv, 1);
	if (stack_a && !issorted(stack_a))
		push_swap(&stack_a);
	free_stack(&stack_a);
	return (0);
}
