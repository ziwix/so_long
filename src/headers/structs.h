/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 08:57:01 by megadiou          #+#    #+#             */
/*   Updated: 2024/04/11 14:50:32 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct sl_map t_map;

typedef struct sl_elements t_elements;

struct sl_map
{
	char	**map;
	int		size_map;
	char	**map_copy;
	int		row;
	int		column;
	t_elements	*elements;
};

struct sl_elements
{
	int	player;
	int	collectible;
	int	exit;
};

#endif