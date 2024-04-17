/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:28:06 by megadiou          #+#    #+#             */
/*   Updated: 2023/08/24 15:31:23 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (*to_find == 0)
		return (str);
	while (str[i])
	{
		while (str[i] == to_find[j])
		{
			if (str[i] != to_find[j])
				j = 0;
			else
			{
				i++;
				j++;
				if (to_find[j] == '\0')
					return (&str[i - j]);
			}
		}
		i++;
	}
	return (NULL);
}
