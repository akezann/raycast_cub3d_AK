/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_layout.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 18:11:51 by akezanna          #+#    #+#             */
/*   Updated: 2021/03/22 14:11:01 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/includes.h"

static	int		check_map(char **map, int nb_rows, int nb_cols)
{
	int i;
	int j;

	i = 0;
	while (i < nb_rows)
	{
		j = 0;
		while (j < nb_cols)
		{
			if (check_chars(map[i][j]) && map[i][j - 1] == ' ')
				return (0);
			if (check_chars(map[i][j]) && map[i][j + 1] == ' ')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static	int		transpose_map(char **map, int nb_rows, int nb_cols)
{
	int i;
	int j;

	i = 0;
	while (i < nb_rows)
	{
		j = 0;
		while (j < nb_cols)
		{
			if (check_chars(map[0][j]) || check_chars(map[nb_rows - 1][j]))
				return (0);
			if (check_chars(map[i][j]) && map[i - 1][j] == ' ')
				return (0);
			if (check_chars(map[i][j]) && map[i + 1][j] == ' ')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int				map_layout(char **map, int nb_rows, int nb_cols)
{
	if (!check_map(map, nb_rows, nb_cols))
	{
		printf("check you map walls, might are open or something else.");
		return (0);
	}
	if (!transpose_map(map, nb_rows, nb_cols))
	{
		printf("check you map walls, might are open or something else.");
		return (0);
	}
	if (check_dir(map, nb_rows, nb_cols) == 0)
	{
		printf("ERROR DIRECTION\n, no direction on the map.");
		return (0);
	}
	if (check_dir(map, nb_rows, nb_cols) > 1)
	{
		printf("ERROR DIRECTION\n, must be just one on the map.");
		return (0);
	}
	return (1);
}
