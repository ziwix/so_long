/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:43:27 by megadiou          #+#    #+#             */
/*   Updated: 2024/05/04 04:26:02 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/key_management.h"

void	mlx_hook(mlx_key_data_t keydata, t_content *content)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(content->mlx_content->mlx);
	else if (mlx_is_key_down(content->mlx_content->mlx, MLX_KEY_W) && content->map_content->map[content->player_content->pos_x - 1][content->player_content->pos_y] != '1')
		content = move_up(content);
	else if (mlx_is_key_down(content->mlx_content->mlx, MLX_KEY_S) && content->map_content->map[content->player_content->pos_x + 1][content->player_content->pos_y] != '1')
		content = move_down(content);
	else if (mlx_is_key_down(content->mlx_content->mlx, MLX_KEY_A) && content->map_content->map[content->player_content->pos_x][content->player_content->pos_y - 1] != '1')
		content = move_left(content);
	else if (mlx_is_key_down(content->mlx_content->mlx, MLX_KEY_D) && content->map_content->map[content->player_content->pos_x][content->player_content->pos_y + 1] != '1')
		content = move_right(content);
	else if (content->map_content->map[content->player_content->pos_x][content->player_content->pos_y] == 'E' && content->map_content->elements->collectible == 0)
	{
		ft_printf("\n\tWell done you've completed the game!!\n");
		mlx_close_window(content->mlx_content->mlx);
	}
}

t_content	*move_up(t_content *content)
{
	if (content->map_content->map[content->player_content->pos_x][content->player_content->pos_y] == 'C')
	{
		content->map_content->elements->collectible--;
		get_images(content, "img/floor.png", content->player_content->pos_x * 64, content->player_content->pos_y * 64);
		content->mlx_content->player = get_images(content, "img/player.png", content->player_content->pos_x * 64, content->player_content->pos_y * 64);
		content->map_content->map[content->player_content->pos_x][content->player_content->pos_y] = '0';
	}
	if (content->map_content->map[content->player_content->pos_x][content->player_content->pos_y] == 'E' && content->map_content->elements->collectible == 0)
	{
		ft_printf("\n\tWell done you've completed the game!!\n");
		mlx_close_window(content->mlx_content->mlx);
	}
	content->player_content->moves++;
	ft_printf("You moved %d times.\n", content->player_content->moves);
	content->player_content->pos_x -= 1;
	content->mlx_content->player->instances[0].y -= 64;
	return (content);
}

t_content	*move_down(t_content *content)
{
	if (content->map_content->map[content->player_content->pos_x][content->player_content->pos_y] == 'C')
	{
		content->map_content->elements->collectible--;
		get_images(content, "img/floor.png", content->player_content->pos_x * 64, content->player_content->pos_y * 64);
		content->mlx_content->player = get_images(content, "img/player.png", content->player_content->pos_x * 64, content->player_content->pos_y * 64);
		content->map_content->map[content->player_content->pos_x][content->player_content->pos_y] = '0';
	}
	if (content->map_content->map[content->player_content->pos_x][content->player_content->pos_y] == 'E' && content->map_content->elements->collectible == 0)
	{
		ft_printf("\n\tWell done you've completed the game!!\n");
		mlx_close_window(content->mlx_content->mlx);
	}
	content->player_content->moves++;
	ft_printf("You moved %d times.\n", content->player_content->moves);
	content->player_content->pos_x += 1;
	content->mlx_content->player->instances[0].y += 64;
	return (content);
}

t_content	*move_left(t_content *content)
{
	if (content->map_content->map[content->player_content->pos_x][content->player_content->pos_y] == 'C')
	{
		content->map_content->elements->collectible--;
		get_images(content, "img/floor.png", content->player_content->pos_x * 64, content->player_content->pos_y * 64);
		content->mlx_content->player = get_images(content, "img/player.png", content->player_content->pos_x * 64, content->player_content->pos_y * 64);
		content->map_content->map[content->player_content->pos_x][content->player_content->pos_y] = '0';
	}
	if (content->map_content->map[content->player_content->pos_x][content->player_content->pos_y] == 'E' && content->map_content->elements->collectible == 0)
	{
		ft_printf("\n\tWell done you've completed the game!!\n");
		mlx_close_window(content->mlx_content->mlx);
	}
	content->player_content->moves++;
	ft_printf("You moved %d times.\n", content->player_content->moves);
	content->player_content->pos_y -= 1;
	content->mlx_content->player->instances[0].x -= 64;
	return (content);
}

t_content	*move_right(t_content *content)
{
	if (content->map_content->map[content->player_content->pos_x][content->player_content->pos_y] == 'C')
	{
		content->map_content->elements->collectible--;
		get_images(content, "img/floor.png", content->player_content->pos_x * 64, content->player_content->pos_y * 64);
		content->mlx_content->player = get_images(content, "img/player.png", content->player_content->pos_x * 64, content->player_content->pos_y * 64);
		content->map_content->map[content->player_content->pos_x][content->player_content->pos_y] = '0';
	}
	if (content->map_content->map[content->player_content->pos_x][content->player_content->pos_y] == 'E' && content->map_content->elements->collectible == 0)
	{
		ft_printf("\n\tWell done you've completed the game!!\n");
		mlx_close_window(content->mlx_content->mlx);
	}
	content->player_content->moves++;
	ft_printf("You moved %d times.\n", content->player_content->moves);
	content->player_content->pos_y += 1;
	content->mlx_content->player->instances[0].x += 64;
	return (content);
}
