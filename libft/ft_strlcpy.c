/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:53:35 by akezanna          #+#    #+#             */
/*   Updated: 2019/11/09 22:55:14 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len_src;
	size_t	len;

	len_src = ft_strlen(src);
	if (size)
	{
		len = (len_src >= size) ? size - 1 : len_src;
		ft_memcpy(dst, src, len);
		dst[len] = '\0';
	}
	return (len_src);
}
