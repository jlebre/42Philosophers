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
# include <pthread.h>

# define INT_MAX	2147483647
# define INT_MIN	-2147483648

typedef struct s_philo
{
	int				id;
	int				meals;
	long long		last_meal;
	long long		last_nap;
	pthread_t		philo;
	struct s_args	*args;
}	t_philo;

typedef struct s_args
{
	int				died;
	int				lock;
	int				number_of_philosophers;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		start_time;
	pthread_mutex_t	fork[200];
	pthread_mutex_t	mut_died;
	pthread_mutex_t	check_print;
	pthread_mutex_t	print;
	pthread_mutex_t	eat;
	int				number_of_meals;
}	t_args;

//CHECK
void				check(char **argv);
void				check_all_int(char **argv);
void				check_limits(char **argv);
int					check_if_dead(t_philo *philo);
int					check_fork(t_philo *philo);
int					check_fork_2(t_philo *philo);

//START ARGS
void				start_args(int argc, char **argv, t_args *args);
t_philo				*start_philo(t_args *args);
void				start_mutex(t_philo *philo);

//PHILO
void				create_philo(t_args *args);
int					destroy_philo(t_philo *philo, t_args *args);
int					kill_everything(t_philo *philo);

//PRINT
int					print(t_philo *philo, char *str);
int					print_2(t_philo *philo, char *str);

//ROUTINE
void				*routine(void *arg);
int					eat(t_philo *philo);
int					eat_2(t_philo *philo);

//TIME
long long			get_time(void);
long long			current_time(t_args *args);

//UTILS
void				ft_error(char	*str);
int					ft_isdigit(int i);
int					ft_atoi(const char *str);
long long			ft_atol(const char *str);

//COLORS
int					red(char *str);
int					green(char *str);
int					yellow(char *str);

#endif
