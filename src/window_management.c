/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 02:29:03 by megadiou          #+#    #+#             */
/*   Updated: 2024/05/04 04:28:24 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/window_management.h"

t_content	*mlx_content_init(t_content *content)
{
	t_mlx_content	*mlx_content;
	int				i;
	int				j;

	i = 0;
	j = 0;
	mlx_content = (t_mlx_content *)malloc(sizeof(t_mlx_content));
	if (!mlx_content)
		error(12);
	content->mlx_content = mlx_content;
	while (content->map_content->map[i])
	{
		while (content->map_content->map[0][j])
			j++;
		i++;
	}
	content->map_content->column = j;
	content->map_content->row = i;
	return (content);
}

t_content	*init_display(t_content *content)
{
	int	pos_x;
	int	pos_y;

	pos_x = 0;
	while (content->map_content->map[pos_x])
	{
		pos_y = 0;
		while (content->map_content->map[pos_x][pos_y])
		{
			place_images(content, pos_x, pos_y);
			pos_y++;
		}
		pos_x++;
	}
	return (content);
}

void	place_images(t_content *content, int pos_x, int pos_y)
{
	if (content->map_content->map[pos_x][pos_y] == '1')
		content->mlx_content->wall = get_images(content, "img/walls.png", pos_y * 64, pos_x * 64);
	if (content->map_content->map[pos_x][pos_y] != '1' && content->map_content->map[pos_x][pos_y] != '\n')
		content->mlx_content->floor = get_images(content, "img/floor.png", pos_y * 64, pos_x * 64);
	if (content->map_content->map[pos_x][pos_y] == 'C')
		content->mlx_content->collectible = get_images(content, "img/collectible.png", pos_y * 64, pos_x * 64);
	if (content->map_content->map[pos_x][pos_y] == 'E')
		content->mlx_content->exit = get_images(content, "img/exit.png", pos_y * 64, pos_x * 64);
	if (content->map_content->map[pos_x][pos_y] == 'P')
	{
		content->mlx_content->player = get_images(content, "img/player.png", pos_y * 64, pos_x * 64);
		content->player_content->pos_x = pos_x;
		content->player_content->pos_y = pos_y;
	}
}

mlx_image_t	*get_images(t_content *content, char *path, int pos_x, int pos_y)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path);
	if (!texture)
		error(1);
	image = mlx_texture_to_image(content->mlx_content->mlx, texture);
	if (!image)
		error(1);
	if (mlx_image_to_window(content->mlx_content->mlx, image, pos_x, pos_y) < 0)
		error(1);
	mlx_delete_texture(texture);
	return (image);
}
