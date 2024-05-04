/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 02:29:38 by megadiou          #+#    #+#             */
/*   Updated: 2024/05/04 03:24:30 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_MANAGEMENT_H
#define	WINDOW_MANAGEMENT_H

#include "so_long.h"

t_content	*mlx_content_init(t_content *content);
t_content	*init_display(t_content *content);
void		place_images(t_content *content, int pos_x, int pos_y);
mlx_image_t	*get_images(t_content *content, char *path, int pos_x, int pos_y);

#endif