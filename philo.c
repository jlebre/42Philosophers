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

void*	live()
{
	pthread_mutex_lock(&mutex);
	printf("Philo took a fork\n");
	printf("Eat\n");
	printf("Philo put fork on the table\n");
	printf("Sleep\n");
	pthread_mutex_unlock(&mutex);
}

void*	create_philo(int nop)
{
	pthread_t	philo[nop];
	pthread_mutex_init(&mutex, NULL);
	int			i;

	i = 0;
	while (i < nop)
	{
		printf("Philo %i created!\n", i);
		pthread_create(philo + i, NULL, &live, NULL);
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

int main(int argc, char **argv)
{
	int nop;
	/*
	int	forks;
	int	ttd;
	int	tte;
	int	tts;
	*/

	if (argc < 5)
		return (0);
	nop = atoi(argv[1]);
	/*
	forks = nop;
	ttd = atoi(argv[2]);
	tte = atoi(argv[3]);
	tts = atoi(argv[4]);
	*/

	create_philo(nop);
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
