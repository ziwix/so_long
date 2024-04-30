/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:03:15 by megadiou          #+#    #+#             */
/*   Updated: 2024/04/27 19:55:34 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

// Is the main function of the whole program. 
// Everything is executed by this function.
int	main(int ac, char *av[])
{
	t_map	*content;

	if (ac != 2)
		error(22);
	if (ft_strstr(av[1], ".ber") == NULL)
		error_map(4);
	content = (t_map *)malloc(sizeof(t_map));
	if (!content)
		error(12);
	content = main_map_checks(av[1], content);
	free_map(content->map);
	free_map(content->map_copy);
	free(content->elements);
	free(content);
	return (0);
}

// This function perform a series of checks and operations on the map.
t_map	*main_map_checks(char *path, t_map *content)
{
	content->map = map_init(path, content);
	if (content->map == NULL)
		error_map(2);
	content = map_checks(content);
	content = flood_fill(content);
	return (content);
}
