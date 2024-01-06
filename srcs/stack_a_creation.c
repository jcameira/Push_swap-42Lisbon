/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_creation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcameira <jcameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:27:13 by jcameira          #+#    #+#             */
/*   Updated: 2023/11/21 21:16:51 by jcameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*fill_stack(int arg_count, char **arg_arr, int init_pos)
{
	t_stack	*stack_a;
	t_stack	*new;
	int		i;
	int		j;

	i = 1;
	j = init_pos;
	stack_a = NULL;
	while (j < arg_count)
	{
		new = newnode((int)ft_atoi(arg_arr[j++]), i++);
		if (!new)
		{
			free_stack(&stack_a);
			return (NULL);
		}
		addnode_back(&stack_a, new);
	}
	return (stack_a);
}

t_stack	*parse_input(char *arguments, int init_pos)
{
	int		i;
	char	**arg_arr;
	t_stack	*stack_a;

	arg_arr = ft_split(arguments, ' ');
	if (!arg_arr)
		return (NULL);
	stack_a = fill_stack(word_count(arguments, ' '), arg_arr, init_pos);
	i = 0;
	while (i < word_count(arguments, ' '))
		free(arg_arr[i++]);
	free(arg_arr);
	return (stack_a);
}
