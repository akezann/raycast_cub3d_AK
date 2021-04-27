/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 10:20:37 by mohamed           #+#    #+#             */
/*   Updated: 2021/03/18 12:54:40 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/includes.h"
#include "./../parsing/structparse.h"
#include "./../../libft/libft.h"

void		ft_sort_sprites(t_game *game)
{
	double	distance[game->parsedata.sprite_num];
	int		tmp;
	int		disttmp;
	int		i;

	i = -1;
	while (++i < game->parsedata.sprite_num)
	{
		distance[i] = ((game->player.pos_x - game->sprite[i].x) *
		(game->player.pos_x - game->sprite[i].x) + (game->player.pos_y -
		game->sprite[i].y) * (game->player.pos_y - game->sprite[i].y));
		game->sprite_order[i] = i;
	}
	i = -1;
	while (++i < game->parsedata.sprite_num - 1)
		if (distance[i] < distance[i + 1])
		{
			disttmp = distance[i];
			distance[i] = distance[i + 1];
			distance[i + 1] = disttmp;
			tmp = game->sprite_order[i];
			game->sprite_order[i] = game->sprite_order[i + 1];
			game->sprite_order[i + 1] = tmp;
			i = -1;
		}
}

t_sprite	*ft_get_sprites(t_game *game)
{
	int			x;
	int			y;
	int			i;
	t_sprite	*sprites;

	x = 0;
	i = 0;
	sprites = malloc(sizeof(t_sprite) * game->parsedata.sprite_num);
	game->sprite_order = malloc(sizeof(int) * game->parsedata.sprite_num);
	while (x < game->parsedata.map_rows)
	{
		y = 0;
		while (y < game->parsedata.map_cols)
		{
			if (game->parsedata.map[x][y] == '2')
			{
				sprites[i].x = x + 0.5;
				sprites[i++].y = y + 0.5;
			}
			y++;
		}
		x++;
	}
	return (sprites);
}

void		draw_sprite(t_game *game)
{
	game->draw_sp.texx = (int)(256 * (game->draw_sp.stripe -
		(-game->draw_sp.spritewidth / 2 + game->draw_sp.spritescreenx)) *
		game->img.width / game->draw_sp.spritewidth) / 256;
	if (game->draw_sp.transformy > 0 && game->draw_sp.stripe > 0 &&
		game->draw_sp.stripe < game->parsedata.win_width &&
		game->draw_sp.transformy < game->z_buff[game->draw_sp.stripe])
	{
		game->draw_sp.y = game->draw_sp.drawstarty;
		while (game->draw_sp.y < game->draw_sp.drawendy)
		{
			game->draw_sp.d = (game->draw_sp.y) * 256 -
			game->parsedata.win_height * 128 + game->draw_sp.spriteheight * 128;
			game->draw_sp.texy =
				((game->draw_sp.d * game->img.height) /
				game->draw_sp.spriteheight) / 256;
			game->draw_sp.color =
				game->img.s_addr[(game->img.width *
				game->draw_sp.texy) + game->draw_sp.texx];
			if (game->draw_sp.color > 0 && game->draw_sp.color != 0xfff)
				game->img.texture[(game->draw_sp.y *
				game->parsedata.win_width) +
				game->draw_sp.stripe] = game->draw_sp.color;
			game->draw_sp.y++;
		}
	}
}

void		cal_sprite_size(t_game *game)
{
	game->draw_sp.spritescreenx = (int)(game->parsedata.win_width / 2) *
		(1 + game->draw_sp.transformx / game->draw_sp.transformy);
	game->draw_sp.spriteheight = abs((int)(game->parsedata.win_height /
		(game->draw_sp.transformy)));
	game->draw_sp.drawstarty = -game->draw_sp.spriteheight / 2 +
		game->parsedata.win_height / 2;
	if (game->draw_sp.drawstarty < 0)
		game->draw_sp.drawstarty = 0;
	game->draw_sp.drawendy = game->draw_sp.spriteheight / 2 +
		game->parsedata.win_height / 2;
	if (game->draw_sp.drawendy >= game->parsedata.win_height)
		game->draw_sp.drawendy = game->parsedata.win_height - 1;
	game->draw_sp.spritewidth = abs((int)(game->parsedata.win_height /
		(game->draw_sp.transformy)));
	game->draw_sp.drawstartx = -game->draw_sp.spritewidth /
		2 + game->draw_sp.spritescreenx;
	if (game->draw_sp.drawstartx < 0)
		game->draw_sp.drawstartx = 0;
	game->draw_sp.drawendx = game->draw_sp.spritewidth /
		2 + game->draw_sp.spritescreenx;
	if (game->draw_sp.drawendx >= game->parsedata.win_width)
		game->draw_sp.drawendx = game->parsedata.win_width - 1;
	game->draw_sp.stripe = game->draw_sp.drawstartx;
}

void		ft_sprites(t_game *game)
{
	int		i;

	i = 0;
	ft_sort_sprites(game);
	while (i < game->parsedata.sprite_num)
	{
		game->draw_sp.spritex = game->sprite[game->sprite_order[i]].x -
			game->player.pos_x;
		game->draw_sp.spritey = game->sprite[game->sprite_order[i]].y -
			game->player.pos_y;
		game->draw_sp.invdet = 1.0 / (game->player.plane_x *
			game->player.dir_y - game->player.dir_x * game->player.plane_y);
		game->draw_sp.transformx = game->draw_sp.invdet * (game->player.dir_y *
		game->draw_sp.spritex - game->player.dir_x * game->draw_sp.spritey);
		game->draw_sp.transformy = game->draw_sp.invdet *
		(-game->player.plane_y *
		game->draw_sp.spritex + game->player.plane_x * game->draw_sp.spritey);
		cal_sprite_size(game);
		while (game->draw_sp.stripe < game->draw_sp.drawendx)
		{
			draw_sprite(game);
			game->draw_sp.stripe++;
		}
		i++;
	}
}
