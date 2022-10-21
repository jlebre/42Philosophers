/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:20:30 by jlebre            #+#    #+#             */
/*   Updated: 2022/10/21 20:24:30 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork->mutex);
	pthread_mutex_lock(philo->right_fork->mutex);
	if (philo->left_fork->taken == false && philo->right_fork->taken == false)
	{
		print(philo, "has taken a fork");
		print(philo, "has taken a fork");
		philo->left_fork->taken = true;
		philo->right_fork->taken = true;
		philo->meals++;
		philo->last_meal = get_time();
		return (1);
	}
	else
	{
		pthread_mutex_unlock(philo->left_fork->mutex);
		pthread_mutex_unlock(philo->right_fork->mutex);
		return (0);
	}
	return (1);
}


/* int	check_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork->mutex);
	if (!print(philo, "has taken a fork"))
	{
		pthread_mutex_unlock(philo->left_fork->mutex);
		return (0);
	}
	pthread_mutex_lock(philo->right_fork->mutex);
	if (!print(philo, "has taken a fork"))
	{
		pthread_mutex_unlock(philo->left_fork->mutex);
		pthread_mutex_unlock(philo->right_fork->mutex);
		return (0);
	}
	return (1);
}

int	check_fork_2(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork->mutex);
	if (!print(philo, "has taken a fork"))
	{
		pthread_mutex_unlock(philo->right_fork->mutex);
		return (0);
	}
	pthread_mutex_lock(philo->left_fork->mutex);
	if (!print(philo, "has taken a fork"))
	{
		pthread_mutex_unlock(philo->left_fork->mutex);
		pthread_mutex_unlock(philo->right_fork->mutex);
		return (0);
	}
	return (1);
} */