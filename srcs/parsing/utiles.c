/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:31:49 by akezanna          #+#    #+#             */
/*   Updated: 2021/03/22 11:11:19 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/includes.h"

int		wrong_char_in_map(char c)
{
	if (!(c == '0' || c == '1' || c == '2' || c == 'N' || c == 'S' || c == 'W'
		|| c == 'E' || c == ' '))
		return (1);
	return (0);
}

int		check_chars(char c)
{
	if (c == '0' || c == '2' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

int		check_chars_valide(char c)
{
	if (c == '0' || c == '2' || c == 'N' || c == 'S' || c == 'W' || c == 'E'
		|| c == '1')
		return (1);
	return (0);
}

int		is_dir(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int		check_chars_line(char *line)
{
	while (*line)
	{
		if (wrong_char_in_map(*line))
			return (0);
		line++;
	}
	return (1);
}
