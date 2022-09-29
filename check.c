/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:19:50 by jlebre            #+#    #+#             */
/*   Updated: 2022/09/15 19:49:46 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_all_int(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '+' || argv[i][j] == '-')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_limits(char **argv)
{
	int			i;
	long long	n;

	i = 0;
	while (argv[i])
	{
		n = ft_atol(argv[i]);
		if (n < INT_MIN || n > INT_MAX)
			return (0);
		if (!add_stack(stack_a(), n))
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicates(void)
{
	t_stack	*temp;
	t_stack	*ptr;

	if (stack_a()->next)
	{
		temp = stack_a()->next;
		while (temp)
		{
			ptr = stack_a()->next;
			while (ptr)
			{
				if (ptr != temp && ptr->content == temp->content)
					return (0);
				ptr = ptr->next;
			}
			temp = temp->next;
		}
		return (1);
	}
	return (0);
}

int	downsize(void)
{
	t_stack	*temp;
	t_stack	*ptr;

	temp = stack_a()->next;
	while (temp)
	{
		temp->nb = 0;
		ptr = stack_a()->next;
		while (ptr)
		{
			if (ptr != temp && temp->content > ptr->content)
				temp->nb++;
			ptr = ptr->next;
		}
		temp = temp->next;
	}
	return (1);
}

int	check(char **argv)
{
	if (!check_all_int(argv))
		return (0);
	if (!check_limits(argv))
		return (0);
	if (!check_duplicates())
		return (0);
	downsize();
	return (1);
}
