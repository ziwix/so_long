/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwix <ziwix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:35:09 by megadiou          #+#    #+#             */
/*   Updated: 2024/04/09 09:39:43 by ziwix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_INIT_H
# define MAP_INIT_H

# include "so_long.h"

char	**map_init(char *path, t_map *content);
int		map_size(char *path);
char	**get_map(int fd, int l_count);

#endif