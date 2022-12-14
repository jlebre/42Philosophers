/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:33:19 by jlebre            #+#    #+#             */
/*   Updated: 2022/10/17 13:33:19 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_philo(t_philo *philo, t_args *args)
{
	int	i;

	i = 0;
	while (i < args->number_of_philosophers)
	{
		pthread_join(philo[i].philo, NULL);
		i++;
	}
	kill_everything(philo);
}

void	kill_everything(t_philo *philo)
{
	int	i;
	int	nb;

	i = 0;
	nb = philo->args->number_of_philosophers;
	while (i < nb)
	{
		pthread_mutex_destroy(&args()->forks[i].mutex);
		i++;
	}
	pthread_mutex_destroy(&philo->args->mutex);
	pthread_mutex_destroy(&philo->args->mutex_life);
	free(philo);
}
