/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:43:36 by jlebre            #+#    #+#             */
/*   Updated: 2022/09/30 16:07:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_philo()
{
	int	i;

	i = 1;
	args()->philos = malloc(sizeof(t_philo) * args()->number_of_philo);
	args()->start_time;
	i = 1;
	while (i < args()->number_of_philo)
	{
		pthread_mutex_init(args()->philos[i].fork, NULL);
		i++;
	}
	while (i < args()->number_of_philo)
	{
		args()->philos[i].number_of_philo = i + 1;
		pthread_create(args()->philos[i].philo, NULL, &routine, &i);
		usleep(1000);
		//printf("%lli %i created!\n", current_time(), i);
		i++;
	}
    return (0);
}
