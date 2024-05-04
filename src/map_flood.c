/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_flood.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 06:12:14 by megadiou          #+#    #+#             */
/*   Updated: 2024/05/04 02:39:45 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/map_flood.h"

// Main function of the flood fill.
t_map	*flood_fill(t_map *map_content)
{
	map_content->row = 1;
	map_content->column = 1;
	duplicate_map(map_content);
	map_content->map_copy = flood_map(map_content->map_copy,
			map_content->row, map_content->column);
	check_flooded_map(map_content);
	free_map(map_content->map_copy);
	return (map_content);
}

// This function duplicate the map to use it in the flood fill 
// without affecting the main map.
void	duplicate_map(t_map *map_content)
{
	int	l_pos;

	l_pos = 0;
	map_content->map_copy = malloc(sizeof(char *) * (map_content->size_map + 1));
	if (!map_content->map_copy)
		error(12);
	map_content->map_copy[map_content->size_map] = 0;
	while (l_pos < map_content->size_map)
	{
		map_content->map_copy[l_pos] = ft_strdup(map_content->map[l_pos]);
		l_pos++;
	}
}

// This function is the core part of the flood fill
// it's replacing all player, collectibles, exit, and free space;
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

// This function checks if there still is elements left. 
// If there is the map is not playable.
void	check_flooded_map(t_map *map_content)
{
	int	row;
	int	i;

	row = 1;
	while (map_content->map_copy[row])
	{
		i = 1;
		while (map_content->map_copy[row][i])
		{
			if (map_content->map_copy[row][i] == 'C'
				|| map_content->map_copy[row][i] == 'E'
				|| map_content->map_copy[row][i] == 'P')
				error_map(3);
			i++;
		}
		row++;
	}
}
