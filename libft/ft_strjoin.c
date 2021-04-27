/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:55:16 by akezanna          #+#    #+#             */
/*   Updated: 2021/03/18 11:53:54 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	unsigned	lens1;
	unsigned	lens2;
	char		*sj;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (!s1)
		return (ft_strdup((char *)s2));
	if (!s2)
		return (ft_strdup((char *)s1));
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	if (!(sj = (char *)malloc(lens1 + lens2 + 1)))
		return (0);
	ft_memcpy(sj, s1, lens1);
	ft_memcpy(sj + lens1, s2, lens2);
	sj[lens1 + lens2] = '\0';
	return (sj);
}
