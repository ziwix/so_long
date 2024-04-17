/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:16:02 by megadiou          #+#    #+#             */
/*   Updated: 2023/11/08 14:50:38 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*s == c)
		s++;
	while (s[i])
	{
		if ((s[i] == c && s[i - 1] != c) || (s[i + 1] == 0 && s[i] != c))
			count++;
		i++;
	}
	return (count);
}

static size_t	ft_words_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

static void	ft_free_all(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static char	**ft_mal_strs(char const *s, char **strs, char c, int count)
{
	int		n;
	size_t	words_len;

	n = 0;
	words_len = 0;
	while (n < count)
	{
		while (*s == c)
			s++;
		words_len = ft_words_len(s, c);
		strs[n] = (char *)malloc(sizeof(char) * (words_len + 1));
		if (!strs[n])
		{
			ft_free_all(strs);
			return (NULL);
		}
		ft_strlcpy(strs[n], s, words_len + 1);
		s += words_len;
		n++;
	}
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**strs;

	if (!s || (s[0] == 0 && c == 0))
	{
		strs = (char **)malloc(sizeof(char *) * 1);
		if (!strs)
			return (NULL);
		strs[0] = NULL;
		return (strs);
	}
	if (c == 0)
		count = 1;
	else
		count = ft_count_words(s, c);
	strs = (char **)malloc(sizeof(char *) * (count + 1));
	if (!strs)
		return (NULL);
	strs = ft_mal_strs(s, strs, c, count);
	if (!strs)
		return (NULL);
	strs[count] = NULL;
	return (strs);
}
