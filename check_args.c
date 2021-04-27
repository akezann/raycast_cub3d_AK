/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 18:13:15 by akezanna          #+#    #+#             */
/*   Updated: 2021/03/22 10:52:02 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/includes.h"

void		check_args(t_game *game, int n, char **ar, int fd)
{
	game->save = 0;
	if (n < 2 || n > 3)
	{
		ft_putstr_fd("Invalid number of args, must 2 or 3 args", 1);
		exit(0);
	}
	if (n == 2 && (!check_file_extension(ar[1], "cub", 3) || fd < 0))
	{
		ft_putstr_fd("might file not exist, or invalid extenstion", 1);
		exit(0);
	}
	if (n == 3 && ft_strncmp(ar[2], "--save", 7))
	{
		ft_putstr_fd("something wrong on arg 3", 1);
		exit(0);
	}
	if (n == 3 && !ft_strncmp(ar[2], "--save", 6) && ft_strlen(ar[2]) == 6)
		game->save = 1;
}
