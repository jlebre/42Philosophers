/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:33:00 by jlebre            #+#    #+#             */
/*   Updated: 2022/10/17 13:33:00 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	black(char *str)
{
	return (printf("\033[0;30m%s\033[0m", str));
}

int	red(char *str)
{
	return (printf("\033[0;31m%s\033[0m", str));
}

int	green(char *str)
{
	return (printf("\033[0;32m%s\033[0m", str));
}

int	yellow(char *str)
{
	return (printf("\033[0;33m%s\033[0m", str));
}
