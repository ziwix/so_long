/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 07:23:36 by megadiou          #+#    #+#             */
/*   Updated: 2024/04/11 14:51:02 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../../libft/libft.h"
# include "../../ft_printf/src/ft_printf.h"
# include "../../MLX42/include/MLX42/MLX42.h"
# include "../../get_next_line/get_next_line.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>

# include "error.h"
# include "structs.h"
# include "map_init.h"
# include "map_checks.h"
# include "map_flood.h"
# include "free.h"

t_map	*main_map_checks(char *path, t_map *content);

#endif