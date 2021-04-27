/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:14:03 by pmouhali          #+#    #+#             */
/*   Updated: 2021/03/17 18:05:36 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/includes.h"

void	move_right(t_player *player, t_parsedata *parsedata)
{
	double ndirx;
	double ndiry;

	ndirx = player->dir_y;
	ndiry = -player->dir_x;
	if (parsedata->map[(int)(player->pos_x + ndirx * MOVESPEED)]
		[(int)player->pos_y] == '0')
		player->pos_x += ndirx * MOVESPEED;
	if (parsedata->map[(int)player->pos_x]
		[(int)(player->pos_y + ndiry * MOVESPEED)] == '0')
		player->pos_y += ndiry * MOVESPEED;
	if (parsedata->map[(int)(player->pos_x + ndirx * MOVESPEED)]
			[(int)player->pos_y] == parsedata->dir_type)
		player->pos_x += ndirx * MOVESPEED;
	if (parsedata->map[(int)player->pos_x]
		[(int)(player->pos_y + ndiry * MOVESPEED)] == parsedata->dir_type)
		player->pos_y += ndiry * MOVESPEED;
}

void	move_left(t_player *player, t_parsedata *parsedata)
{
	double ndir_x;
	double ndir_y;

	ndir_x = -player->dir_y;
	ndir_y = player->dir_x;
	if (parsedata->map[(int)(player->pos_x + ndir_x * MOVESPEED)]
		[(int)player->pos_y] == '0')
		player->pos_x += ndir_x * MOVESPEED;
	if (parsedata->map[(int)player->pos_x]
		[(int)(player->pos_y + ndir_y * MOVESPEED)] == '0')
		player->pos_y += ndir_y * MOVESPEED;
	if (parsedata->map[(int)(player->pos_x + ndir_x * MOVESPEED)]
		[(int)player->pos_y] == parsedata->dir_type)
		player->pos_x += ndir_x * MOVESPEED;
	if (parsedata->map[(int)player->pos_x]
		[(int)(player->pos_y + ndir_y * MOVESPEED)] == parsedata->dir_type)
		player->pos_y += ndir_y * MOVESPEED;
}

void	move_forward(t_player *player, t_parsedata *parsedata)
{
	if (parsedata->map[(int)(player->pos_x + player->dir_x * MOVESPEED)]
		[(int)player->pos_y] == '0')
		player->pos_x += player->dir_x * MOVESPEED;
	if (parsedata->map[(int)player->pos_x]
		[(int)(player->pos_y + player->dir_y * MOVESPEED)] == '0')
		player->pos_y += player->dir_y * MOVESPEED;
	if (parsedata->map[(int)(player->pos_x + player->dir_x * MOVESPEED)]
		[(int)player->pos_y] == parsedata->dir_type)
		player->pos_x += player->dir_x * MOVESPEED;
	if (parsedata->map[(int)player->pos_x]
		[(int)(player->pos_y + player->dir_y * MOVESPEED)] ==
			parsedata->dir_type)
		player->pos_y += player->dir_y * MOVESPEED;
}

void	move_backward(t_player *player, t_parsedata *parsedata)
{
	if (parsedata->map[(int)(player->pos_x - player->dir_x * MOVESPEED)]
		[(int)player->pos_y] == '0')
		player->pos_x -= player->dir_x * MOVESPEED;
	if (parsedata->map[(int)player->pos_x]
		[(int)(player->pos_y - player->dir_y * MOVESPEED)] == '0')
		player->pos_y -= player->dir_y * MOVESPEED;
	if (parsedata->map[(int)(player->pos_x - player->dir_x * MOVESPEED)]
		[(int)player->pos_y] == parsedata->dir_type)
		player->pos_x -= player->dir_x * MOVESPEED;
	if (parsedata->map[(int)player->pos_x]
		[(int)(player->pos_y - player->dir_y * MOVESPEED)] ==
			parsedata->dir_type)
		player->pos_y -= player->dir_y * MOVESPEED;
}
