/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 09:29:52 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/09/15 18:24:50 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* PONER ESTADO DEL FILO EN 1, ES DECIR, Q SE HA CREADO CORRECTAMENTE */
int	set_philo_status(t_table *table)
{
	if (pthread_mutex_lock(&table->state) != 0)
		return (0);
	table->state_philo = 1;
	if (pthread_mutex_unlock(&table->state) != 0)
		return (0);
	return (1);
}
/* ESTABLECER TIEMPO DE LA ULTIMA COMIDA */
void	set_last_eat_time(t_philo *philo, long new_time)
{
	if (pthread_mutex_lock(&philo->time_since_eat) != 0)
		return ;
	philo->time_from_eat = new_time;
	if (pthread_mutex_unlock(&philo->time_since_eat) != 0)
		return ;
}
/* ESPECIFICAR SI HA TERMINADO LA CENA (LA FLAG) */
void	set_finish_dinner(t_table *table)
{
	if (pthread_mutex_lock(&table->finish_meal) != 0)
		return ;
	table->finished_meal = 1;
	if (pthread_mutex_unlock(&table->finish_meal) != 0)
		return ;
}
