/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:28:03 by akezanna          #+#    #+#             */
/*   Updated: 2021/03/21 15:52:51 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/includes.h"

void				get_sprite(t_parsedata *parsedata, char *line)
{
	char	**data;

	data = ft_split(line, ' ');
	if (check_file_extension(line, "xpm", 3))
	{
		if (!ft_strncmp(data[0], "S", 1) && *(data + 1) && !*(data + 2) &&
			open(*(data + 1), O_RDONLY) > 0)
			parsedata->s_text = *(data + 1);
		else
		{
			ft_putstr_fd("ERROR TEXTURE\n", 1);
			ft_putstr_fd("might file not exist,", 1);
			ft_putstr_fd(" or no space between id and path", 1);
			exit(0);
		}
	}
	else
	{
		ft_putstr_fd("ERROR TEXTURE\n", 1);
		ft_putstr_fd("Invalid extension of sprite", 1);
		exit(0);
	}
	free(data[0]);
	free(data);
}
