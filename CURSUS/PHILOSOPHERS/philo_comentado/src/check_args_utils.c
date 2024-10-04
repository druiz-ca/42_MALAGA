/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:43:25 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/09/15 16:21:14 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_str_isdigit(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
		i++;
	while (str[i])
	{
		flag = 1;
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (flag);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while ((str[i] && str[i] <= 9 && str[i] >= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			nb = nb * 10 + str[i] - '0';
		else
			return (nb * sign);
		i++;
	}
	return (nb * sign);
}

int	*build_array(int argc, char **argv)
{
	int	*args;
	int	i;
	int	j;

	i = 1;
	j = 0;	// argc - 1 xq argc tmb incluye ./a.out
		// cuando el malloc es sobre ls ptr de la matriz es int *
	args = malloc(sizeof(int *) * (argc - 1));
	if (!args)
		return (0);
	while (j < argc) // inicializa a 0 los ptr de la matriz
		args[j++] = 0; //¿¿ si no lo hago peta??
	j = 0;
	while (i < argc) //no es <= pq argc tiene 1 de más x el ./a.out
	{	// pq no necesita malloc a cada string??
		args[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}
	return (args);
}
