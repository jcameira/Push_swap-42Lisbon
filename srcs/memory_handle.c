/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcameira <jcameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 00:05:23 by jcameira          #+#    #+#             */
/*   Updated: 2024/03/06 02:35:24 by jcameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

void	*free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!(*stack))
		return (NULL);
	last = lastnode(*stack);
	(*stack)->previous = NULL;
	last->next = NULL;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	return (NULL);
}

int	error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}
