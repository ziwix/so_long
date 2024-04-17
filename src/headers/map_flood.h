/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_flood.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 06:30:36 by megadiou          #+#    #+#             */
/*   Updated: 2024/04/11 15:44:48 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_FLOOD_H
# define MAP_FLOOD_H

# include "so_long.h"

t_map	*flood_fill(t_map *content);
void	duplicate_map(t_map *content);
char	**flood_map(char **map, int row, int column);
void	check_flooded_map(t_map *content);

#endif