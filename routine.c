/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:44:53 by jlebre            #+#    #+#             */
/*   Updated: 2022/09/27 16:24:24 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_fork(int nb)
{
	return (nb);
}

void	eat(int nb)
{
	if (check_fork(nb))
	{
		//pthread_mutex_lock(mut());
		printf("%lli %i has taken a fork\n", (time_ms() - args()->start_time), nb);
		printf("%lli %i is eating\n", (time_ms() - args()->start_time), nb);
		usleep(args()->time_to_eat);
		args()->temp = args()->time_to_die;
		//pthread_mutex_unlock(mut());
	}
	else
	{
		while (args()->temp != 0)
		{
			eat(nb);
			args()->temp--;
		}
	}
}

void	dorme(int nb)
{
	printf("%lli %i is sleeping\n", (time_ms() - args()->start_time), nb);
	usleep(args()->time_to_sleep);
}

void	think(int nb)
{
	printf("%lli %i is thinking\n", (time_ms() - args()->start_time), nb);
}

void	*routine(void *arg)
{
	int i;

	i = *(int*)arg;
	//pthread_mutex_init(mut(), NULL);
	eat(i);
	dorme(i);
	think(i);
	//If !Eat:
	//printf("%i died\n", time, i);
	//pthread_mutex_destroy(mut());
    return (0);
}
