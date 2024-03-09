/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcameira <jcameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 00:12:40 by jcameira          #+#    #+#             */
/*   Updated: 2024/03/09 20:07:32 by jcameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack	*create_stack(char **argv)
{
	t_stack	*stack_a;
	t_stack	*new;
	char	**str;
	int		i;
	int		j;

	stack_a = NULL;
	i = 0;
	while (argv[++i])
	{
		str = ft_split(argv[i], ' ');
		j = -1;
		while (str[++j])
		{
			new = newnode(ft_atoi(str[j]));
			if (!new)
				return (free_stack(&stack_a));
			addnode_back(&stack_a, new);
		}
		free_split(str);
	}
	get_index(&stack_a);
	if (!check_dups(stack_a))
		return (free_stack(&stack_a));
	return (stack_a);
}
