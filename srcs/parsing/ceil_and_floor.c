/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceil_and_floor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 18:07:12 by akezanna          #+#    #+#             */
/*   Updated: 2021/04/27 15:17:48 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/includes.h"

static	int		count_char(char *str, int c)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == c)
			i++;
		str++;
	}
	return (i);
}

static	int		get_color_from_rgb(int r, int g, int b)
{
	return (r * 256 * 256) + (g * 256) + b;
}

static	int		set_color(char *r, char *g, char *b)
{
	if (ft_atoi(r) < 0 || ft_atoi(r) > 255)
		return (0);
	if (ft_atoi(g) < 0 || ft_atoi(g) > 255)
		return (0);
	if (ft_atoi(b) < 0 || ft_atoi(b) > 255)
		return (0);
	return (get_color_from_rgb(ft_atoi(r), ft_atoi(g), ft_atoi(b)));
}

static	int		parse_color(t_parsedata *parsedata, char *line, char c)
{
	char	**rgb;

	if ((line[0] == 'C' || line[0] == 'F') && (line[1] != ' '))
		return (0);
	if (count_char(line + 1, ',') != 2)
		return (0);
	rgb = ft_split(line + 1, ',');
	if (!rgb[0] || !rgb[1] || !rgb[2])
		return (0);
	if (is_number(rgb[0]) && is_number(rgb[1]) && is_number(rgb[2]))
		if (set_color(rgb[0], rgb[1], rgb[2]))
		{
			if (c == 'C')
				parsedata->ceil_color = set_color(rgb[0], rgb[1], rgb[2]);
			if (c == 'F')
				parsedata->floor_color = set_color(rgb[0], rgb[1], rgb[2]);
		}
		else
			return (0);
	else
		return (0);
	free_split(rgb, 3);
	return (1);
}

int				ceil_floor_color(t_parsedata *parsedata, char *line, char c)
{
	if (!parse_color(parsedata, line, c))
	{
		printf("COLOR ERROR!\n");
		printf("-- might no space between ident and rgb\n");
		printf("-- might is not a number\n");
		return (0);
	}
	return (1);
}
