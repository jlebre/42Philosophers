/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:44:53 by jlebre            #+#    #+#             */
/*   Updated: 2022/09/30 18:13:54 by marvin           ###   ########.fr       */
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
		printf("%lli %i has taken a fork\n", current_time(), nb);
		printf("%lli %i is eating\n", current_time(), nb);
		usleep(args()->time_to_eat * 1000);
		if (nb == 2)
			sleep(2);
		//args()->temp = args()->time_to_die;
		args()->last_meal = time_ms();
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

void	nap(int nb)
{
	usleep(args()->time_to_sleep * 1000);
	printf("%lli %i is sleeping\n", current_time(), nb);
}

void	think(int nb)
{
	printf("%lli %i is thinking\n", current_time(), nb);
}

void	*routine(void *arg)
{
	int i;

	i = *(int*)arg;
	printf("%lli %i created!\n", current_time(), i);
	//pthread_mutex_init(args()->mutex , NULL);
	while(1)
	{
		eat(i);
		nap(i);
		think(i);
	}
	//pthread_mutex_destroy(args()->mutex);
    return (0);
}