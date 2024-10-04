/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 12:16:00 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/06/27 19:45:49 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line/get_next_line.h"
#include "MLX42/include/MLX42/MLX42.h"

typedef struct estructura
{
	mlx_t			*mlx;
	int				high;
	int				width;
	int				x;
	int				y;
	int				xp;
	int				yp;
	int				x2;
	int				y2;
	int				cont_p;
	int				cont_c;
	int				cont_e;
	int				player;
	int				num_coin;
	int				coin_left;
	int				steps;
	int				finished;
	char			*path;
	char			**map;
	void			*window;
	int				**copy_map;
	mlx_texture_t	*t_floor;
	mlx_texture_t	*t_wall;
	mlx_texture_t	*t_player;
	mlx_texture_t	*t_coin;
	mlx_texture_t	*t_exit;
	mlx_image_t		*i_floor;
	mlx_image_t		*i_wall;
	mlx_image_t		*i_player;
	mlx_image_t		*i_coin;
	mlx_image_t		*i_exit;
}	t_game;

void	initialize_game(t_game *game);
void	check_ext_assign(char *cad, t_game *game);
void	measure_map(t_game *game);
void	copy_map(t_game *game);
int		check_rect(t_game *game);
int		check_wall_left_right(t_game *game);
int		check_wall_up_down(t_game *game);
int		check_type_obj(t_game *game);
int		check_num_min_obj(t_game *game);
void	check_coin_exit(t_game *game, int y, int x);
void	calloc_copy_map(t_game *game);
void	search_player(t_game *game);
int		check_possible(t_game *game);
int		check_map(t_game *game);
void	ft_free_mlx_text(t_game *game);
void	ft_free_mlx_img(t_game *game);
void	ft_free_map(t_game *game);
void	checks_map(t_game *game);
void	initialize_mlx(t_game *game);
void	load_text(t_game *game);
void	load_img(t_game *game);
void	draw_map(t_game *game);
void	search_player(t_game *game);
void	ft_key_left(t_game *game);
void	ft_key_down(t_game *game);
void	ft_key_right(t_game *game);
void	ft_ley_up(t_game *game);
void	ft_key(struct mlx_key_data key_data, void *param);
void	ft_malloc_error(void);
void	write_steps(t_game *game);
int		ft_strlen2(char *str);