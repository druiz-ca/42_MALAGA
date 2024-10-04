/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 12:16:52 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/07/21 09:56:49 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_malloc_error(void)
{
	write(1, "Malloc Error\n", 12);
	exit(1);
}

void	calloc_copy_map(t_game *game)
{
	game->y2 = 0;
	game->x2 = 0;
	game->copy_map = malloc(sizeof(int *) * game->high);
	if (!game->copy_map)
		ft_malloc_error();
	while (game->y2 < game->high)
	{	// AQUI TAMPOCO NECESITARIA HACER MALLOC DE CADA FILA!!?!???!!?!?
		game->copy_map[game->y2] = malloc(sizeof(int *) * game->width);
		if (!game->copy_map[game->y2])
			ft_malloc_error();
		game->y2++;
	}
	game->y2 = 0;
	while (game->y2 < game->high)
	{
		game->x2 = 0;
		while (game->x2 < game->width)
		{// relleno de 0s el mapa copia, lo limpio, lo inicializo para que no de fallos
			game->copy_map[game->y2][game->x2] = 0;
			game->x2++;
		}
		game->y2++;
	}
}

void	search_player(t_game *game)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (game->map[y][x] != 'P')
	{
		x++;
		if (game->map[y][x] == '\0')
		{
			x = 0;
			y++;
		}
	}
	game->xp = x;
	game->yp = y;
}
