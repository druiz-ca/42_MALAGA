/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 09:29:06 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/09/15 16:26:15 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	destroy_mutex(t_table *table)
{
	int	i;

	pthread_mutex_destroy(&table->write);
	pthread_mutex_destroy(&table->state);
	pthread_mutex_destroy(&table->init_time);
	pthread_mutex_destroy(&table->start);
	pthread_mutex_destroy(&table->finish_meal);
	i = 0;
	while (i < table->philo_num)
	{
		pthread_mutex_destroy(&table->forks[i]);
		pthread_mutex_destroy(&table->philos[i].eat_cont_mutex);
		pthread_mutex_destroy(&table->philos[i].time_since_eat);
		i++;
	}
}

void	free_table(t_table *table)
{
	free(table->forks);
	free(table->philos);
	free(table);
}
