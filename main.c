/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:33:24 by jlebre            #+#    #+#             */
/*   Updated: 2022/10/17 13:33:24 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_args	*args()
{
	static t_args	a;

	return (&a);
}

int	main(int argc, char **argv)
{

	if (argc < 2)
		ft_error("No Arguments!\n");
	check(argv);
	start_args(argc, argv, args());
	if (args()->number_of_philosophers == 1)
	 only_one_philosopher();
	else
		create_philo(args());
	return (0);
}
