/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 22:24:01 by marvin            #+#    #+#             */
/*   Updated: 2022/09/16 22:24:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_args	*args(void)
{
	static t_args	args;
	return (&args);
}

t_args	*philos(void)
{
	static t_args	philos;
	return (&philos);
}

long long time_ms()
{
	struct timeval	tv;
	long long		sec;
	long long		usec;

	gettimeofday(&tv, NULL);
	sec = tv.tv_sec - args()->s_time.tv_sec;
	usec = tv.tv_usec - args()->s_time.tv_usec;
	return ((usec / 1000) + (sec * 1000));
}

int	check_fork(int nb)
{
	return (1);
}

void	eat(int nb)
{
	if (check_fork(nb))
	{
		//pthread_mutex_lock(mut());
		printf("%lli %i has taken a fork\n", time_ms(), nb);
		printf("%lli %i is eating\n", time_ms(), nb);
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
	printf("%lli %i is sleeping\n", time_ms(), nb);
	usleep(args()->time_to_sleep);
}

void	think(int nb)
{
	printf("%lli %i is thinking\n", time_ms(), nb);
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
}

void	*create_philo(int nop)
{
	pthread_t	philo[nop++];
	int			i;

	i = 1;
	while (i < nop)
	{
		pthread_create(philo + i, NULL, &routine, &i);
		printf("%lli %i created!\n", time_ms(), i);
		i++;
	}
	i = 1;
	while (i < nop)
	{
		pthread_join(philo[i], NULL);
		printf("%lli %i died!\n", time_ms(), i);
		i++;
	}
}

int	start_args(int argc, char **argv)
{
	args()->number_of_philo = ft_atoi(argv[1]);
	args()->time_to_die = ft_atoi(argv[2]);
	args()->time_to_eat = ft_atoi(argv[3]);
	args()->time_to_sleep = ft_atoi(argv[4]);
	if (args()->number_of_philo <= 0 || args()->time_to_die < 0
		|| args()->time_to_eat < 0 || args()->time_to_sleep < 0)
		return (0);
	if (argc == 6)
	{
		args()->number_of_meals = ft_atoi(argv[5]);
		if (args()->number_of_meals <= 0)
			return (0);
	}
	
	args()->temp = args()->time_to_die;
	//args()->start_time = gettimeofday();
	return (1);
}

int main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (!start_args(argc, argv))
		return (0);
	create_philo(args()->number_of_philo);
	return (0);
}

//MUTEX FORKS
//Check if dead inside and outside

/*
number_of_philosophers
time_to_die
time_to_eat
time_to_sleep
[number_of_times_each_philosopher_must_eat]

memset
printf
malloc
free
write
usleep
gettimeofday
pthread_create
pthread_detach
pthread_join
pthread_mutex_init
pthread_mutex_destroy
pthread_mutex_lock
pthread_mutex_unlock
*/
