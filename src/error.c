/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:09:10 by megadou           #+#    #+#             */
/*   Updated: 2024/04/11 18:01:35 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/error.h"

// This function prints an error message corresponding to the given error code 
// and then terminates the program with a failure status. 
void	error(int err_code)
{
	int	errno;

	errno = err_code;
	perror("Error");
	exit(EXIT_FAILURE);
}

// Same as the function above but for the map.
void	error_map(int error_code)
{
	int	errno;

	errno = 5;
	if (error_code == 1)
		perror("Error: Invalid map");
	else if (error_code == 2)
		perror("Error: Error map can't load");
	else if (error_code == 3)
		perror("Error: This map is not compliant");
	else if (error_code == 4)
		perror("Error: Wrong map extension, Please use a map with the extension '.ber'");
	exit(EXIT_FAILURE);
}

void	mlx_error()
{
	perror(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}
