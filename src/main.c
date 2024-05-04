/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:03:15 by megadiou          #+#    #+#             */
/*   Updated: 2024/05/04 03:09:39 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

// Is the main function of the whole program. 
// Everything is executed by this function.
int	main(int ac, char *av[])
{
	t_content	*content;

	check_arguments(ac, av);
	content = (t_content *)malloc(sizeof(t_content));
	if (!content)
		error(12);
	content->map_content = main_map_checks(av[1], content);
	if (!content->map_content)
		free(content);
	content = main_window_init(content);
	return (0);
}

// This function perform a series of checks and operations on the map.
t_map	*main_map_checks(char *path, t_content *content)
{
	content->map_content = (t_map *)malloc(sizeof(t_map));
	if (!content->map_content)
		error(12);
	content->map_content->map = map_init(path, content->map_content);
	if (content->map_content->map == NULL)
	{
		free(content->map_content);
		free(content);
		error_map(2);
	}
	content->map_content = map_checks(content->map_content);
	content->map_content = flood_fill(content->map_content);
	return (content->map_content);
}

t_content	*main_window_init(t_content *content)
{
	content = mlx_content_init(content);
	content->mlx_content->mlx = mlx_init(content->map_content->column * 64,
			content->map_content->row * 64, "so_long", false);
	if (!content->mlx_content->mlx)
		error_mlx();
	content->player_content = (t_player *)malloc(sizeof(t_player));
	if (!content->player_content)
		error(12);
	content->player_content->moves = 0;
	content = init_display(content);
	mlx_key_hook(content->mlx_content->mlx, (void (*))mlx_hook, content);
	mlx_loop(content->mlx_content->mlx);
	mlx_terminate(content->mlx_content->mlx);
	return (content);
}
