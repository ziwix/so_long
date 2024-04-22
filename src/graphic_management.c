/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:43:27 by megadiou          #+#    #+#             */
/*   Updated: 2024/04/22 15:52:58 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/graphic_management.h"


void	window_init(t_map *content)
{
	mlx_t	*mlx;

	mlx = mlx_init(500, 500, "so_long", false);
	if (!mlx)
		error_mlx();
	mlx_loop(mlx);
	mlx_terminate(mlx);
}