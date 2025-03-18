/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:32:52 by jlebre            #+#    #+#             */
/*   Updated: 2022/10/17 13:32:52 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_all_int(char **argv)
{
	int		i;
	int		j;
	char	**input;

	i = 0;
	input = argv;
	input++;
	while (input[i])
	{
		j = 0;
		if (input[i][j] == '+' || input[i][j] == '-')
			j++;
		while (input[i][j])
		{
			if (!ft_isdigit(input[i][j]))
				ft_error("All parameters should be numeric!\n");
			j++;
		}
		i++;
	}
}

void	check_limits(char **argv)
{
	int			i;
	long long	n;

	i = 0;
	while (argv[i])
	{
		n = ft_atol(argv[i]);
		if (n < INT_MIN || n > INT_MAX)
			ft_error("At least one parameters is off limits!\n");
		i++;
	}
}

void	check(char **argv)
{
	check_all_int(argv);
	check_limits(argv);
}
