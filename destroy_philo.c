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

int	destroy_philo(t_philo *philo, t_args *args)
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

int	kill_everything(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->args->number_of_philosophers)
	{
		pthread_mutex_destroy(&philo->args->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&philo->args->print);
	pthread_mutex_destroy(&philo->args->eat);
	pthread_mutex_destroy(&philo->args->mut_died);
	pthread_mutex_destroy(&philo->args->check_print);
	free(philo);
	return (0);
}