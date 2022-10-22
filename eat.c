/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:19:43 by jlebre            #+#    #+#             */
/*   Updated: 2022/10/22 19:46:45 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		if (!check_fork(philo))
			return (0);
	}
	else
	{
		if (!check_fork_2(philo))
			return (0);
	}
	print_2(philo, "is eating");
	while (philo->args->time_to_eat > (get_time() - philo->last_meal))
	{
		pthread_mutex_lock(&philo->args->mutex);
		if (philo->args->died == 1)
		{
			pthread_mutex_unlock(&philo->args->mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->args->mutex);
	}
	eat_2(philo);
	return (1);
}

int	eat_2(t_philo *philo)
{
	if (philo->args->number_of_philosophers > 1)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(&philo->right_fork);
	}
	else
		return (0);
	return (1);
}
