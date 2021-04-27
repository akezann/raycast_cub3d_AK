/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utiles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:34:34 by akezanna          #+#    #+#             */
/*   Updated: 2021/03/22 14:27:32 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/includes.h"

void	set_map(char **map, t_parsedata *data)
{
	int	i;
	int	j;
	int len;

	i = 0;
	len = 0;
	data->map = (char **)malloc(sizeof(char *) * data->map_rows);
	while (i < data->map_rows)
	{
		data->map[i] = (char *)malloc(sizeof(char) * data->map_cols);
		j = 0;
		len = ft_strlen(map[i]);
		while (j < len || len < data->map_cols)
		{
			data->map[i][j] = map[i][j];
			if (j == len)
				data->map[i][len++] = ' ';
			j++;
		}
		i++;
	}
}

void	free_split(char **s, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(s[i++]);
	free(s);
}

void	init_map_data(t_parsedata *parsedata)
{
	parsedata->s_text = NULL;
	parsedata->so_text = NULL;
	parsedata->ea_text = NULL;
	parsedata->we_text = NULL;
	parsedata->no_text = NULL;
	parsedata->tmp_map = NULL;
	parsedata->ceil_color = 0;
	parsedata->floor_color = 0;
	parsedata->map_cols = 0;
	parsedata->map_rows = 0;
	parsedata->win_height = 0;
	parsedata->win_width = 0;
	parsedata->ident_count = 0;
}

int		check_ident(char *line)
{
	if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2)
		|| !ft_strncmp(line, "EA", 2) || !ft_strncmp(line, "WE", 2) ||
			!ft_strncmp(line, "S", 1) ||
			!ft_strncmp(line, "C", 1) || !ft_strncmp(line, "F", 1) ||
			!ft_strncmp(line, "R", 1))
		return (1);
	return (0);
}
