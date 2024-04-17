/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:41:47 by megadiou          #+#    #+#             */
/*   Updated: 2023/11/08 15:38:00 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (*((unsigned char *)s + i))
		i++;
	while (i >= 0)
	{
		if (*((unsigned char *)s + i) == (unsigned char)c)
			return (((char *)s + i));
		i--;
	}
	return (0);
}
