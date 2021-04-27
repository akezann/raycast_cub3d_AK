/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:14:39 by akezanna          #+#    #+#             */
/*   Updated: 2021/03/21 16:57:54 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/includes.h"

static	int		affect_texture(t_parsedata *parsedata, char **data)
{
	if (!ft_strncmp(data[0], "NO", 2) && *(data + 1) && !*(data + 2))
		parsedata->no_text = *(data + 1);
	else if (!ft_strncmp(data[0], "SO", 2) && *(data + 1) && !*(data + 2))
		parsedata->so_text = *(data + 1);
	else if (!ft_strncmp(data[0], "WE", 2) && *(data + 1) && !*(data + 2))
		parsedata->we_text = *(data + 1);
	else if (!ft_strncmp(data[0], "EA", 2) && *(data + 1) && !*(data + 2))
		parsedata->ea_text = *(data + 1);
	else
		return (0);
	return (1);
}

void			get_textures(t_parsedata *parsedata, char *line)
{
	char	**data;

	data = ft_split(line, ' ');
	if (check_file_extension(line, "xpm", 3) &&
		(open(*(data + 1), O_RDONLY) <= 0 ||
			!affect_texture(parsedata, data)
			|| !(*data && *(data + 1) && !*(data + 2))))
	{
		ft_putstr_fd("ERROR TEXTURE\n", 1);
		ft_putstr_fd("check extension, or might file not exist,", 1);
		ft_putstr_fd("or no space between id and path.,\n", 1);
		exit(0);
	}
	free(data[0]);
	free(data);
}
