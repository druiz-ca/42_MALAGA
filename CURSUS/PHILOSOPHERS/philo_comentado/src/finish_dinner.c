/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_dinner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 09:29:00 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/09/15 18:39:13 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* UNE EL HILO DEL MONITOR */
void	ft_wait_monitor(t_table *table)
{
	if (pthread_join(table->monitor, NULL) != 0)
		printf("Error in pthread_join\n");
}
/* UNE LOS HILOS DE TODOS LOS FILO */
void	ft_wait_philos(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_num)
		pthread_join(table->philos[i++].philo, NULL);
}
/* UNIR LOS HILOS DEL MONITOR Y LOS FILOS */
void	finish_dinner(t_table *table)
{
	ft_wait_monitor(table); //pq le llama wait??
	ft_wait_philos(table);
}
