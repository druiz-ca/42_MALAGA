/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:39:09 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/09/15 17:21:15 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* CREO LOS HILOS DE CADA FILOSOFO Q SE INICIAN CON SU RUTINA*/
void	start_philos(t_table *table)
{
	int	i;
	int	ret; // sobra el ret!!!

	i = 0;
	/* CREO 1 HILO X CADA FILO */
	while (i < table->philo_num)
	{
		ret = pthread_create(&table->philos[i].philo, NULL, &ft_routine, &table->philos[i]);
		if (ret != 0)
		{
			printf("Error: Failed to create philo thread\n");
			return ;// si da error como lo controlo en start_dinner???
		}
		i++;
	}
}
/* CREACION DE HILOS + RUTINAS */
int	start_dinner(t_table *table)
{
	int	ret; // ret??

	ret = 0;
	start_philos(table); // se bería llamar start_thread_philos
	set_philo_status(table); // si da error (1) como lo controlo??
	/* CREO EL HILO DEL MONITOR + SU RUTINA */
	ret = pthread_create(&table->monitor, NULL, &ft_monitor, table);
	if (ret != 0)
	{
		printf("Error: Failed to create philo thread\n");
		return (1);
	}
	return (0);
}
