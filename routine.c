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
	pthread_mutex_lock(&args()->mutex);
	philo->last_meal = get_time() + args()->time_to_die;
	pthread_mutex_unlock(&args()->mutex);
	while (check_life())
	{
		if (!eat(philo))
			break ;
		if (!print(philo, "is sleeping"))
			break ;
		philo->time = philo->args->time_to_sleep + get_time();
		while (get_time() < philo->time)
		{
			if (!check_life())			
				return (NULL);
		}
		if (!print(philo, "is thinking"))
			break ;
	}
	return (NULL);
}
