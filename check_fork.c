/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:20:30 by jlebre            #+#    #+#             */
/*   Updated: 2022/10/22 22:52:29 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_fork_2(t_philo *philo);

int	check_fork(t_philo *philo)
{
	int i;

	if (philo->id % 2 != 0)
		return (check_fork_2(philo));
	i = 0;
	pthread_mutex_lock(&philo->right_fork->mutex);
	if (!philo->right_fork->is_select)
	{
		pthread_mutex_lock(&philo->left_fork->mutex);
		if (!philo->left_fork->is_select)
		{
			philo->right_fork->is_select = 1;
			philo->left_fork->is_select = 1;
			i += print(philo, "has taken a fork");
			i += print(philo, "has taken a fork");		
		}
		pthread_mutex_unlock(&philo->left_fork->mutex);	
	}
	pthread_mutex_unlock(&philo->right_fork->mutex);		
	return (i == 2);
}

int	check_fork_2(t_philo *philo)
{
	int i;

	i = 0;
	pthread_mutex_lock(&philo->left_fork->mutex);
	if (!philo->left_fork->is_select)
	{
		pthread_mutex_lock(&philo->right_fork->mutex);
		if (!philo->right_fork->is_select)
		{
			philo->left_fork->is_select = 1;
			philo->right_fork->is_select = 1;
			i += print(philo, "has taken a fork");
			i += print(philo, "has taken a fork");		
		}
		pthread_mutex_unlock(&philo->right_fork->mutex);	
	}
	pthread_mutex_unlock(&philo->left_fork->mutex);		
	return (i == 2);
}

int	free_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->right_fork->mutex);
	philo->right_fork->is_select = 0;
	pthread_mutex_unlock(&philo->right_fork->mutex);	
	pthread_mutex_lock(&philo->left_fork->mutex);
	philo->left_fork->is_select = 0;
	pthread_mutex_unlock(&philo->left_fork->mutex);	
	return (1);
}