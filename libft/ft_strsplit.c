/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 21:14:31 by dzboncak          #+#    #+#             */
/*   Updated: 2018/11/30 19:05:08 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static size_t		ft_count_words(char const *s, char c)
{
	size_t			i;
	size_t			count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			count += 1;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (count);
}

static char const	*ft_findnext(char const *s, char c)
{
	if (*s == c && *s != '\0')
	{
		while (*s == c)
			s++;
	}
	else
	{
		while (*s != c && *s != '\0')
			s++;
		while (*s == c && *s != '\0')
			s++;
	}
	return (s);
}

static	size_t		ft_wrdlen(char const *s, char c)
{
	size_t			len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	return (len);
}

static char			*ft_getword(char const *s, char c)
{
	char			*word;
	size_t			len;
	size_t			i;

	len = ft_wrdlen(s, c);
	word = (char*)malloc(sizeof(char) * (len + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char				**ft_strsplit(char const *s, char c)
{
	char			**res;
	size_t			words;
	size_t			i;

	if (s == NULL || c == '\0')
		return (NULL);
	words = ft_count_words(s, c);
	i = 0;
	res = (char**)malloc(sizeof(char*) * (words + 1));
	if (res == NULL)
		return (NULL);
	if (words == 0)
	{
		res[i] = 0;
		return (res);
	}
	if (i == 0 && s[0] != c)
		res[i++] = ft_getword(s, c);
	while (i < words)
	{
		s = ft_findnext(s, c);
		res[i++] = ft_getword(s, c);
	}
	res[i] = 0;
	return (res);
}
