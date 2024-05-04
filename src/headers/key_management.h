/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_management.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:44:28 by megadiou          #+#    #+#             */
/*   Updated: 2024/05/04 04:19:06 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_MANAGEMENT_H
# define KEY_MANAGEMENT_H

# include "so_long.h"

t_content	*mlx_content_init(t_content *content);
void		mlx_hook(mlx_key_data_t keydata, t_content *content);
t_content	*move_up(t_content *content);
t_content	*move_down(t_content *content);
t_content	*move_left(t_content *content);
t_content	*move_right(t_content *content);

#endif