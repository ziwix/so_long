/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 07:57:33 by megadiou          #+#    #+#             */
/*   Updated: 2024/04/11 16:05:02 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/map_checks.h"

// Main function of the map checks.
t_map	*map_checks(t_map *content)
{
	t_elements *elem;

	elem = (t_elements *)malloc(sizeof(t_elements));
	check_walls_top_bottom(content);
	check_wall_sides(content);
	elem = check_elements(content, elem);
	content->elements = elem;
	return (content);
}

// Checking if the top and bottom walls of the map are valid.
void	check_walls_top_bottom(t_map *content)
{
	int	size;
	int	index;

	size = content->size_map;
	index = 0;
	while (content->map[0] && content->map[size - 1])
	{
		if (content->map[0][index] == '\n'
			&& content->map[size - 1][index] == '\0')
			break ;
		if (content->map[0][index] != '1'
			&& content->map[size - 1][index] != '1')
			error_map(3);
		index++;
	}
}

// Checking if the side walls of the map are valid.
void	check_wall_sides(t_map *content)
{
	int	size;
	int	index;
	int	index_size;

	index_size = 1;
	size = ft_strlen(content->map[0]) - 1;
	if (size == content->size_map)
		error_map(3);
	index = 0;
	while (index < content->size_map)
	{
		if (content->map[index][0] != '1'
			&& content->map[index][size - 1] != '1')
			error_map(3);
		index++;
	}
	if (size != (int)ft_strlen(content->map[content->size_map - 1]))
		error_map(3);
	while (index_size < content->size_map - 1)
	{
		if (size + 1 != (int)ft_strlen(content->map[index_size]))
			error_map(3);
		index_size++;
	}
}

// Check if there is all the elements required for the game to function.
t_elements	*check_elements(t_map *content, t_elements *elem)
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
	elem = check_elements_count(content, elem, index, c_index);
	if (elem->player != 1 || elem->collectible < 1 || elem->exit != 1)
		error_map(3);
	return (elem);
}

// Count the elements to check it in the function above.
t_elements	*check_elements_count(t_map *content, t_elements *elem,
	int index, int c_index)
{
	while (index < content->size_map)
	{
		while (content->map[index][c_index] != 0)
		{
			if (content->map[index][c_index] == 'P')
				elem->player++;
			else if (content->map[index][c_index] == 'C')
				elem->collectible++;
			else if (content->map[index][c_index] == 'E')
				elem->exit++;
			else if (content->map[index][c_index] != 'P'
				&& content->map[index][c_index] != 'C'
				&& content->map[index][c_index] != 'E'
				&& content->map[index][c_index] != '0'
				&& content->map[index][c_index] != '1'
				&& content->map[index][c_index] != '\n')
				error_map(3);
			c_index++;
		}
		c_index = 0;
		index++;
	}
	return (elem);
}
