/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 12:16:31 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/07/21 09:55:59 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
/* FUNCION PARA ESCRIBIR LOS PASOS QUE VAS DANDO*/
void	write_steps(t_game *game)
{
	char	*test;

	test = ft_itoa(game->steps); // convierto el numero de pasos a char
	write(1, test, ft_strlen(test)); // escribo el numero de pasos
	write(1, "\n", 1);
	free(test);
}

void	initialize_game(t_game *game)
{
	game->high = 0;
	game->width = 0;
	game->x = 0;
	game->y = 0;
	game->xp = 0;
	game->yp = 0;
	game->player = 0;
	game->num_coin = 0;
	game->coin_left = 0;
	game->steps = 0;
	game->finished = 0;
	game->path = NULL;
	game->map = NULL;
	game->window = NULL;
	game->t_floor = NULL;
	game->t_wall = NULL;
	game->t_player = NULL;
	game->t_coin = NULL;
	game->t_exit = NULL;
	game->i_floor = NULL;
	game->i_wall = NULL;
	game->i_player = NULL;
	game->i_coin = NULL;
	game->i_exit = NULL;
}
/* FUNCION PARA SABER LAS MEDIDAS DEL MAPA*/
void	measure_map(t_game *game)
{
	int		fd;
	char	*linea;

	fd = 0;
	fd = open(game->path, O_RDONLY);
	linea = get_next_line(fd); //leo la primera linea
	game->width = ft_strlen(linea); // obtengo el ancho del mapa
	while (linea) // bajo linea a linea para obtener el alto del mapa
	{
		free(linea);
		linea = get_next_line(fd);
		game->high++; //
	}
	free(linea);
	close(fd);
}
/* HAGO UNA COPIA DEL MAPA*/
void	copy_map(t_game *game)
{
	int		i;
	int		fd;
	char	*linea;

	fd = 0;
	i = 0;
	fd = open(game->path, O_RDONLY);
	/* primero reservo memoria de las filas*/
	game->map = malloc(sizeof(char *) * (game->high + 1));
	if (!game->map)
	{
		free(game->map);
		write(1, "Error\nMalloc", 12);
		exit(EXIT_FAILURE);
	}
	/* voy leyendo el mapa y copiandolo */
	while (i < game->high)
	{
		linea = get_next_line(fd); // ???? PORQUE NO HE NECESITADO HACER MALLOC DE LINEA!!!!!
		game->map[i] = linea;
		game->map[i][ft_strlen(linea)] = '\0'; // añado el final de la linea
		i++;
	}
	game->map[i] = NULL; // añado el final del mapa
	close(fd);
}
/* COMPRUEBO LA EXTENSION */
void	check_ext_assign(char *cad, t_game *game)
{
	initialize_game(game);
	if (ft_strncmp(cad + ft_strlen(cad) - 4, ".ber", 4) != 0)
	{
		write(1, "Error\nExtension error", 21);
		exit(EXIT_FAILURE);
	}
	else
	{
		game->path = cad;
		measure_map(game);
		copy_map(game);
		checks_map(game);
	}
}
