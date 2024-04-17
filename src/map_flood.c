/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_flood.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 06:12:14 by megadiou          #+#    #+#             */
/*   Updated: 2024/04/11 16:13:22 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/map_flood.h"

// Main function of the flood fill.
t_map	*flood_fill(t_map *content)
{
	content->row = 1;
	content->column = 1;
	duplicate_map(content);
	content->map_copy = flood_map(content->map_copy,
			content->row, content->column);
	check_flooded_map(content);
	return (content);
}

// This function duplicate the map to use it in the flood fill without affecting the main map.
void	duplicate_map(t_map *content)
{
	int	l_pos;

	l_pos = 0;
	content->map_copy = malloc(sizeof(char *) * (content->size_map + 1));
	if (!content->map_copy)
		error(12);
	content->map_copy[content->size_map] = 0;
	while (l_pos < content->size_map)
	{
		content->map_copy[l_pos] = ft_strdup(content->map[l_pos]);
		l_pos++;
	}
}

// This function is the core part of the flood fill, it's replacing all player, collectibles, exit, and free space;
char	**flood_map(char **map, int row, int column)
{
	if ((map[row][column] != '1' && map[row][column] != 'V'))
	{
		map[row][column] = 'V';
		flood_map(map, row + 1, column);
		flood_map(map, row - 1, column);
		flood_map(map, row, column + 1);
		flood_map(map, row, column - 1);
	}
	return (map);
}

// This function checks if there still is elements left. If there is the map is not playable.
void	check_flooded_map(t_map *content)
{
	int	row;
	int	i;

	row = 1;
	while (content->map_copy[row])
	{
		i = 1;
		while (content->map_copy[row][i])
		{
			if (content->map_copy[row][i] == 'C' || content->map_copy[row][i] == 'E'
				|| content->map_copy[row][i] == 'P')
				error_map(3);
			i++;
		}
		row++;
	}
}
