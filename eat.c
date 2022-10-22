/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:19:43 by jlebre            #+#    #+#             */
/*   Updated: 2022/10/23 00:03:25 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eat(t_philo *philo)
{
	while (1)
	{
		if (check_fork(philo))
		{	
			print(philo, "is eating");
			pthread_mutex_lock(&args()->mutex);
			philo->meals++;
			philo->last_meal = (get_time() + args()->time_to_die);
			pthread_mutex_unlock(&args()->mutex);
			break ;
		}
		if (!check_life())
			return (0);
	}	
	philo->time = get_time() + args()->time_to_eat;
	while (get_time() < philo->time)
	{
		if (!check_life())
			break ;
	}
	free_fork(philo);
	return (1);
}
