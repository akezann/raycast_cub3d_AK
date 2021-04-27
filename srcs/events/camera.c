/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:13:18 by pmouhali          #+#    #+#             */
/*   Updated: 2021/03/17 18:02:19 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/includes.h"

void	camera_left(t_player *player)
{
	player->olddir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(ROTSPEED) - player->dir_y *
		sin(ROTSPEED);
	player->dir_y = player->olddir_x * sin(ROTSPEED) + player->dir_y *
		cos(ROTSPEED);
	player->oldplane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(ROTSPEED) - player->plane_y *
		sin(ROTSPEED);
	player->plane_y = player->oldplane_x * sin(ROTSPEED) + player->plane_y *
		cos(ROTSPEED);
}

void	camera_right(t_player *player)
{
	player->olddir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(-ROTSPEED) - player->dir_y *
		sin(-ROTSPEED);
	player->dir_y = player->olddir_x * sin(-ROTSPEED) + player->dir_y *
		cos(-ROTSPEED);
	player->oldplane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(-ROTSPEED) - player->plane_y *
		sin(-ROTSPEED);
	player->plane_y = player->oldplane_x * sin(-ROTSPEED) + player->plane_y *
		cos(-ROTSPEED);
}
