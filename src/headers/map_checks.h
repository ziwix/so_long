/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 07:58:43 by megadiou          #+#    #+#             */
/*   Updated: 2024/04/30 04:17:21 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CHECKS_H
# define MAP_CHECKS_H

# include "so_long.h"

t_map		*map_checks(t_map *content);
void		check_walls_top_bottom(t_map *content);
void		check_wall_sides(t_map *content);
t_elements	*check_elements(t_map *content, t_elements *elem);
t_elements	*check_elements_count(t_map *content, t_elements *elem,
				int index, int c_index);

#endif