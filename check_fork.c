/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:20:30 by jlebre            #+#    #+#             */
/*   Updated: 2022/10/21 18:24:45 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_fork(t_philo *philo)
{
}

int	check_fork_2(t_philo *philo)
{
}

int	check_fork(t_philo *philo)
{
	if (philo->id != (philo->args->number_of_philosophers)
		&& philo->id != (philo->args->number_of_philosophers))
	{
		if (!pthread_mutex_lock(&philo->args->fork[philo->id]))
		{
			if (philo->args->number_of_philosophers < 2)
			{
				pthread_mutex_unlock(&philo->args->fork[philo->id]);
				if (!check_if_dead(philo))
					return (2);
			}
			else if (!pthread_mutex_lock(&philo->args->fork[philo->id + 1]))
			{
				pthread_mutex_lock(&philo->args->print);
				print(philo, "has taken a fork");
				print(philo, "has taken a fork");
				pthread_mutex_unlock(&philo->args->print);
				return (1);
			}
			else
			{
				pthread_mutex_unlock(&philo->args->fork[philo->id]);
				return (0);
			}
		}
	}
	else if (philo->id == (philo->args->number_of_philosophers))
	{
		if (!pthread_mutex_lock(&philo->args->fork[philo->id]))
		{
			if (philo->args->number_of_philosophers < 2)
			{
				pthread_mutex_unlock(&philo->args->fork[philo->id]);
				if (!check_if_dead(philo))
					return (2);
			}
			else if (!pthread_mutex_lock(&philo->args->fork[0])
				&& philo->args->number_of_philosophers >= 2)
			{
				pthread_mutex_lock(&philo->args->print);
				print(philo, "has taken a fork");
				print(philo, "has taken a fork");
				pthread_mutex_unlock(&philo->args->print);
				return (1);
			}
			else
			{
				pthread_mutex_unlock(&philo->args->fork[philo->id]);
				return (0);
			}
		}
	}
	return (0);
}

