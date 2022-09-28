/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:48:57 by jlebre            #+#    #+#             */
/*   Updated: 2022/09/28 01:22:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long time_ms()
{
	struct timeval	tv;
	long long		sec;
	long long		usec;

	gettimeofday(&tv, NULL);
	sec = tv.tv_sec - args()->s_time.tv_sec;
	usec = tv.tv_usec - args()->s_time.tv_usec;
	return ((usec / 1000) + (sec * 1000));
}

long long	current_time()
{
	return (time_ms() - args()->start_time);
}
