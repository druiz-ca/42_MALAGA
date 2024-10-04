/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_map_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 12:15:34 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/07/21 10:03:28 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_coin_exit(t_game *game, int y, int x)
{/* si en la pos de la copia del mapa no he pasado aún (0) y en la pos del mapa no es un muro = entro */
	if (game->copy_map[y][x] == 0 && game->map[y][x] != '1')
	{
		if (game->copy_map[y][x] == 1) // si ya he pasado por esa casilla return
			return ;
		if (game->map[y][x] == 'C') // si la casilla es una moneda la cojo
			game->coin_left--; // resto una moneda
		if (game->map[y][x] == 'E') // si la casilla es la salida y no he cogido todas las monedas return
			return ;
		game->copy_map[y][x] = 1; // marco la casilla como pasada
		check_coin_exit(game, y, x - 1); // compruebo la casilla de la izquierda
		check_coin_exit(game, y, x + 1); // compruebo la casilla de la derecha
		check_coin_exit(game, y + 1, x); // compruebo la casilla de abajo
		check_coin_exit(game, y - 1, x); // compruebo la casilla de arriba
	}	// con la recursividad lo que hago es que no pare de llamarse a la misma funcion con todas las posiciones
	return ; // hasta que no haya pasado por todas las casillas y las haya marcado entonces llegue al return
}

int	check_possible(t_game *game)
{
	int		aux;

	aux = 0;
	search_player(game); // busco al jugador
	calloc_copy_map(game); // copio el mapa y lo limpio
	check_coin_exit(game, game->yp, game->xp);
	while (aux < game->high) // cuando acabo libero todo el mapa
		free (game->copy_map[aux++]);
	free(game->copy_map);
	game->copy_map = NULL;
	if (game->coin_left != 0) // si no he podido recoger todas las monedas devuelvo error
		return (1);
	else
		return (0);
}

int	check_map(t_game *game)
{
	if (check_rect(game) == 1)
		return (1);
	if (check_wall_left_right(game) == 1)
		return (1);
	if (check_wall_up_down(game) == 1)
		return (1);
	if (check_type_obj(game) == 1)
		return (1);
	if (check_num_min_obj(game) == 1)
		return (1);
	return (0);
}

void	checks_map(t_game *game)
{	/* hago todas las comprobaciones del mapa*/
	if (check_map(game) == 1)
	{
		write(1, "Error\nMap Error", 15);
		ft_free_map(game);
		exit(EXIT_FAILURE);
	}
	check_possible(game);
	if (game->coin_left > 0)
	{
		write(1, "Error\nMap error", 15);
		ft_free_map(game);
		exit(EXIT_FAILURE);
	}
}
