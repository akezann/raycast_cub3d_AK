/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:43:23 by akezanna          #+#    #+#             */
/*   Updated: 2019/11/09 22:55:46 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	lend;
	size_t	lens;
	size_t	j;
	size_t	i;

	lend = ft_strlen(dst);
	lens = ft_strlen(src);
	if (size <= lend)
		return (lens + size);
	else
		lens += lend;
	i = 0;
	j = lend;
	while (src[i] && i < size - lend - 1)
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (lens);
}
