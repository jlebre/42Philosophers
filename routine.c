/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:18:53 by jlebre            #+#    #+#             */
/*   Updated: 2022/10/17 13:18:53 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *i)
{
	t_philo	*philo;

	philo = (t_philo *)i;
	while (1)
	{
		if (!eat(philo))
			break ;
		if (!print(philo, "is sleeping"))
			break ;
		while (philo->args->time_to_sleep > (get_time() - philo->last_nap))
		{
			pthread_mutex_lock(&philo->args->mutex);
			if (philo->args->died == 1)
			{
				pthread_mutex_unlock(&philo->args->mutex);
				break ;
			}
			pthread_mutex_unlock(&philo->args->mutex);
		}
		philo->last_nap = current_time(philo->args);
		if (!print(philo, "is thinking"))
			break ;
	}
	return (NULL);
}
