/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:40:05 by jlebre            #+#    #+#             */
/*   Updated: 2022/09/27 14:40:05 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_args	*args(void)
{
	static t_args	args;
	return (&args);
}

t_args	*philos(void)
{
	static t_args	philos;
	return (&philos);
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
