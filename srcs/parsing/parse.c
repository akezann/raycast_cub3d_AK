/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 09:21:53 by akezanna          #+#    #+#             */
/*   Updated: 2021/03/22 14:27:12 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/includes.h"

static	void	free_add(t_parsedata *parsedata, char *line, char *line_join)
{
	char	*tmp;

	if (ft_strlen(line) > parsedata->map_cols)
		parsedata->map_cols = ft_strlen(line);
	tmp = parsedata->tmp_map;
	line_join = ft_strjoin(line, "/");
	parsedata->tmp_map = ft_strjoin(parsedata->tmp_map, line_join);
	free(tmp);
	free(line_join);
}

static	int		parse_idents(t_parsedata *parsedata, char *line)
{
	if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2)
		|| !ft_strncmp(line, "EA", 2) || !ft_strncmp(line, "WE", 2))
		get_textures(parsedata, line);
	else if (!ft_strncmp(line, "S", 1))
		get_sprite(parsedata, line);
	else if (!ft_strncmp(line, "R", 1))
	{
		if (!get_resolution(parsedata, line))
			return (0);
	}
	else if (!ft_strncmp(line, "C", 1))
	{
		if (!ceil_floor_color(parsedata, line, 'C'))
			return (0);
	}
	else if (!ft_strncmp(line, "F", 1))
	{
		if (!ceil_floor_color(parsedata, line, 'F'))
			return (0);
	}
	return (1);
}

static	int		parse_map(t_parsedata *parsedata, char *line)
{
	char	*linejoin;

	linejoin = NULL;
	if (*line && !check_ident(line))
	{
		if (check_chars_line(line) && parsedata->ident_count == 8)
		{
			if (check_chars(line[0]) ||
				check_chars(line[ft_strlen(line) - 1]))
			{
				printf("might map open or something else ops\n");
				return (0);
			}
			free_add(parsedata, line, linejoin);
			parsedata->map_rows++;
		}
		else
		{
			printf("check idents if something missed or map not in the end\n");
			return (0);
		}
	}
	return (1);
}

static	int		check_ident_lines(t_parsedata *parsedata, int fd)
{
	int		r;
	char	*strimline;
	char	*line;

	r = 1;
	while (r == 1)
	{
		r = get_next_line(fd, &line);
		strimline = ft_strtrim(line, " ");
		if (check_ident(strimline))
		{
			if (!parse_idents(parsedata, strimline))
				return (0);
			parsedata->ident_count++;
		}
		else if (!parse_map(parsedata, line))
			return (0);
		free(line);
		free(strimline);
	}
	return (1);
}

int				save_map(t_parsedata *parsedata, int fd)
{
	char	**map;

	init_map_data(parsedata);
	if (check_ident_lines(parsedata, fd) <= 0)
		return (0);
	if (fd <= 0)
	{
		ft_putstr_fd("error or file not exxist\n", 1);
		return (0);
	}
	map = ft_split(parsedata->tmp_map, '/');
	set_map(map, parsedata);
	free_split(map, parsedata->map_rows);
	if (parsedata->map_rows < 3 || parsedata->map_cols < 3)
	{
		ft_putstr_fd("map is too small.\n", 1);
		return (0);
	}
	if (!map_layout(parsedata->map, parsedata->map_rows, parsedata->map_cols))
		return (0);
	count_sprite(parsedata);
	return (1);
}
