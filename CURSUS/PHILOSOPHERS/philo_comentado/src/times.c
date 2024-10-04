/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   times.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:19:33 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/09/15 18:28:20 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long	get_time_milli(void)
{
	struct timeval	tv;
	long			seconds_since_unix_epoch;
	long			this_second_milliseconds;

	if (gettimeofday(&tv, NULL) == -1)
	{
		printf("Error in gettimeofday()\n");
		return (0);
	}
	seconds_since_unix_epoch = tv.tv_sec * 1000;
	this_second_milliseconds = tv.tv_usec / 1000;
	return (seconds_since_unix_epoch + this_second_milliseconds);
}
/* PQ HACEN FALTA EN MILI Y EN MICRO ?? */
long	get_time_micro(void)
{
	struct timeval	tv; //estructura de la libreria "sys/time"
	long			seconds_since_unix_epoch;
	long			this_second_microseconds;

	if (gettimeofday(&tv, NULL) == -1)
	{
		printf("Error in gettimeofday()\n");
		return (0);
	}
	// lo multiplica para convertir a segundos??
	seconds_since_unix_epoch = tv.tv_sec * 1000000;
	this_second_microseconds = tv.tv_usec;
	// pq los suma??
	return (seconds_since_unix_epoch + this_second_microseconds);
}

/* COMPRUEBO QUE MUTEAR INIT_TIME NO DA ERRORES*/
long	check_init_time(t_table *table)
{
	long	init_time;

	if (pthread_mutex_lock(&table->init_time) != 0)
		return (0);
	init_time = table->initial_time; // el valor no es 0?
	if (pthread_mutex_unlock(&table->init_time) != 0)
		return (0);
	return (init_time);
}
/* PONGO EL TIEMPO INICIAL */
void	set_initial_time(t_table *table)
{
	if (pthread_mutex_lock(&table->init_time) != 0)
		return ;
	table->initial_time = get_time_milli(); // PQ AQUI EN MILI
	if (pthread_mutex_unlock(&table->init_time) != 0)
		return ;
	// tengo una varibale equivalente x cada var
	//q uso para hacer el mutex : init_time = initial_time
	// para guardar el valor que necesito controlar
}

int	ft_usleep(t_table *table, long sleep_time)
{
	long	sleep_start;
	long	elapsed;

	sleep_start = get_time_micro();
	/* MIENTRAS QUE NO LLEGUE EL TIEMPO DE TERMINAR DE DORMIR */
	while (get_time_micro() - sleep_start < sleep_time) // Y AQUI EN MICRO??
	{	/* COMPRUEBO SI HA TERMINADO DE COMER */
		if (check_finish_dinner(table))
			return (1);
		// elapsed significa transcurrido
		elapsed = sleep_time - (get_time_micro() - sleep_start);
		// si han pasado + d 1000 microsegundos= a dormir 500 ??
		if (elapsed > 1000) // ??
			usleep(500);
		else // sino espero a que llegue al tiempo de dormi ??
		{
			while (get_time_micro() - sleep_start < sleep_time)
				;
		}
	}
	return (0);
}
