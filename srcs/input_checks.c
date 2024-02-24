/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcameira <jcameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:26:43 by jcameira          #+#    #+#             */
/*   Updated: 2024/02/24 00:27:59 by jcameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	issorted(t_stack *stack)
{
	int	i;
	int	j;
	int	size;

	stack = find_first(stack);
	i = 0;
	j = stack->nbr;
	size = stacksize(stack);
	while (i++ < size)
	{
		if (j > stack->nbr)
			return (0);
		j = stack->nbr;
		stack = stack->next;
	}
	return (1);
}

int	check_string(char *str)
{
	int		i;
	int		args;
	char	**nbr_lst;

	i = 0;
	nbr_lst = ft_split(str, ' ');
	args = word_count(str, ' ');
	while (i < args)
	{
		if (!check_numeric(nbr_lst[i++]) || !check_dups(nbr_lst))
		{
			i = 0;
			while (i < args)
				free(nbr_lst[i++]);
			free(nbr_lst);
			return (0);
		}
	}
	i = 0;
	while (i < args)
		free(nbr_lst[i++]);
	free(nbr_lst);
	return (1);
}

int	check_dups(char **nbr)
{
	int	i;
	int	j;

	i = 1;
	while (nbr[i])
	{
		j = i;
		while (nbr[++j])
		{
			if (!ft_strcmp(nbr[i], nbr[j]))
			{
				ft_printf("Error\n");
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	check_numeric(char *nbr)
{
	int	i;

	i = 0;
	if ((ft_atoi(nbr) > 2147483648 || ft_atoi(nbr) < -2147483648)
		|| (nbr[i] != '-' && !ft_isdigit(nbr[i]))
		|| (nbr[i] == '-' && !nbr[i + 1]))
	{
		ft_printf("Error\n");
		return (0);
	}
	if (ft_atoi(nbr) >= 0)
		i = -1;
	else
		i = 0;
	while (nbr[++i])
	{
		if (!ft_isdigit(nbr[i]))
		{
			ft_printf("Error\n");
			return (0);
		}
	}
	return (1);
}

int	check_input(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		if (!check_string(argv[1]))
			return (0);
	}
	else if (argc > 2)
	{
		if (!check_dups(argv))
			return (0);
		while (i < argc)
		{
			if (!check_numeric(argv[i++]))
				return (0);
		}
	}
	return (1);
}
