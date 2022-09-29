/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:48:16 by jlebre            #+#    #+#             */
/*   Updated: 2022/09/29 17:52:17 by marvin           ###   ########.fr       */
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
# include <bits/pthreadtypes.h>

//Struct for Philo

typedef struct s_philo
{
	int             philo;
	int             fork;
	int             time_to_die;
	int             time_to_eat;
	int             time_to_sleep;
	struct timeval  time;
	int             number_of_meals;
	pthread_mutex_t *forks;
	int             temp;
}   t_philo;

//Struct for General Info

typedef struct s_args
{
	int number_of_philo;
	int fork;
	struct timeval  s_time;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int number_of_meals;
	long long start_time;
	long long last_meal;
	pthread_mutex_t *mutex;
	int temp;
	t_philo *philos;
}   t_args;

//STRUCTS
t_args	*args(void);
t_args	*philos(void);

//START ARGS
int	start_args(int argc, char **argv);

//CREATE PHILO
void	*create_philo(int nop);

//ROUTINE
void	*routine(void *arg);
void	think(int nb);
void	nap(int nb);
void	eat(int nb);
int	check_fork(int nb);

//TIME
long long time_ms();
long long	current_time();

//ATOI
int	ft_atoi(const char *str);

//UTILS
int	is_dead(int i);

//COLORS
//Normal Colors
int	black(char *str);
int	red(char *str);
int	green(char *str);
int	yellow(char *str);
int	blue(char *str);
int	purple(char *str);
int	cyan(char *str);
int	white(char *str);
//Bold
int	bold_black(char *str);
int	bold_red(char *str);
int	bold_green(char *str);
int	bold_yellow(char *str);
int	bold_blue(char *str);
int	bold_purple(char *str);
int	bold_cyan(char *str);
int	bold_white(char *str);

#endif
