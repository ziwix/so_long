/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwix <ziwix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 09:54:52 by megadiou          #+#    #+#             */
/*   Updated: 2024/04/09 07:24:47 by ziwix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcat(char *s1, char *s2, char *dest)
{
	size_t	i;
	size_t	lens1;

	i = 0;
	if (!s1)
		lens1 = 0;
	else
	{
		lens1 = ft_strlen(s1);
		while (s1[i])
		{
			dest[i] = s1[i];
			i++;
		}
	}
	i = 0;
	while (s2[i])
	{
		dest[lens1 + i] = s2[i];
		i++;
	}
	dest[lens1 + i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	new_s_len;
	char	*dst;

	if (!s2)
		return (NULL);
	if (!s1)
		new_s_len = ft_strlen(s2) + 1;
	else
		new_s_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	dst = (char *)malloc(sizeof(char) * new_s_len);
	if (!dst)
		return (NULL);
	dst = ft_strcat((char *)s1, (char *)s2, dst);
	free((char *)s1);
	return (dst);
}
