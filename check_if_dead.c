/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:15:28 by jlebre            #+#    #+#             */
/*   Updated: 2022/10/21 19:39:11 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_if_dead(t_philo *philo)
{
	if ((current_time(philo->args) - philo->last_meal) > philo->args->time_to_die)
	{
		if (philo->args->lock == 0)
		{
			philo->args->lock = 1;
			pthread_mutex_lock(&philo->args->mut_died);
			philo->args->died = 1;
			pthread_mutex_unlock(&philo->args->mut_died);
			printf("%lld %i died\n", current_time(philo->args), philo->id);
			return (0);
		}
	}
	return (1);
}
