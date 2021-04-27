/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:01:02 by akezanna          #+#    #+#             */
/*   Updated: 2019/11/09 22:59:24 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src1;
	unsigned char	*ptr;

	dest = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	ptr = NULL;
	while (n-- && ptr == NULL)
	{
		*dest = *src1;
		if (*src1 == (unsigned char)c)
			ptr = dest + 1;
		src1++;
		dest++;
	}
	return (ptr);
}
