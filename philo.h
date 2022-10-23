/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:33:32 by jlebre            #+#    #+#             */
/*   Updated: 2022/10/17 13:33:32 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/time.h>
# include <stdbool.h>
# include <pthread.h>

# define INT_MAX	2147483647
# define INT_MIN	-2147483648

typedef struct s_fork
{
	int				is_select;
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_philo
{
	int				id;
	int				meals;
	pthread_t		philo;
	long long		last_meal;
	long long		last_nap;
	t_fork			*left_fork;
	t_fork			*right_fork;
	long long		time;
	struct s_args	*args;
}	t_philo;

typedef struct s_args
{
	int				died;
	int				number_of_philosophers;
	int				number_of_meals;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		start_time;
	t_philo			*philos;
	t_fork			forks[1000];
	pthread_mutex_t	mutex;
	pthread_mutex_t	mutex_life;
}	t_args;

//CHECK
void				check(char **argv);
void				check_all_int(char **argv);
void				check_limits(char **argv);

//FORK
int					check_fork(t_philo *philo);
int					check_fork_2(t_philo *philo);
int					free_fork(t_philo *philo);

//CHECK LIFE
int					check_life(void);
int					check_life_all(void);
int					all_ate(t_philo *philo);
int					only_one_philosopher(void);

//START ARGS
t_args				*args(void);
t_philo				*start_philo(t_args *args);
void				start_args(int argc, char **argv, t_args *args);
void				start_mutex(t_philo *philo);

//PHILO
void				create_philo(t_args *args);
void				destroy_philo(t_philo *philo, t_args *args);
void				kill_everything(t_philo *philo);

//PRINT
int					print(t_philo *philo, char *str);
int					print_2(t_philo *philo, char *str);

//ROUTINE
void				*routine(void *arg);
int					eat(t_philo *philo);

//TIME
long long			get_time(void);
long long			current_time(t_args *args);

//UTILS
void				ft_error(char *str);
int					ft_isdigit(int i);
int					ft_atoi(const char *str);
long long			ft_atol(const char *str);

//COLORS
int					red(char *str);
int					green(char *str);
int					yellow(char *str);

#endif
