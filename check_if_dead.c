/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:15:28 by jlebre            #+#    #+#             */
/*   Updated: 2022/10/22 19:45:29 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_if_dead(t_philo *philo)
{
	int	i;

	while (1)
	{
		i = 0;
		pthread_mutex_lock(&philo->args->mutex);
		while (i < philo->args->number_of_philosophers && philo->args->died != 1)
		{
			if (get_time() - philo->last_meal >= philo->args->time_to_die)
			{
				printf("%lld %i died\n", current_time(philo->args), philo->id);
				philo->args->died = 1;
				pthread_mutex_unlock(&philo->args->mutex);
				return ;
			}
			if (all_ate(philo) == 0)
				return ;
			if (only_one_philosopher(philo) == 0)
				return ;
			i++;
		}
		pthread_mutex_unlock(&philo->args->mutex);
	}
}

int	all_ate(t_philo *philo)
{
	int	i;

	i = 0;
	while (philo->args->number_of_meals != -1
		&& i < philo->args->number_of_philosophers
		&& philo[i].meals >= philo->args->number_of_meals)
		i++;
	if (i == philo->args->number_of_philosophers)
	{
		philo->args->died = 1;
		pthread_mutex_unlock(&philo->args->mutex);
		return (0);
	}
	return (1);
}

int	only_one_philosopher(t_philo *philo)
{
	if (philo->args->number_of_philosophers == 1)
	{
		usleep(philo->args->time_to_die * 1000);
		printf("%lld %i died\n", current_time(philo->args), philo->id);
		philo->args->died = 1;
		pthread_mutex_unlock(&philo->args->mutex);
		return (0);
	}
	return (1);
}