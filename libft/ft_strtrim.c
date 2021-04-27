/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 12:35:18 by akezanna          #+#    #+#             */
/*   Updated: 2021/03/18 11:53:32 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_check(char s1, char const *set)
{
	while (*set)
	{
		if (*set == s1)
			return (1);
		set++;
	}
	return (0);
}

static int	get_start(char const *s1, char const *set)
{
	int		i;

	i = 0;
	while (s1[i])
	{
		if (ft_check(s1[i], set) == 1)
			i++;
		else
			break ;
	}
	return (i);
}

static int	get_end(char const *s1, char const *set)
{
	int		j;

	j = ft_strlen(s1) - 1;
	while (j >= 0 && s1[j])
	{
		if (ft_check(s1[j], set) == 1)
			j--;
		else
			break ;
	}
	return (j);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*st;
	int		start;
	int		end;
	int		size;

	if (s1 == 0)
		return (0);
	if (set == 0)
		return (ft_strdup(s1));
	start = get_start(s1, set);
	end = get_end(s1, set);
	size = end - start + 1;
	if (end < start)
		return (ft_calloc(1, 1));
	st = (char *)malloc(size + 1);
	if (st == NULL)
		return (0);
	st = ft_substr(s1, start, size);
	return (st);
}
