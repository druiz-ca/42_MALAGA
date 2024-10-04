/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:11:58 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/09/15 17:59:13 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* 	SI EL FILO ES EL 1 DESMUTEA EL TENEDOR DERECHO ??  */
int	one_philo_case(t_philo *philo)
{	
	if (philo->table->philo_num == 1)
	{
		while (!check_finish_dinner(philo->table))
			;
		if (pthread_mutex_unlock(philo->r_fork) != 0)
			return (1);
		return (1);
	}
	return (0);
}

void	increase_eat_cont(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->eat_cont_mutex) != 0)
		return ;
	philo->eat_cont++;
	if (pthread_mutex_unlock(&philo->eat_cont_mutex) != 0)
		return ;
}

void	*ft_routine(void *philosopher)
{
	t_philo	*philo; // al ser la rutina de los filo ya no uso la struct table
	// al recibirlo como void hay que castearlo
	philo = (t_philo *)philosopher;
	// bucle infinito hasta que se cumpla la condicion
	// ESPERA A QUE TODOS LOS HILOS SE HAYAN CREADO, es decir, 
	//q se haya ejecutado la siguiente ft = set_philo_status = 1
	while (!check_philo_status(philo->table))
		; // de esta forma los filos q se van creando no hacen nada hasta que
		//esten todos creados
	/* ESPERO A QUE LA VAR INIT_TIME SE HAYA RELLENADO X EL MONITOR */
	while (!check_init_time(philo->table))
		;
	/* LE DOY PRIORIDAD A QUE COMAN LOS IMPARES, DURMIENDO A LOS PARES
	PARA EVITAR DEADLOCKS(cuando el codigo se blooquea xq todos los mutex
	estan bloqueados)*/
	if (philo->table->philo_num != 1 && philo->philo_id % 2 == 0)
		ft_usleep(philo->table, 30000);
	/* INICIALIZO EL TIEMPO DE CADA PHILO A 0 (TIEMPO ACTUAL) 
	cuando empieza, la ultima vez q comió es cuando empieza el prog. */
	set_last_eat_time(philo, check_init_time(philo->table));
		// le envío la estruct philo + el tiempo inicial(la hora a l q se creó)
	/* MIENTRAS QUE NO ACABE LA CENA (finished_meal = 1)*/
	while (!check_finish_dinner(philo->table))
	{
		if (ft_take_forks(philo))
			break ;
		if (ft_eating(philo))
			break ;
		if (ft_sleeping(philo))
			break ;
		if (ft_thinking(philo))
			break ;
	}
	return (NULL); // pq si es una ft void ??
}
