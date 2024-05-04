/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 08:57:01 by megadiou          #+#    #+#             */
/*   Updated: 2024/05/04 03:38:28 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_content		t_content;
typedef struct s_map			t_map;
typedef struct s_elements		t_elements;
typedef struct s_mlx_content	t_mlx_content;
typedef struct s_player			t_player;

struct s_content
{
	t_map			*map_content;
	t_mlx_content	*mlx_content;
	t_player		*player_content;
};

struct s_map
{
	char			**map;
	char			**map_copy;
	int				size_map;
	int				row;
	int				column;
	t_elements		*elements;
};

struct s_elements
{
	int	player;
	int	collectible;
	int	exit;
};

struct s_mlx_content
{
	mlx_t			*mlx;
	mlx_image_t		*player;
	mlx_image_t		*collectible;
	mlx_image_t		*exit;
	mlx_image_t		*wall;
	mlx_image_t		*floor;
};

struct s_player
{
	int	pos_x;
	int	pos_y;
	int	moves;
};


#endif