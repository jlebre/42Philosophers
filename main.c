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

int	main(int argc, char **argv)
{
	t_args	args;

	if (argc < 2)
		ft_error("No Arguments!\n");
	check(argv);
	start_args(argc, argv, &args);
	create_philo(&args);
	return (0);
}
