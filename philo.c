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

pthread_mutex_t	mutex;

void sleep()

void	*rotine(void *arg)
{
	eat(void);
	sleep();
	think(void);
}

void	*live(void *arg)
{
	int i;

	i = *(int*)arg;
	pthread_mutex_lock(&mutex);
	printf("Philo %i took a fork\n", i);
	printf("Philo %i is eating spaggetti\n", i);
	printf("Philo %i put fork back on the table\n", i);
	printf("Philo %i is sleeping\n", i);
	printf("Philo %i is thinking\n", i);
	pthread_mutex_unlock(&mutex);
}

void	*create_philo(int nop)
{
	pthread_t	philo[nop];
	pthread_mutex_init(&mutex, NULL);
	int			i;

	i = 0;
	while (i < nop)
	{
		printf("Philo %i created!\n", i);
		pthread_create(philo + i, NULL, &live, &i);
		i++;
	}
	i = 0;
	while (i < nop)
	{
		printf("Philo %i died!\n", i);
		pthread_join(philo[i], NULL);
		i++;
	}
	pthread_mutex_destroy(&mutex);
}

int	start_args(char **argv, t_args *args);
{
	args.number_of_philo = ft_atoi(argv[1]);
	args.time_to_die = ft_atoi(argv[2]);
	args.time_to_eat = ft_atoi(argv[3]);
	args.time_to_sleep = ft_atoi(argv[4]);
	if (args.number_of_philo <= 0 || args.time_to_die < 0
		|| args.time_to_eat < 0 || args.time_to_sleep < 0)
		return (1);
	if (argc == 6)
	{
		args.number_of_meals = ft_atoi(argv[5]);
		if (args.number_of_meals <= 0)
			return (1);
	}
	args.start_time = gettimeofday();
	return (0);
}

int main(int argc, char **argv)
{
	t_args	args;

	if (argc < 2)
		return (0);
	if (start_args(argv, &args))
		return (0);
	create_philo(args.number_of_philo);
	return (0);
}

//MUTEX FORKS

/* MESSAGES
printf("%i Philo %i has taken a fork\n", time, philo);
printf("%i Philo %i is eating\n", time, philo);
printf("%i Philo %i is sleeping\n", time, philo);
printf("%i Philo %i is thinking\n", time, philo);
printf("%i Philo %i died\n", time, philo);
*/

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
