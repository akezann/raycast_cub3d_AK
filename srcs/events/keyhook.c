/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:14:53 by pmouhali          #+#    #+#             */
/*   Updated: 2021/04/27 15:20:43 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/includes.h"

int		key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_W)
		move_forward(&game->player, &game->parsedata);
	if (keycode == KEY_S)
		move_backward(&game->player, &game->parsedata);
	if (keycode == KEY_A)
		move_left(&game->player, &game->parsedata);
	if (keycode == KEY_D)
		move_right(&game->player, &game->parsedata);
	if (keycode == KEY_L_ARR)
		camera_left(&game->player);
	if (keycode == KEY_R_ARR)
		camera_right(&game->player);
	return (0);
}
