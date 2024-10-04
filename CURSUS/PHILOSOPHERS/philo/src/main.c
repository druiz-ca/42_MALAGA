/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:43:16 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/09/15 16:27:40 by druiz-ca         ###   ########.fr       */
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
		start_dinner(table);
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
