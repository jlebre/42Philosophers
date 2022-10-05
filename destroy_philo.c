/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:14:25 by marvin            #+#    #+#             */
/*   Updated: 2022/09/30 18:14:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    destroy_philo()
{
    int i;

    i = 1;
    free(args()->philo);
    while (i < args()->number_of_philo)
    {
        pthread_mutex_destroy(args()->philo[i].fork);
        i++;
    }
    while (i < args()->number_of_philo)
    {
        pthread_join(args()->philo[i].philo, NULL);
        i++;
    }
}