/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:19:43 by jlebre            #+#    #+#             */
/*   Updated: 2022/10/21 18:23:21 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		if (check_fork(philo) == 0)
			return (0);
	}
	else
	{
		if (check_fork_2(philo) == 0)
			return (0);
	}
	print_2(philo, "is eating");
	while (philo->args->time_to_eat > (get_time() - philo->last_meal))
	{
		pthread_mutex_lock(&philo->args->mut_died);
		if (philo->args->died)
		{
			pthread_mutex_unlock(&philo->args->mut_died);
			break ;
		}
		pthread_mutex_unlock(&philo->args->mut_died);
	}
	eat_2(philo);
}

int	eat_2(t_philo *philo)
{
	if (philo->args->number_of_philosophers > 1)
	{
		if (philo->id == philo->args->number_of_philosophers)
			pthread_mutex_unlock(&philo->args->fork[0]);
		else
			pthread_mutex_unlock(&philo->args->fork[philo->id + 1]);
		pthread_mutex_unlock(&philo->args->fork[philo->id]);
	}
	else
		return (0);
	return (1);
}
