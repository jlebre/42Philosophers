/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:43:36 by jlebre            #+#    #+#             */
/*   Updated: 2022/09/27 15:48:40 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
    return (0);
}
