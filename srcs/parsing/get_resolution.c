/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 18:16:05 by akezanna          #+#    #+#             */
/*   Updated: 2021/03/21 17:07:22 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/includes.h"

static	void	check_dimensions(int *width, int *height)
{
	if (*width < 480)
		*width = 480;
	if (*height < 320)
		*height = 320;
	if (*width >= 2560)
		*width = 2560;
	if (*height >= 1440)
		*height = 1440;
}

static	int		parse_resolution(t_parsedata *parsedata, char *line)
{
	char	**data;

	data = ft_split(line, ' ');
	if (!data[0][1] && data[1] && data[2] && !data[3] &&
			(is_number(data[1]) && is_number(data[2])))
	{
		parsedata->win_width = ft_atoi(data[1]);
		parsedata->win_height = ft_atoi(data[2]);
	}
	else
	{
		ft_putstr_fd("ERROR RESOLUTION\n", 1);
		ft_putstr_fd("check your resolution format, \n", 1);
		ft_putstr_fd("might not digit or something else.\n", 1);
		return (0);
	}
	free_split(data, 3);
	return (1);
}

int				get_resolution(t_parsedata *parsedata, char *line)
{
	if (!parse_resolution(parsedata, line))
		return (0);
	else
		check_dimensions(&parsedata->win_width, &parsedata->win_height);
	return (1);
}
