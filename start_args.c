/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:41:38 by jlebre            #+#    #+#             */
/*   Updated: 2022/09/30 15:43:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_args(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("Invalid arguments\n");
		return (0);
	}
	args()->number_of_philo = ft_atol(argv[0]);
	args()->time_to_die = ft_atol(argv[1]);
	args()->time_to_eat = ft_atol(argv[2]);
	args()->time_to_sleep = ft_atol(argv[3]);
	if (args()->number_of_philo <= 0 || args()->time_to_die < 0
		|| args()->time_to_eat < 0 || args()->time_to_sleep < 0)
		return (0);
	if (argc == 6)
	{
		args()->number_of_meals = ft_atoi(argv[4]);
		if (args()->number_of_meals <= 0)
			return (0);
	}
	else
		args()->number_of_meals = 0;
	args()->start_time = time_ms();
	return (1);
}
