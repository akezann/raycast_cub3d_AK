/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 19:08:22 by akezanna          #+#    #+#             */
/*   Updated: 2019/11/09 23:38:14 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	char	*p;

	str = (char *)malloc(ft_strlen(src) + 1);
	if (str == NULL)
		return (NULL);
	p = str;
	while (*src)
		*(p++) = *(src++);
	*p = '\0';
	return (str);
}
