/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:33:56 by jlebre            #+#    #+#             */
/*   Updated: 2022/10/17 13:33:56 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(char	*str)
{
	red("Error!\n");
	red(str);
	exit(0);
}

int	ft_isdigit(int i)
{
	if ((i > 47) && (i < 58))
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	val;
	int	sinal;

	i = 0;
	val = 0;
	sinal = 1;
	while ((str[i] == '\n') || (str[i] == '\r') || (str[i] == '\t')
		|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == ' '))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sinal *= -1;
		i++;
	}
	while ((str[i] >= 48) && (str[i] <= 57))
	{	
		val *= 10;
		val += str[i] - 48;
		i++;
	}
	return (sinal * val);
}

long long	ft_atol(const char *str)
{
	int			i;
	long long	val;
	int			sinal;

	i = 0;
	val = 0;
	sinal = 1;
	while ((str[i] == '\n') || (str[i] == '\r') || (str[i] == '\t')
		|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sinal *= -1;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{	
		val *= 10;
		val += str[i] - 48;
		i++;
	}
	return (sinal * val);
}
