/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:17:07 by akezanna          #+#    #+#             */
/*   Updated: 2021/03/20 14:40:08 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/includes.h"

static	void	get_perp(t_ray *ray, t_player *player)
{
	if (ray->side == 0)
		ray->perpwalldist = (ray->map_x - player->pos_x +
			(1 - ray->step_x) / 2) / ray->raydir_x;
	else
		ray->perpwalldist = (ray->map_y - player->pos_y +
			(1 - ray->step_y) / 2) / ray->raydir_y;
	ray->lineheight = (int)(ray->h / ray->perpwalldist);
	ray->drawstart = -ray->lineheight / 2 + ray->h / 2;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = ray->lineheight / 2 + ray->h / 2;
	if (ray->drawend >= ray->h)
		ray->drawend = ray->h - 1;
}

static	void	init_ray(t_ray *ray, t_player *player, t_parsedata *parsedata)
{
	ray->camera_x = 2 * ray->x / (double)parsedata->win_width - 1;
	ray->raydir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->raydir_y = player->dir_y + player->plane_y * ray->camera_x;
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
	ray->h = parsedata->win_height;
	ray->hit = 0;
	ray->deltadist_x = fabs(1 / ray->raydir_x);
	ray->deltadist_y = fabs(1 / ray->raydir_y);
	get_sidedistances(ray, player);
}

static	void	put_f_c_color(t_ray *ray, t_img *img, t_parsedata *parsedata)
{
	int	y;

	y = 0;
	while (y < ray->drawstart)
		img->texture[parsedata->win_width * y++ + ray->x] =
			parsedata->ceil_color;
	y = ray->drawend + 1;
	while (y < ray->h)
		img->texture[parsedata->win_width * y++ + ray->x] =
			parsedata->floor_color;
}

void			draw_walls(t_game *game, t_ray *ray, t_player *player,
				t_img *img)
{
	ray->x = 0;
	ray->lineheight = 0;
	if (!(game->z_buff = malloc(sizeof(double) *
		game->parsedata.win_width + 1)))
		exit(0);
	mlx_clear_window(game->mlx, game->win);
	while (ray->x < game->parsedata.win_width)
	{
		init_ray(ray, player, &game->parsedata);
		dda(ray, &game->parsedata);
		get_perp(ray, player);
		game->z_buff[ray->x] = game->ray.perpwalldist;
		put_f_c_color(ray, img, &game->parsedata);
		text_calculs(game, player, ray);
		ray->x++;
	}
	ft_sprites(game);
	free(game->z_buff);
	if (game->save == 1)
		ft_screenshot(game);
}
