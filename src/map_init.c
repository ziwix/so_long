/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:33:22 by megadiou          #+#    #+#             */
/*   Updated: 2024/04/11 15:58:02 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/map_init.h"

// Initialize the process to get the map.
char	**map_init(char *path, t_map *content)
{
	int		fd;
	char	**map;

	content->size_map = map_size(path);
	if (content->size_map < 3)
		error_map(1);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error(2);
	map = get_map(fd, content->size_map);
	close(fd);
	return (map);
}

// Calculate the length of the map.
int	map_size(char *path)
{
	int		fd;
	int		count_lines;
	char	*line;

	count_lines = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error(2);
	line = get_next_line(fd);
	while (line)
	{
		count_lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count_lines);
}

// Read the map from the file and stock it in an array of strings.
char	**get_map(int fd, int l_count)
{
	char	**map;
	int		l_pos;

	l_pos = 0;
	map = malloc(sizeof(char *) * (l_count + 1));
	if (!map)
		error(12);
	map[l_pos] = get_next_line(fd);
	l_pos++;
	while (l_pos < l_count)
	{
		map[l_pos] = get_next_line(fd);
		l_pos++;
	}
	ft_printf("\n");
	map[l_pos] = 0;
	return (map);
}
