/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kezann <kezann@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 19:52:04 by akezanna          #+#    #+#             */
/*   Updated: 2021/01/05 22:21:38 by kezann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		ft_memdel(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

static	int		findline(char **rest, char **line)
{
	int		size;
	char	*perm;

	size = 0;
	while ((*rest)[size] != '\n' && (*rest)[size] != '\0')
		size++;
	if ((*rest)[size] == '\n')
	{
		*line = ft_substr(*rest, 0, size);
		perm = ft_strdup(ft_strchr(*rest, '\n') + 1);
		ft_memdel(rest);
		*rest = perm;
		return (1);
	}
	else
	{
		*line = ft_strdup(*rest);
		ft_memdel(rest);
	}
	return (0);
}

static	int		returnvalue(char **rest, char **line, int readres)
{
	if (readres < 0)
		return (-1);
	else if (readres == 0 && *rest == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	else
		return (findline(rest, line));
}

int				get_next_line(int fd, char **line)
{
	int				buff_s;
	int				res;
	char			*buff;
	static	char	*rest;
	char			*perm;

	buff_s = 100;
	if (fd < 0 || buff_s < 0 || !line ||
			!(buff = (char *)malloc(buff_s + 1)))
		return (-1);
	while ((res = read(fd, buff, buff_s)) > 0)
	{
		buff[res] = '\0';
		perm = ft_strjoin(rest, buff);
		if (rest)
		{
			free(rest);
			rest = NULL;
		}
		rest = perm;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (returnvalue(&rest, line, res));
}
