/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 01:41:01 by marvin            #+#    #+#             */
/*   Updated: 2022/09/28 01:41:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	is_dead(int i)
{
	if ((time_ms() - args()->last_meal) > args()->time_to_die
		&& current_time() >= args()->time_to_die)
	{
		printf("%lli %i died\n", current_time(), i);
		return (0);
	}
	else
		return (1);
}

//0 - Dead
//1 - Not Dead