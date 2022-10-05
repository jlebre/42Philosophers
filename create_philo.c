/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:43:36 by jlebre            #+#    #+#             */
/*   Updated: 2022/09/30 19:38:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_philo()
{
	int	i;

	i = 1;
	args()->philo = malloc(sizeof(t_philo) * args()->number_of_philo);
	//args()->start_time;
	i = 1;
	while (i < args()->number_of_philo)
	{
		pthread_mutex_init(args()->philo[i].fork, NULL);
		i++;
	}
	printf("testeeeee\n");
	while (i < args()->number_of_philo)
	{
		args()->philo[i].number_of_philo = i + 1;
		pthread_create(&args()->philo[i].philo, NULL, &routine, &i);
		printf("%lli %i created!\n", current_time(), i);
		usleep(1000);
		i++;
	}
	printf("testeeeee\n");
}
