/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 12:16:40 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/07/21 09:54:04 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_text(t_game *game)
{
	game->t_floor = mlx_load_png("textures/green.png");
	game->t_wall = mlx_load_png("textures/wall.png");
	game->t_player = mlx_load_png("textures/chicken1.png");
	game->t_coin = mlx_load_png("textures/chicken_leg.png");
	game->t_exit = mlx_load_png("textures/exit_on.png");
}

void	load_img(t_game *game)
{
	game->i_floor = mlx_texture_to_image(game->mlx, game->t_floor);
	game->i_wall = mlx_texture_to_image(game->mlx, game->t_wall);
	game->i_player = mlx_texture_to_image(game->mlx, game->t_player);
	game->i_coin = mlx_texture_to_image(game->mlx, game->t_coin);
	game->i_exit = mlx_texture_to_image(game->mlx, game->t_exit);
}

void	draw_map(t_game *g)
{
	while (g->map[g->y])
	{
		g->x = 0;
		while (g->map[g->y][g->x])
		{
			if (g->map[g->y][g->x] == '1') // si la casilla a la que me quiero mover es una pared pinto pared
				mlx_image_to_window(g->mlx, g->i_wall, g->x * 32, g->y * 32);
			if (g->map[g->y][g->x] == '0')
				mlx_image_to_window(g->mlx, g->i_floor,
					g->x * 32, g->y * 32);
			if (g->map[g->y][g->x] == 'P')
				mlx_image_to_window(g->mlx, g->i_player, g->x * 32, g->y * 32);
			if (g->map[g->y][g->x] == 'C')
			{
				g->num_coin++;
				mlx_image_to_window(g->mlx, g->i_coin, g->x * 32, g->y * 32);
			}
			if (g->map[g->y][g->x] == 'E')
				mlx_image_to_window(g->mlx, g->i_exit, g->x * 32, g->y * 32);
			g->x++;
		}
		g->y++;
	}
}

void	initialize_mlx(t_game *game)
{
	/* game width - 1 pq strlen devuelve la ult pos + 1 ('\0')*/
	game->mlx = mlx_init((game->width - 1) * 32, game->high * 32,
			"SO_LONG", true);
	if (!game->mlx)
		exit(EXIT_FAILURE);
	else
	{
		load_text(game);
		load_img(game);
		draw_map(game);
	}
}
