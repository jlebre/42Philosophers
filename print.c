/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:28:12 by jlebre            #+#    #+#             */
/*   Updated: 2022/10/21 18:11:44 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->args->check_print);
	if (philo->args->died)
	{
		pthread_mutex_unlock(&philo->args->print);
		return (0);
	}
	printf("%lld %d %s\n", current_time(philo->args), philo->id, str);
	pthread_mutex_unlock(&philo->args->check_print);
	return (1);
}

int	print_2(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->args->eat);
	if (philo->args->died == 1)
	{
		pthread_mutex_unlock(&philo->args->eat);
		return (0);
	}
	printf("%lld %d %s\n", current_time(philo->args), philo->id, str);
	philo->meals++;
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->args->eat);
	return (1);
}
