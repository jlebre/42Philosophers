/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:48:34 by marvin            #+#    #+#             */
/*   Updated: 2022/10/01 16:48:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <time.h>
# include <sys/time.h> 
# include <pthread.h>

# define INT_MAX    2147483647
# define INT_MIN    -2147483648

typedef struct s_args
{
	int			number_of_philosophers;
	long long	time_to_die;
	long long	time_to_eat;
	long long	time_to_sleep;
	int			number_of_meals;
}   t_args;

//CHECK
void    	check(char **argv);
void    	check_all_int(char **argv);
void    	check_limits(char **argv);

//UTILS
void    	ft_error();
int			ft_isdigit(int i);
int			ft_atoi(const char *str);
long long	ft_atol(const char *str)

#endif