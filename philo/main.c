/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:44:45 by marvin            #+#    #+#             */
/*   Updated: 2022/09/29 16:44:45 by marvin           ###   ########.fr       */
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
	if (!check(++argv))
		printf("Error\n");
	if (!start_args(argc, argv))
		return (0);
	//is_dead(i) != 0
	create_philo(args()->number_of_philo);
	return (0);
}
