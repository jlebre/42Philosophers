/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:41:38 by jlebre            #+#    #+#             */
/*   Updated: 2022/09/27 16:23:32 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_args(int argc, char **argv)
{
    struct timeval	tv;
    
	args()->number_of_philo = ft_atoi(argv[1]);
	args()->time_to_die = ft_atoi(argv[2]);
	args()->time_to_eat = ft_atoi(argv[3]);
	args()->time_to_sleep = ft_atoi(argv[4]);
	if (args()->number_of_philo <= 0 || args()->time_to_die < 0
		|| args()->time_to_eat < 0 || args()->time_to_sleep < 0)
		return (0);
	if (argc == 6)
	{
		args()->number_of_meals = ft_atoi(argv[5]);
		if (args()->number_of_meals <= 0)
			return (0);
	}
	
	args()->temp = args()->time_to_die;
	args()->start_time = gettimeofday(&tv, NULL);
	return (1);
}
