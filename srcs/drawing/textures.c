/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:46:33 by akezanna          #+#    #+#             */
/*   Updated: 2021/03/17 15:49:06 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/includes.h"

void	check_side(t_game *game)
{
	if (game->ray.side == 0)
		if (game->ray.map_x - game->player.pos_x > 0)
		{
			game->ray.color = game->img.so_addr[game->img.height *
				game->ray.tex_y + game->ray.tex_x];
		}
		else
		{
			game->ray.color = game->img.no_addr[game->img.height *
				game->ray.tex_y + game->ray.tex_x];
		}
	else
	{
		if (game->ray.map_y - game->player.pos_y > 0)
		{
			game->ray.color = game->img.we_addr[game->img.height *
				game->ray.tex_y + game->ray.tex_x];
		}
		else
		{
			game->ray.color = game->img.ea_addr[game->img.height *
				game->ray.tex_y + game->ray.tex_x];
		}
	}
}

void	text_calculs(t_game *game, t_player *player, t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_x = player->pos_y + ray->perpwalldist * ray->raydir_y;
	else
		ray->wall_x = player->pos_x + ray->perpwalldist * ray->raydir_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * (double)game->img.width);
	if (ray->side == 0 && ray->raydir_x > 0)
		ray->tex_x = game->img.width - ray->tex_x - 1;
	if (ray->side == 1 && ray->raydir_y < 0)
		ray->tex_x = game->img.width - ray->tex_x - 1;
	ray->tex_step = 1.0 * game->img.height / ray->lineheight;
	ray->tex_pos = (ray->drawstart - ray->h / 2 + ray->lineheight / 2) *
			ray->tex_step;
	while (ray->drawstart < ray->drawend)
	{
		ray->tex_y = (int)ray->tex_pos;
		ray->tex_pos += ray->tex_step;
		check_side(game);
		game->img.texture[game->parsedata.win_width *
			ray->drawstart + ray->x] = ray->color;
		ray->drawstart++;
	}
}
