/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcameira <jcameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:16:35 by jcameira          #+#    #+#             */
/*   Updated: 2024/03/06 19:34:27 by jcameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	issorted(t_stack *stack)
{
	t_stack	*tmp;
	int		i;
	int		size;

	tmp = stack;
	i = -1;
	size = stacksize(stack);
	while (++i < size - 1)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	check_dups(t_stack *stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = stack;
	while (tmp1->next != stack)
	{
		tmp2 = tmp1->next;
		while (tmp2 != stack)
		{
			if (tmp1->nbr == tmp2->nbr)
				return (error());
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (1);
}

int	check_numeric(char *str)
{
	int		i;
	char	*tmp;

	tmp = ft_itoa(ft_atoi(str));
	if (str[0] == '+')
	{
		if (ft_strcmp(tmp, str + 1))
			return (error());
	}
	else
		if (ft_strcmp(tmp, str))
			return (error());
	free(tmp);
	if (ft_atoi(str) < 0 || str[0] == '+')
		i = 0;
	else
		i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (error());
	}
	return (1);
}

int	check_input(int argc, char **argv)
{
	int		i;
	int		j;
	char	**str;

	i = 0;
	while (++i < argc)
	{
		str = ft_split(argv[i], ' ');
		if (!str)
			return (0);
		j = -1;
		while (str[++j])
		{
			if (!check_numeric(str[j]))
				return (0);
		}
		free_split(str);
	}
	return (1);
}
