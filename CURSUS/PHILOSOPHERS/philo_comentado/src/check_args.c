/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:43:22 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/09/15 16:20:26 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_digits(int argc, char **argv)
{
	int	i;
	int	flag;

	i = 1;
	flag = 1;
	while (i < argc)
	{
		if (!ft_str_isdigit(argv[i]))
		{
			printf("Error in ""\"%s\": ", argv[i]);
			printf("Arguments must be numeric\n");
			flag = 0;
		}
		i++;
	}
	return (flag);
}
int	check_num_philos(int *args)
{
	if (args[0] > 250)
	{
		printf("Error in ""\"%d\": ", args[0]);
		printf("Too many philosophers\n");
		return (0);
	}
	if (args[0] <= 0)
	{
		printf("Error in ""\"%d\": ", args[0]);
		printf("Not enough philosophers\n");
		return (0);
	}
	return (1);
}
int	check_times(int *args)
{
	int	i;
	int	flag;

	i = 1;
	flag = 1;
	while (i < 4) // no es lo mismo i = 0, (i < 3)???
	{
		if (args[i] < 0)
		{
			printf("Error in ""\"%d\": ", args[i]);
			printf("Not enough philosophers\n");
			flag = 0;
		}
		i++;
	}
	return (flag);
}
int	check_eat_times(int *args)
{
	if (args[4] < 0)
	{
		printf("Error in ""\"%d\": ", args[4]);
		printf("They have to eat at least 0 times\n");
		return (0);
	}
	return (1);
}
int	check_args(int argc, char **argv)
{
	int	*args; // creo args solo para los check, luego lo libero
	int	flag;

	args = NULL;
	flag = 1;
	args = build_array(argc, argv);
	if (args == NULL)
		return (0);
	// no debería comprobar primero si son digitos que buildarray?
	if (!check_digits(argc, argv))
		flag = 0;
	if (!check_num_philos(args))
		flag = 0;
	if (!check_times(args))
		flag = 0;
	if (argc == 6)
	{
		if (!check_eat_times(args))
			flag = 0;
	}
	free(args);
	return (flag);
}
