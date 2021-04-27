/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cub3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:13:36 by akezanna          #+#    #+#             */
/*   Updated: 2021/03/21 18:21:42 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/includes.h"

void		init_player(t_game *game)
{
	get_player_pos(&game->player, &game->parsedata);
	if (game->parsedata.dir_type == 'N' || game->parsedata.dir_type == 'S')
	{
		game->player.dir_x = (game->parsedata.dir_type == 'N') ? -1. : 1.;
		game->player.dir_y = 0.;
		game->player.plane_x = 0.;
		game->player.plane_y = (game->parsedata.dir_type == 'N') ? 0.66 : -0.66;
	}
	else if (game->parsedata.dir_type == 'W' || game->parsedata.dir_type == 'E')
	{
		game->player.dir_x = 0.;
		game->player.dir_y = (game->parsedata.dir_type == 'W') ? -1. : 1.;
		game->player.plane_x = (game->parsedata.dir_type == 'W') ? -0.66 : 0.66;
		game->player.plane_y = 0.;
	}
}

void		window_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->parsedata.win_width,
		game->parsedata.win_height, "cub3d 1337");
}

void		img_init(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, game->parsedata.win_width,
		game->parsedata.win_height);
	game->img.texture = (int *)mlx_get_data_addr(game->img.img, &game->img.bpp,
		&game->img.size_l, &game->img.endian);
	game->img.no_text = mlx_xpm_file_to_image(game->mlx,
		game->parsedata.no_text, &game->img.width, &game->img.height);
	game->img.no_addr = (int *)mlx_get_data_addr(game->img.no_text,
		&game->img.bpp, &game->img.size_l, &game->img.endian);
	game->img.so_text = mlx_xpm_file_to_image(game->mlx,
		game->parsedata.so_text, &game->img.width, &game->img.height);
	game->img.so_addr = (int *)mlx_get_data_addr(game->img.so_text,
		&game->img.bpp, &game->img.size_l, &game->img.endian);
	game->img.we_text = mlx_xpm_file_to_image(game->mlx,
		game->parsedata.we_text, &game->img.width, &game->img.height);
	game->img.we_addr = (int *)mlx_get_data_addr(game->img.we_text,
		&game->img.bpp, &game->img.size_l, &game->img.endian);
	game->img.ea_text = mlx_xpm_file_to_image(game->mlx,
		game->parsedata.ea_text, &game->img.width, &game->img.height);
	game->img.ea_addr = (int *)mlx_get_data_addr(game->img.ea_text,
		&game->img.bpp, &game->img.size_l, &game->img.endian);
	game->img.sp_text = mlx_xpm_file_to_image(game->mlx,
		game->parsedata.s_text, &game->img.width, &game->img.height);
	game->img.s_addr = (int *)mlx_get_data_addr(game->img.sp_text,
		&game->img.bpp, &game->img.size_l, &game->img.endian);
}

int			draw_loop(t_game *game)
{
	draw_walls(game, &game->ray, &game->player,
		&game->img);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}

int			main(int n, char **ar)
{
	int		fd;
	t_game	game;

	fd = open(ar[1], O_RDONLY);
	check_args(&game, n, ar, fd);
	if (!save_map(&game.parsedata, fd))
		return (0);
	window_init(&game);
	img_init(&game);
	count_sprite(&game.parsedata);
	game.sprite = ft_get_sprites(&game);
	init_player(&game);
	mlx_hook(game.win, 2, 1L << 0, key_hook, &game);
	mlx_loop_hook(game.mlx, &draw_loop, &game);
	mlx_loop(game.mlx);
}
