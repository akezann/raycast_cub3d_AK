/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_ext_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 18:13:44 by akezanna          #+#    #+#             */
/*   Updated: 2021/03/21 16:57:03 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/includes.h"

int		check_file_extension(char *line, char *ext, int n)
{
	if (!ft_strncmp(ft_strrchr(line, '.') + 1, ext, n))
		return (1);
	return (0);
}
