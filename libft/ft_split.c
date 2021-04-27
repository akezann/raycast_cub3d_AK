/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 20:18:32 by akezanna          #+#    #+#             */
/*   Updated: 2019/11/07 14:18:38 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		c_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		while (s[i] && s[i] != c)
			i++;
		count++;
	}
	return (count);
}

static int		size_words(char const *s, char c)
{
	int count;

	count = 0;
	while (*s != c && *s)
	{
		count++;
		s++;
	}
	return (count);
}

static	char	**m_free(char **p, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (p[i] != NULL)
		{
			free(p[i]);
			i++;
		}
	}
	free(p);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**tab;
	int		j;
	int		k;

	j = 0;
	if (s == 0 ||
			!(tab = (char **)malloc(sizeof(char *) * (c_words(s, c) + 1))))
		return (0);
	while (*s)
	{
		while ((*s == c) && *s)
			s++;
		if (*s)
		{
			k = 0;
			if (!(tab[j] = (char *)malloc(sizeof(char) *
							size_words(s, c) + 1)))
				return (m_free(&tab[j], size_words(s, c) + 1));
			while (*s && *s != c)
				tab[j][k++] = *(s++);
			tab[j++][k] = '\0';
		}
	}
	tab[j] = NULL;
	return (tab);
}
