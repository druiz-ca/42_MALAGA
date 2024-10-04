/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 09:29:57 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/09/15 18:15:39 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_printing(t_philo *philo, t_action_philo action)
{
	long	time;
	// paq muteo la var write, de q sirve??
	if (pthread_mutex_lock(&philo->table->write) != 0)
		return (0);
	time = get_time_milli() - check_init_time(philo->table);
	// si ha terminado de comer y no esta muerto
	if (check_finish_dinner(philo->table) && action != DIE)
	{
		if (pthread_mutex_unlock(&philo->table->write) != 0)
			return (0);
		return (0);
	}
	if (action == FORK)
		printf("%ld %d %s\n", time, philo->philo_id, TAKE_FORKS);
	if (action == EAT)
		printf("%ld %d %s\n", time, philo->philo_id, EATING);
	if (action == SLEEP)
		printf("%ld %d %s\n", time, philo->philo_id, SLEEPING);
	if (action == THINK)
		printf("%ld %d %s\n", time, philo->philo_id, THINKING);
	if (action == DIE)
		printf("%ld %d %s\n", time, philo->philo_id, DIED);
	if (pthread_mutex_unlock(&philo->table->write) != 0)
		return (0);
	return (1);
}
/* SOLO COGE LOS TENEDORES, NO HACE NADA MÁS */
int	ft_take_forks(t_philo *philo)
{	// muteo el tenedor derecho // si esta muteado = return ??
	if (pthread_mutex_lock(philo->r_fork) != 0)
		return (1);
	/* SI HA TERMINADO LA CENA (la ft printing tmb lo comprueba )*/
	if (check_finish_dinner(philo->table) || !ft_printing(philo, FORK))
	{	// desmuteo el tenedor derecho q había cogido 
		if (pthread_mutex_unlock(philo->r_fork) != 0)
			return (1);
		return (1);
	}
	/* SI SOLO HAY UN FILO SALES X Q NO HAY 2 TENEDORES */
	if (one_philo_case(philo))
		return (1);
	/* SI DA ERROR AL HACER LOCK SOBREE EL OTRO TENEDOR Q HABIA COGIDO */
	//si estuvieses ya lock ese mutex solo esparia a q se demutee
	if (pthread_mutex_lock(philo->l_fork) != 0)
	{
		if (pthread_mutex_unlock(philo->r_fork) != 0)
			return (1);
		return (1);
	}
	/* VUELVO A COMPROBAR SI HA TERMINADO DE COMER= DESMUTEO LOS T.*/
	if (check_finish_dinner(philo->table) || !ft_printing(philo, FORK))
	{
		if (pthread_mutex_unlock(philo->r_fork) != 0)
			return (1);
		if (pthread_mutex_unlock(philo->l_fork) != 0)
			return (1);
		return (1);
	}
	return (0);
}

int	ft_eating(t_philo *philo)
{
	long	new_time;

	new_time = get_time_milli();
	/* ACTUALIZA EL TIEMPO DE LA ULTIMA VEZ Q COMIÓ A AHORA*/
	set_last_eat_time(philo, new_time);
	if (check_finish_dinner(philo->table) || !ft_printing(philo, EAT))
	{
		if (pthread_mutex_unlock(philo->l_fork) != 0)
			return (1);
		if (pthread_mutex_unlock(philo->r_fork) != 0)
			return (1);
		return (1);
	}
	/* SI HAN CAMBIADO EL VALOR DE: "DEBE COMER" (FLAG) ENTONCES COME 
	- must_eat es una flag q se controla desde otro lado (no necesario)*/
	if (philo->table->must_eat != -1)
		increase_eat_cont(philo); // incrementa contador d comidas
	/* LO PONE EN PAUSE EL HILO DURANTE EL TIEMPO ESPECIFIFICADO XRA COMER */
	ft_usleep(philo->table, philo->table->time_to_eat * 1000);
	return (0);
}

int	ft_sleeping(t_philo *philo)
{	// pq desmutea los 2 tenedores tanto si entra como si no??
	if (check_finish_dinner(philo->table) || !ft_printing(philo, SLEEP))
	{
		if (pthread_mutex_unlock(philo->l_fork) != 0)
			return (1);
		if (pthread_mutex_unlock(philo->r_fork) != 0)
			return (1);
		return (1);
	}
	if (pthread_mutex_unlock(philo->l_fork) != 0)
		return (1);
	if (pthread_mutex_unlock(philo->r_fork) != 0)
		return (1);
	/* LO PONE EN PAUSE EL HILO DURANTE EL TIEMPO ESPECIFIFICADO XRA DORMIR */
	if (ft_usleep(philo->table, philo->table->time_to_sleep * 1000))
		return (1);
	return (0);
}

int	ft_thinking(t_philo *philo)
{
	long	time_to_think;

	if (check_finish_dinner(philo->table) || !ft_printing(philo, THINK))
		return (1);
	//EL TIEMPO DE PENSAR DE LOS PARES ES EQUIVAL. AL Q TARDAN EN EMPEZAR
	// A COMER DESDE Q SE DESPIERTA
	if (philo->table->philo_num % 2 == 0)
		return (0);
	/* DESINCRONIZO A LOS HILOS IMAPRES PARA EVITAR DEATHLOOKS */
	// con poner 200 x ejemplo ya servía en vez de toda esa formula !!!!
	time_to_think = philo->table->time_to_eat * 2 - philo->table->time_to_sleep;
	if (time_to_think < 0) // solo checkeo 
		time_to_think = 0;
	/* SIMPLEMENTE LO PONE EN PAUSA los impares */
	if (ft_usleep(philo->table, time_to_think * 1000 / 2)) //
		return (1);
	return (0);
}
