/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:10:11 by megadiou          #+#    #+#             */
/*   Updated: 2024/04/30 04:21:41 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "so_long.h"

void	error(int err_code);
void	error_map(int err_code);
void	error_mlx(void);
void	check_arguments(int n_args, char **av);

#endif