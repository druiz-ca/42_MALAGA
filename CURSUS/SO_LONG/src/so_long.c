/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 12:16:21 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/06/27 19:49:09 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;
	int		aux;

	aux = 0;
	if (ac != 2)
	{
		write(1, "Error\nArgument error", 20);
		return (1);
	}
	game = malloc(sizeof(t_game));
	if (!game)
	{
		write(1, "Error\nMalloc error", 18);
		return (1);
	}
	game->xp = 0;
	game->yp = 0;
	check_ext_assign(av[1], game);
	initialize_mlx(game);
	search_player(game);
	mlx_key_hook(game->mlx, ft_key, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}
