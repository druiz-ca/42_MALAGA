/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:43:16 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/09/15 16:15:32 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	if (argc == 5 || argc == 6)
	{
		if (!check_args(argc, argv))
			return (1);
		table = init_table(argc, argv);
		if (!table)
			return (1);
		start_dinner(table);//d q sirve q return 1 o 0? deberia ser void?
		finish_dinner(table);
		destroy_mutex(table);
		free_table(table);
	}
	else
	{
		printf("Error: Incorrect number of arguments\n");
		return (1);
	}
	return (0);
}
/* ----------------------------------------------------------------------
								NOTAS
-------------------------------------------------------------------------
- Necesito tener un puntero a la estructura "philo" desde la estructura 
  "table" para poder acceder a cada philo diferente e ir modificandolo
- Solo sehace mutex sobre var o ptr que sean de tipo pthread_mutex_t, el
  resto de variables no se mutean
- en el .h = solo necesito poner las ft que son llamadas desde otro .c
  (es decir, las que se llamen desde el mismo .c no es neceario)
  - si el orden de las cabeceras en el .h no esta ok ERROR


-------------------------------------------------------------------------
								NOVEDADES
-------------------------------------------------------------------------
- LIBRERIA PARA HILOS : <pthread.h>
- pthread_mutex_init: es un tipo de objeto de sincronización utilizado
	 para proteger secciones de código que no pueden ser ejecutadas 
	 simultáneamente por más de un hilo permitiendo que solo un hilo 
	 acceda a un recurso o sección de código a la vez.
- pthread_mutex_destroy
- pthread_create
- pthread_join
- asleep
- gettimeofday


*/