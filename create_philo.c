/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:34:10 by jlebre            #+#    #+#             */
/*   Updated: 2022/10/17 14:34:10 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_philo(t_args *args)
{
	int		i;
	t_philo	*philo;

	philo = start_philo(args);
	i = 0;
	while (i < args->number_of_philosophers)
	{
		pthread_create(&philo[i].philo, NULL, &routine, &philo[i]);
		i++;
	}
	while (1)
		if (!check_if_dead(philo))
			break ;
	destroy_philo(philo, args);
}
