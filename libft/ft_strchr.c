/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:09:50 by megadiou          #+#    #+#             */
/*   Updated: 2023/11/08 15:36:51 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (*((unsigned char *)s + i))
	{
		if (*((unsigned char *)s + i) == (unsigned char)c)
			return (((char *)s + i));
		i++;
	}
	if ((unsigned char)c == 0)
		return (((char *)s + i));
	return (0);
}
