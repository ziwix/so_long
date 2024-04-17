/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:39:28 by megadiou          #+#    #+#             */
/*   Updated: 2023/11/06 15:18:41 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] && s2[i]))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if ((!big || !little) && len == 0)
		return (NULL);
	if (little[i] == 0)
		return ((char *)big);
	if (ft_strlen(big) >= ft_strlen(little))
	{
		while (big[i] && i < len && len - i >= ft_strlen(little))
		{
			while ((big[i] == little[0] && ft_strcmp((big + i), little) == 0))
				return ((char *)big + i);
			i++;
		}
	}
	return (NULL);
}
