/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:02:14 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/09/15 17:24:16 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* COMPROBACION DE QUE EL MUTEO FUNCIONA Y DEVUELVE EL ESTADO DEL PHILO MUTEAO */
int	check_philo_status(t_table *table)
{
	int	philo_status;
	// si no se puede mutear STATE devolver 0
	if (pthread_mutex_lock(&table->state) != 0)
		return (0);
	// si ha podido, se guarda el estado del filosofo en philo_status
	philo_status = table->state_philo;// cuando ha cogido algun valor ???
	// si ha podido mutear, se desbloquea
	if (pthread_mutex_unlock(&table->state) != 0)
		return (0);
	//la alternativa seria devolver 1 (philo_status vale 1)
	return (philo_status);
}

long	check_last_eat(t_philo *philo)
{
	long	last_eat_time;

	if (pthread_mutex_lock(&philo->time_since_eat) != 0)
		return (0);
	last_eat_time = philo->time_from_eat;
	if (pthread_mutex_unlock(&philo->time_since_eat) != 0)
		return (0);
	return (last_eat_time);
}
/* COMPROBAR SI HA TERMINADO DE COMER */
/*DUDA DE LOS MUTEX:
si hago mutex con una var de tipo mutex, que efecto tiene eso
sobre el resto de variables, es decir pq al mutear una var solamente
bloquea el acceso a una var normal que nada tiene que ver ?!?!*/
int	check_finish_dinner(t_table *table)
{
	int	finish_dinner;
	// vuelve a usar una var de tipo mutex
	if (pthread_mutex_lock(&table->finish_meal) != 0)
		return (0);
	finish_dinner = table->finished_meal; // y una normal equivalente
	if (pthread_mutex_unlock(&table->finish_meal) != 0)
		return (0);
	return (finish_dinner);
}

int	check_if_full(t_philo *philo)
{
	int	times_eaten;

	if (pthread_mutex_lock(&philo->eat_cont_mutex) != 0)
		return (0);
	times_eaten = philo->eat_cont;
	if (pthread_mutex_unlock(&philo->eat_cont_mutex) != 0)
		return (0);
	return (times_eaten);
}
