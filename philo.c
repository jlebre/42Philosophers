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

pthread_mutex_t *mut(void)
{
	static pthread_mutex_t	mutex;
	return (&mutex);
}

void	eat(int nb)
{
	printf(" Philo %i has taken a fork\n", nb);
	printf(" Philo %i is eating\n", nb);

}

void	dorme(int nb)
{
	printf(" Philo %i is sleeping\n", nb);
}

void	think(int nb)
{
	printf(" Philo %i is thinking\n", nb);
}

void	*routine(void *arg)
{
	int i;

	i = *(int*)arg;
	eat(i);
	dorme(i);
	think(i);
	//If !Eat:
	printf(" Philo %i died\n", time, i);
}

/*
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
*/

/*
	pthread_mutex_init(mut(), NULL);
	pthread_mutex_destroy(mut());

*/

void	*create_philo(int nop)
{
	pthread_t	philo[nop];
	int			i;

	i = 1;
	while (i < (nop + 1))
	{
		printf("Philo %i created!\n", i);
		pthread_create(philo + i, NULL, &routine, &i);
		i++;
	}
	i = 1;
	while (i < (nop + 1))
	{
		printf("Philo %i died!\n", i);
		pthread_join(philo[i], NULL);
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
