/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 12:15:50 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/06/27 17:54:10 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free_mlx_text(t_game *game)
{
	mlx_delete_texture(game->t_floor);
	game->t_floor = NULL;
	mlx_delete_texture(game->t_wall);
	game->t_wall = NULL;
	mlx_delete_texture(game->t_player);
	game->t_player = NULL;
	mlx_delete_texture(game->t_coin);
	game->t_coin = NULL;
	mlx_delete_texture(game->t_exit);
	game->t_exit = NULL;
}

void	ft_free_mlx_img(t_game *game)
{
	mlx_delete_image(game->mlx, game->i_floor);
	game->i_floor = NULL;
	mlx_delete_image(game->mlx, game->i_wall);
	game->i_wall = NULL;
	mlx_delete_image(game->mlx, game->i_player);
	game->i_player = NULL;
	mlx_delete_image(game->mlx, game->i_coin);
	game->i_coin = NULL;
	mlx_delete_image(game->mlx, game->i_exit);
	game->i_exit = NULL;
}

void	ft_free_map(t_game *game)
{
	int		i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		game->map[i] = NULL;
		i++;
	}
	free(game->map);
	game->map = NULL;
	free(game);
	game = NULL;
}
