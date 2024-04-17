/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:41:50 by megadiou          #+#    #+#             */
/*   Updated: 2024/04/11 16:02:04 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/free.h"

// Free all content of a map and the map it self.
void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}