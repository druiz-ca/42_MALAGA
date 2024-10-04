/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 12:17:00 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/07/21 10:04:36 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_rect(t_game *game)
{
	int		i2;
	int		x2;

	x2 = 0;
	i2 = 0;
	while (game->map[0][x2])
		x2++;
	while (game->map[i2])
	{	// comprueblo que todas las filas tengan la misma longitud
		if (ft_strlen2(game->map[i2]) != x2)
			return (1);
		i2++;
	}
	return (0);
}

int	check_wall_left_right(t_game *game)
{
	int		y;
	int		x;

	x = 0;
	y = 0;
	while (y < game->high)
	{ // compruebo que las paredes de la izquierda y derecha sean muros
		if (game->map[y][x] != '1')
			return (1);
		y++;
	}
	y = 0;
	x = game->width - 2; // -2 pq la ultima pos es '\0'
	while (y < game->high)
	{ // compruebo que las paredes de la izquierda y derecha sean muros
		if (game->map[y][x] != '1')
			return (1);
		y++;
	}
	return (0);
}

int	check_wall_up_down(t_game *game)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (x < game->width - 1)
	{ // compruebo que las paredes de arriba y abajo sean muros
		if (game->map[y][x] != '1')
			return (1);
		x++;
	}
	y = game->high - 1;
	x = 0;
	while (x < game->width - 1)
	{ // compruebo que las paredes de arriba y abajo sean muros
		if (game->map[y][x] != '1')
			return (1);
		x++;
	}
	return (0);
}

int	check_type_obj(t_game *game)
{
	int		x;
	int		y;

	y = game->high - 1;
	while (y >= 0)
	{
		x = game->width - 2;
		while (x >= 0)
		{ // compruebo que solo haya los objetos permitidos
			if (game->map[y][x] != '0' && game->map[y][x] != '1' &&
				game->map[y][x] != 'P' && game->map[y][x] != 'C' &&
				game->map[y][x] != 'E')
				return (1);
			x--;
		}
		y--;
	}
	return (0);
}

int	check_num_min_obj(t_game *game)
{
	int		x;
	int		y;

	y = game->high - 1;
	game->cont_p = 0;
	game->cont_c = 0;
	game->cont_e = 0;
	while (y >= 0)
	{ // compruebo que haya un jugador, al menos una moneda y una salida
		x = game->width - 2;
		while (x >= 0)
		{
			if (game->map[y][x] == 'P')
				game->cont_p++;
			if (game->map[y][x] == 'C')
				game->cont_c++;
			if (game->map[y][x] == 'E')
				game->cont_e++;
			x--;
		}
		y--;
	}
	if (game->cont_p != 1 || game->cont_c < 1 || game->cont_e < 1)
		return (1);
	return (0);
}
