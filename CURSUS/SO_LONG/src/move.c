/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 12:15:55 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/07/21 09:52:50 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_key_left(t_game *game)
{	
	if (game->map[game->yp][game->xp - 1] == '1') // si la casilla a la que me quiero mover es una pared
		return ;
	if (game->map[game->yp][game->xp - 1] == 'C') // si la casilla a la que me quiero mover es una moneda
		game->num_coin--; // resto una moneda
	if (game->map[game->yp][game->xp - 1] == 'E' && game->num_coin < 1) // si la casilla a la que me quiero mover es la salida y he cogido todas las monedas
	{
		mlx_close_window(game->mlx);
		ft_free_mlx_text(game);
		ft_free_mlx_img(game);
		write(1, "You Win\n", 8);
		return ;
	}
	else if (game->map[game->yp][game->xp - 1] == 'E' &&
		game->num_coin != 0) // si la casilla a la que me quiero mover es la salida y no he cogido todas las monedas
		return ;
	game->steps++;
	/* INTERCAMBIO LA POSICION DONDE ESTABA EL PERSONAJE A SUELO Y VECEVERSA PARA HACER QUE SE MUEVA */
	game->map[game->yp][game->xp] = '0';
	game->map[game->yp][game->xp - 1] = 'P';
	mlx_image_to_window(game->mlx, game->i_floor, game->xp * 32, game->yp * 32); // pinto el suelo en la posicion anterior
	game->xp -= 1;
	mlx_image_to_window(game->mlx, game->i_player, game->xp * 32,
		game->yp * 32); // pinto el personaje en la nueva posicion
	write(1, "Movements: ", 11);
	write_steps(game);
}

void	ft_key_down(t_game *game)
{
	if (game->map[game->yp + 1][game->xp] == '1')
		return ;
	if (game->map[game->yp + 1][game->xp] == 'C')
		game->num_coin--;
	if (game->map[game->yp + 1][game->xp] == 'E' && game->num_coin < 1)
	{
		mlx_close_window(game->mlx);
		ft_free_mlx_text(game);
		ft_free_mlx_img(game);
		write(1, "You Win\n", 8);
		return ;
	}
	else if (game->map[game->yp + 1][game->xp] == 'E' && game->num_coin != 0)
		return ;
	game->steps++;
	game->map[game->yp][game->xp] = '0';
	game->map[game->yp + 1][game->xp] = 'P';
	mlx_image_to_window(game->mlx, game->i_floor, game->xp * 32, game->yp * 32);
	game->yp += 1;
	mlx_image_to_window(game->mlx, game->i_player, game->xp * 32,
		game->yp * 32);
	write(1, "Movements: ", 11);
	write_steps(game);
}

void	ft_key_right(t_game *game)
{
	if (game->map[game->yp][game->xp + 1] == '1')
		return ;
	if (game->map[game->yp][game->xp + 1] == 'C')
		game->num_coin--;
	if (game->map[game->yp][game->xp + 1] == 'E' && game->num_coin < 1)
	{
		mlx_close_window(game->mlx + 1);
		ft_free_mlx_text(game);
		ft_free_mlx_img(game);
		write(1, "You Win\n", 8);
		return ;
	}
	else if (game->map[game->yp][game->xp + 1] == 'E' && game->num_coin != 0)
		return ;
	game->steps++;
	game->map[game->yp][game->xp] = '0';
	game->map[game->yp][game->xp + 1] = 'P';
	mlx_image_to_window(game->mlx, game->i_floor, game->xp * 32, game->yp * 32);
	game->xp += 1;
	mlx_image_to_window(game->mlx, game->i_player, game->xp * 32,
		game->yp * 32);
	write(1, "Movements: ", 11);
	write_steps(game);
}

void	ft_key_up(t_game *game)
{
	if (game->map[game->yp - 1][game->xp] == '1')
		return ;
	if (game->map[game->yp - 1][game->xp] == 'C')
		game->num_coin--;
	if (game->map[game->yp - 1][game->xp] == 'E' && game->num_coin < 1)
	{
		mlx_close_window(game->mlx);
		ft_free_mlx_text(game);
		ft_free_mlx_img(game);
		write(1, "You Win\n", 8);
		return ;
	}
	else if (game->map[game->yp - 1][game->xp] == 'E' && game->num_coin != 0)
		return ;
	game->steps++;
	game->map[game->yp][game->xp] = '0';
	game->map[game->yp - 1][game->xp] = 'P';
	mlx_image_to_window(game->mlx, game->i_floor, game->xp * 32, game->yp * 32);
	game->yp -= 1;
	mlx_image_to_window(game->mlx, game->i_player, game->xp * 32,
		game->yp * 32);
	write(1, "Movements: ", 11);
	write_steps(game);
}
/* FUNCION PARA CONTROL DE TECLAS */
void	ft_key(struct mlx_key_data key_data, void *param)
{
	t_game		*game;

	game = (t_game *)param; // casteo de void a t_game
	if (key_data.key == MLX_KEY_ESCAPE)
	{ // LA mlx contiene las macros de las teclas MLX_KEY_ESCAPE es la tecla ESC
		ft_free_mlx_text(game);
		ft_free_mlx_img(game);
		mlx_close_window(game->mlx);
		mlx_terminate(game->mlx);
		exit(0);
	}
	if (key_data.key == MLX_KEY_UP && key_data.action == MLX_PRESS)
		ft_key_up(game);
	if (key_data.key == MLX_KEY_RIGHT && key_data.action == MLX_PRESS)
		ft_key_right(game);
	if (key_data.key == MLX_KEY_DOWN && key_data.action == MLX_PRESS)
		ft_key_down(game);
	if (key_data.key == MLX_KEY_LEFT && key_data.action == MLX_PRESS)
		ft_key_left(game);
}
