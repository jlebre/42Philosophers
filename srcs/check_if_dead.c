/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:15:28 by jlebre            #+#    #+#             */
/*   Updated: 2022/10/23 00:11:29 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	dead_all(int p)
{
	int		i;
	t_philo	*philo;

	i = 0;
	pthread_mutex_lock(&args()->mutex_life);
	args()->died = 1;
	pthread_mutex_unlock(&args()->mutex_life);
	return ;
	while (i < args()->number_of_philosophers)
	{
		philo = &args()->philos[i];
		if (i != p)
			pthread_detach(philo->philo);
		i++;
	}
}

int	check_life(void)
{
	int	i;

	pthread_mutex_lock(&args()->mutex_life);
	i = args()->died;
	pthread_mutex_unlock(&args()->mutex_life);
	return (!i);
}

int	check_life_all(void)
{
	t_philo	*philo;
	int		die;
	int		i;
	int		is;

	die = 0;
	i = -1;
	is = 0;
	pthread_mutex_lock(&args()->mutex);
	while (++i < args()->number_of_philosophers && args()->died != 1 && !die)
	{
		philo = &args()->philos[i];
		if (get_time() > philo->last_meal)
		{
			printf("%lld %i died\n", current_time(philo->args), philo->id);
			die++;
		}
		if (args()->number_of_meals >= 0)
			is += (philo->meals >= args()->number_of_meals);
	}
	die += (is == args()->number_of_philosophers);
	if (die > 0)
		dead_all(i);
	pthread_mutex_unlock(&args()->mutex);
	return (die == 0);
}

int	all_ate(t_philo *philo)
{
	int	i;

	i = 0;
	while (philo->args->number_of_meals != -1
		&& i < philo->args->number_of_philosophers
		&& philo[i].meals >= philo->args->number_of_meals)
		i++;
	if (i == philo->args->number_of_philosophers)
		philo->args->died = 1;
	return (philo->args->died);
}

int	only_one_philosopher(void)
{
	if (args()->number_of_philosophers == 1)
	{
		usleep(args()->time_to_die * 1000);
		printf("%lld %i died\n", current_time(args()), 1);
		return (1);
	}
	return (0);
}
