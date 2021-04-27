/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:21:47 by akezanna          #+#    #+#             */
/*   Updated: 2019/11/09 19:23:55 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst1;
	unsigned char	*src1;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	src1 = (unsigned char *)src;
	dst1 = (unsigned char *)dst;
	i = len - 1;
	if (src1 < dst1)
		while (len-- > 0)
		{
			dst1[i] = src1[i];
			i--;
		}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
