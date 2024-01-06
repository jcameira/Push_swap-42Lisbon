/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcameira <jcameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 01:42:00 by jcameira          #+#    #+#             */
/*   Updated: 2023/11/21 22:20:04 by jcameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	ft_printf("Error\n");
	exit(0);
}

void	check_line(t_stack **stack_a, t_stack **stack_b, char *l)
{
	if (l[0] == 'r' && l[1] == 'a' && l[2] == '\n')
		ra(stack_a, 1);
	else if (l[0] == 'r' && l[1] == 'b' && l[2] == '\n')
		rb(stack_b, 1);
	else if (l[0] == 'r' && l[1] == 'r' && l[2] == '\n')
		rr(stack_a, stack_b, 1);
	else if (l[0] == 'r' && l[1] == 'r' && l[2] == 'a' && l[3] == '\n')
		rra(stack_a, 1);
	else if (l[0] == 'r' && l[1] == 'r' && l[2] == 'b' && l[3] == '\n')
		rrb(stack_b, 1);
	else if (l[0] == 'r' && l[1] == 'r' && l[2] == 'r' && l[3] == '\n')
		rrr(stack_a, stack_b, 1);
	else if (l[0] == 's' && l[1] == 'a' && l[2] == '\n')
		sa(stack_a, 1);
	else if (l[0] == 's' && l[1] == 'b' && l[2] == '\n')
		sb(stack_b, 1);
	else if (l[0] == 's' && l[1] == 's' && l[2] == '\n')
		ss(stack_a, stack_b, 1);
	else if (l[0] == 'p' && l[1] == 'a' && l[2] == '\n')
		pa(stack_a, stack_b, 1);
	else if (l[0] == 'p' && l[1] == 'b' && l[2] == '\n')
		pb(stack_a, stack_b, 1);
	else
		error_exit();
	free(l);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	stack_b = NULL;
	if (!check_input(argc, argv))
		return (0);
	if (argc == 2)
		stack_a = parse_input(argv[1], 0);
	else
		stack_a = fill_stack(argc, argv, 1);
	line = get_next_line(0);
	while (line)
	{
		check_line(&stack_a, &stack_b, line);
		line = get_next_line(0);
	}
	if (stack_b || !issorted(stack_a))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	free(line);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
