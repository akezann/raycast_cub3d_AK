/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:27:16 by akezanna          #+#    #+#             */
/*   Updated: 2019/11/09 23:22:26 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*last;

	last = (char *)s;
	len = ft_strlen(s) + 1;
	while (len-- > 0)
	{
		if (last[len] == (char)c)
			return (last + len);
	}
	return (NULL);
}
