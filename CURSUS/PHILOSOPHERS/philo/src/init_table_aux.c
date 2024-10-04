/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table_aux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 11:59:29 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/09/15 16:26:29 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_philo_mutex(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_num)
	{
		pthread_mutex_init(&table->philos[i].eat_cont_mutex, NULL);
		pthread_mutex_init(&table->philos[i].time_since_eat, NULL);
		i++;
	}
}

int	safe_mutex_init_2(t_table *table)
{
	if (pthread_mutex_init(&table->finish_meal, NULL) != 0)
	{
		pthread_mutex_destroy(&table->write);
		pthread_mutex_destroy(&table->state);
		pthread_mutex_destroy(&table->init_time);
		pthread_mutex_destroy(&table->start);
		return (0);
	}
	return (1);
}

int	safe_mutex_init(t_table *table)
{
	if (pthread_mutex_init(&table->write, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&table->state, NULL) != 0)
	{
		pthread_mutex_destroy(&table->write);
		return (0);
	}
	if (pthread_mutex_init(&table->init_time, NULL) != 0)
	{
		pthread_mutex_destroy(&table->write);
		pthread_mutex_destroy(&table->state);
		return (0);
	}
	if (pthread_mutex_init(&table->start, NULL) != 0)
	{
		pthread_mutex_destroy(&table->write);
		pthread_mutex_destroy(&table->state);
		pthread_mutex_destroy(&table->init_time);
		return (0);
	}
	if (!safe_mutex_init_2(table))
		return (0);
	return (1);
}
