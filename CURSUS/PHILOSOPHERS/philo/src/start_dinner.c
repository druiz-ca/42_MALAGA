/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:39:09 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/09/15 16:33:28 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	start_philos(t_table *table)
{
	int	i;
	int	ret;

	i = 0;
	while (i < table->philo_num)
	{
		ret = pthread_create(&table->philos[i].philo, \
		NULL, &ft_routine, &table->philos[i]);
		if (ret != 0)
		{
			printf("Error: Failed to create philo thread\n");
			return ;
		}
		i++;
	}
}

int	start_dinner(t_table *table)
{
	int	ret;

	ret = 0;
	start_philos(table);
	set_philo_status(table);
	ret = pthread_create(&table->monitor, NULL, &ft_monitor, table);
	if (ret != 0)
	{
		printf("Error: Failed to create philo thread\n");
		return (1);
	}
	return (0);
}
