/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:43:36 by jlebre            #+#    #+#             */
/*   Updated: 2022/09/28 01:50:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*create_philo(int nop)
{
	pthread_t	philo[nop + 1];
	int			i;

	i = 1;
	while (i < nop)
	{
		pthread_create(philo + i, NULL, &routine, &i);
		//printf("%lli %i created!\n", current_time(), i);
		i++;
	}
	i = 1;
	while (i < nop)
	{
		pthread_join(philo[i], NULL);
		//printf("%lli %i died!\n", current_time(), i);
		i++;
	}
    return (0);
}
