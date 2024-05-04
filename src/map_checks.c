/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 07:57:33 by megadiou          #+#    #+#             */
/*   Updated: 2024/05/04 02:39:40 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/map_checks.h"

// Main function of the map checks.
t_map	*map_checks(t_map *map_content)
{
	map_content->elements = (t_elements *)malloc(sizeof(t_elements));
	check_walls_top_bottom(map_content);
	check_wall_sides(map_content);
	map_content->elements = check_elements(map_content, map_content->elements);
	return (map_content);
}

// Checking if the top and bottom walls of the map are valid.
void	check_walls_top_bottom(t_map *map_content)
{
	int	size;
	int	index;

	size = map_content->size_map;
	index = 0;
	while (map_content->map[0] && map_content->map[size - 1])
	{
		if (map_content->map[0][index] == '\n'
			&& map_content->map[size - 1][index] == '\0')
			break ;
		if (map_content->map[0][index] != '1'
			&& map_content->map[size - 1][index] != '1')
			error_map(3);
		index++;
	}
}

// Checking if the side walls of the map are valid.
void	check_wall_sides(t_map *map_content)
{
	int	size;
	int	index;
	int	index_size;

	index_size = 1;
	size = ft_strlen(map_content->map[0]) - 1;
	if (size == map_content->size_map)
		error_map(3);
	index = 0;
	while (index < map_content->size_map)
	{
		if (map_content->map[index][0] != '1'
			&& map_content->map[index][size - 1] != '1')
			error_map(3);
		index++;
	}
	if (size != (int)ft_strlen(map_content->map[map_content->size_map - 1]))
		error_map(3);
	while (index_size < map_content->size_map - 1)
	{
		if (size + 1 != (int)ft_strlen(map_content->map[index_size]))
			error_map(3);
		index_size++;
	}
}

// Check if there is all the elements required for the game to function.
t_elements	*check_elements(t_map *map_content, t_elements *elem)
{
	int			index;
	int			c_index;

	index = 1;
	c_index = 0;
	if (!elem)
		error(12);
	elem->player = 0;
	elem->collectible = 0;
	elem->exit = 0;
	elem = check_elements_count(map_content, elem, index, c_index);
	if (elem->player != 1 || elem->collectible < 1 || elem->exit != 1)
		error_map(3);
	return (elem);
}

// Count the elements to check it in the function above.
t_elements	*check_elements_count(t_map *map_content, t_elements *elem,
	int index, int c_index)
{
	while (index < map_content->size_map)
	{
		while (map_content->map[index][c_index] != 0)
		{
			if (map_content->map[index][c_index] == 'P')
				elem->player++;
			else if (map_content->map[index][c_index] == 'C')
				elem->collectible++;
			else if (map_content->map[index][c_index] == 'E')
				elem->exit++;
			else if (map_content->map[index][c_index] != 'P'
				&& map_content->map[index][c_index] != 'C'
				&& map_content->map[index][c_index] != 'E'
				&& map_content->map[index][c_index] != '0'
				&& map_content->map[index][c_index] != '1'
				&& map_content->map[index][c_index] != '\n')
				error_map(3);
			c_index++;
		}
		c_index = 0;
		index++;
	}
	return (elem);
}
