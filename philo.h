/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:48:16 by jlebre            #+#    #+#             */
/*   Updated: 2022/09/27 14:49:45 by jlebre           ###   ########.fr       */
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
    int             start_time;
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
    int start_time;
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
void	dorme(int nb);
void	eat(int nb);
int	check_fork(int nb);

//TIME
long long time_ms();

//ATOI
int	ft_atoi(const char *str);

#endif
