/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:23:28 by akezanna          #+#    #+#             */
/*   Updated: 2021/03/21 17:23:08 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*sub;
	unsigned	i;
	unsigned	j;

	if ((size_t)ft_strlen(s) < start)
		return (ft_strdup(""));
	if (!s || !(sub = (char *)malloc(len + 1)))
		return (NULL);
	i = start;
	j = 0;
	while (s[i] && j < len)
	{
		sub[j] = s[i];
		i++;
		j++;
	}
	sub[j] = '\0';
	return (sub);
}
