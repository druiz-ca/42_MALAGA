/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:47:19 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/09/15 10:17:47 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_table_aux(t_table *table, int *args, int argc);
/* CREO LA ESTRUCTURA Y LA INICIALIZO */
t_table	*init_table(int argc, char **argv)
{
	int		*args;
	t_table	*table;

	args = build_array(argc, argv);
	if (!args)
		return (NULL);
	table = malloc(sizeof(t_table)); // como solo creo 1 tabla no mult. x nada
	if (!table)
		return (NULL);
	/* CREO TANTOS TENEDORES COMO FILOSOFOS HAYA */
	table->forks = malloc(sizeof(pthread_mutex_t) * args[0]);
	if (!table->forks)
	{
		free(args);
		free(table);//no libero los fork pq se supone q no ha podido hacer malloc
		return (NULL);
	}
	init_table_aux(table, args, argc);
	free(args);
	return (table);
}
/* GUARDO LOS ARGUMENTOS EN LA ESTRUCTURA MESA */
void	init_table_aux(t_table *table, int *args, int argc)
{
	table->philos = malloc(sizeof(t_philo) * args[0]);
	if (!table->philos)
	{
		free(args);
		free(table->forks);
		free(table);
		return ;
	}
	table->philo_num = args[0];
	table->time_to_die = args[1];
	table->time_to_eat = args[2];
	table->time_to_sleep = args[3];
	table->must_eat = -1; // VER PARA QUE -1 y no 0
	if (argc == 6)
		table->must_eat = args[4];
	table->state_philo = 0;
	table->initial_time = 0;
	table->start_meal = 0;
	table->finished_meal = 0;
	if (!init_mutex(table))
		return ;
	init_philos(table);
}
/* MUTEO TODO */
int	init_mutex(t_table *table)
{
	int	i;

	i = 0;
	/* DIVIDO EN 2 FUNCIONES LOS MUTEX XQ NO CABEN EN 25 LINEAS */
	if (!safe_mutex_init(table)) // muteo todo menos los tenedores
		return (0);
	while (i < table->philo_num)
	{	// SOLO MUTEO LOS TENEDORES, si error destruyo todos los mutex hechos
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
		{
			i--;
			while (i >= 0) //  a la ft mutex tengo que enviarlo x referencia
				pthread_mutex_destroy(&table->forks[i--]);
			pthread_mutex_destroy(&table->write);
			pthread_mutex_destroy(&table->state);
			pthread_mutex_destroy(&table->init_time);
			pthread_mutex_destroy(&table->start);
			pthread_mutex_destroy(&table->finish_meal);
			return (0);
		}
		i++;
	}
	/* SOLO MUTEO TODOS LOS FILO */
	init_philo_mutex(table);
	return (1);
}
/* INICIALIZO LA ESTRUCTURA FILO */
void	init_philos(t_table *table)
{
	int		i;
	long	philo_num; // pq usa una nueva var en vez de la original???

	i = 0;
	philo_num = table->philo_num;
	while (i < table->philo_num)
	{	//al tener un puntero a la struct philo puede recorrerlos uno a uno
		table->philos[i].philo_id = i + 1;
		table->philos[i].l_fork = &table->forks[i]; // pq &
		table->philos[i].r_fork = &table->forks[(i + 1) % philo_num]; //??
		if (table->philos[i].philo_id % 2 == 0) // si el filo es par ???
		{	// ?? porque repite los mismo que arriba??
			table->philos[i].r_fork = &table->forks[i]; // pq x referencia ??
			table->philos[i].l_fork = &table->forks[(i + 1) % philo_num];
		}
		table->philos[i].time_from_eat = 0;
		table->philos[i].eat_cont = 0;
		table->philos[i].table = table;
		i++;
	}
}
