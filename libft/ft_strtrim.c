/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:39:56 by megadiou          #+#    #+#             */
/*   Updated: 2023/11/06 12:30:20 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lenstr(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_check_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_check_trim(char const *s1, char const *set,
									int len_s1, int startEnd)
{
	int	i;

	i = 0;
	if (startEnd == 0)
	{
		while (ft_check_set(s1[i], set) == 1)
			i++;
		return (i);
	}
	if (startEnd == 1)
	{
		i = (len_s1 - 1);
		while (ft_check_set(s1[i], set) == 1)
			i--;
		return ((len_s1 - i - 1));
	}
	return (0);
}

static int	ft_trim(char *dest, char const *s1, int trim)
{
	int		i;
	size_t	len_s1;

	i = 0;
	len_s1 = ft_lenstr(s1);
	if (trim == 0)
	{
		while (s1[i])
		{
			dest[i] = s1[i];
			i++;
		}
	}
	while (i < ((int)len_s1 - trim))
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = 0;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int			start;
	int			end;
	int			stock;
	int			len_s1;
	char		*dest;

	if (!s1 || !set)
		return (NULL);
	len_s1 = ft_lenstr(s1);
	start = ft_check_trim(s1, set, len_s1, 0);
	end = ft_check_trim(s1, set, len_s1, 1);
	stock = start + end;
	if (start == len_s1 || end == len_s1)
	{
		dest = (char *)malloc(sizeof(char));
		if (!dest)
			return (NULL);
		dest[0] = 0;
		return (dest);
	}
	dest = (char *)malloc(sizeof(char) * (len_s1 - stock) + 1);
	if (!dest)
		return (NULL);
	ft_trim(dest, s1 + start, end);
	return (dest);
}
