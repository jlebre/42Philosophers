/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:33:46 by jlebre            #+#    #+#             */
/*   Updated: 2022/10/17 13:33:46 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_args(int argc, char **argv, t_args *args)
{
	if (argc < 5 || argc > 6)
		ft_error("Wrong number of parameters!\n");
	args->number_of_philosophers = ft_atol(argv[1]);
	args->time_to_die = ft_atol(argv[2]);
	args->time_to_eat = ft_atol(argv[3]);
	args->time_to_sleep = ft_atol(argv[4]);
	if (args->number_of_philosophers <= 0 || args->time_to_die < 0
		|| args->time_to_eat < 0 || args->time_to_sleep < 0)
		ft_error("Invalid values!\n");
	if (args->number_of_philosophers > 200)
	{
		ft_error("You can only test with a maximum of 200 philosophers!\n");
		red("Read the evaluation guide\n");
	}
	if (argc == 6)
	{
		args->number_of_meals = ft_atoi(argv[4]);
		if (args->number_of_meals <= 0)
			ft_error("Invalid values!\n");
	}
	else
		args->number_of_meals = -1;
	args->start_time = get_time();
	args->died = 0;
}

t_philo	*start_philo(t_args *args)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = malloc(sizeof(t_philo) * args->number_of_philosophers);
	if (!philo)
		return (0);
	while (i < args->number_of_philosophers)
	{
		philo[i].id = i + 1;
		philo[i].meals = 0;
		philo[i].last_meal = args->start_time;
		philo[i].last_nap = args->start_time;
		philo[i].args = args;
		i++;
	}
	start_mutex(philo);
	return (philo);
}

void	start_mutex(t_philo *philo)
{
	int	i;
	int	nb;

	i = 0;
	nb = philo->args->number_of_philosophers;
	while (i < nb)
	{
		pthread_mutex_init(&philo[i].right_fork, NULL);
		if (i != 0)
			philo[i].left_fork = &philo[i - 1].right_fork;
		else if (i == 0)
			philo[i].left_fork = &philo[nb - 1].right_fork;
		i++;
	}
	pthread_mutex_init(&philo->args->mutex, NULL);
}
