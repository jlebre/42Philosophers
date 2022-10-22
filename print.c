/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:28:12 by jlebre            #+#    #+#             */
/*   Updated: 2022/10/22 19:45:58 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->args->mutex);
	if (philo->args->died == 1)
	{
		pthread_mutex_unlock(&philo->args->mutex);
		return (0);
	}
	printf("%lld %d %s\n", current_time(philo->args), philo->id, str);
	pthread_mutex_unlock(&philo->args->mutex);
	return (1);
}

int	print_2(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->args->mutex);
	if (philo->args->died == 1)
	{
		pthread_mutex_unlock(&philo->args->mutex);
		return (0);
	}
	printf("%lld %d %s\n", current_time(philo->args), philo->id, str);
	philo->meals++;
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->args->mutex);
	return (1);
}
