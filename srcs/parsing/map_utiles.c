/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:29:04 by akezanna          #+#    #+#             */
/*   Updated: 2021/03/22 14:21:27 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/includes.h"

int			is_number(char *number)
{
	int		i;
	char	*num;

	num = ft_strtrim(number, " ");
	i = 0;
	if (*number == '\0')
		return (0);
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	free(num);
	return (1);
}

void		get_player_pos(t_player *player, t_parsedata *parsedata)
{
	int	i;
	int	j;

	parsedata->dir_count = 0;
	i = 0;
	while (i < parsedata->map_rows)
	{
		j = 0;
		while (j < parsedata->map_cols)
		{
			if (is_dir(parsedata->map[i][j]))
			{
				player->pos_x = i + 0.5;
				player->pos_y = j + 0.5;
				parsedata->dir_count++;
				parsedata->dir_type = parsedata->map[i][j];
			}
			j++;
		}
		i++;
	}
}

void		count_sprite(t_parsedata *parsedata)
{
	int i;
	int j;

	i = 0;
	parsedata->sprite_num = 0;
	while (i < parsedata->map_rows)
	{
		j = 0;
		while (j < parsedata->map_cols)
		{
			if (parsedata->map[i][j] == '2')
				parsedata->sprite_num++;
			j++;
		}
		i++;
	}
}

int			check_dir(char **map, int rows, int cols)
{
	int i;
	int j;
	int count_dir;

	i = 0;
	count_dir = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (is_dir(map[i][j]))
				count_dir++;
			j++;
		}
		i++;
	}
	return (count_dir);
}

int			check_walls(char *map, int nb)
{
	int i;

	i = 0;
	while (i < nb)
	{
		if (check_chars(map[i]) && (!check_chars_valide(map[i - 1])))
			return (0);
		if (check_chars(map[i]) && (!check_chars_valide(map[i + 1])))
			return (0);
		i++;
	}
	return (1);
}
