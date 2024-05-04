/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:09:10 by megadou           #+#    #+#             */
/*   Updated: 2024/04/30 04:23:18 by megadiou         ###   ########.fr       */
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
	{
		perror("Error: Wrong map extension");
		perror("Please use a map with the extension '.ber'");
	}
	else if (error_code == 5)
		perror("Error: ");
	exit(EXIT_FAILURE);
}

void	error_mlx(void)
{
	perror(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	check_arguments(int n_args, char **av)
{
	int		i;
	char	*path;

	i = 0;
	if (n_args != 2)
		error(22);
	path = av[1];
	while (path[i])
		i++;
	if ((path[i - 4] != '.') || (path[i - 3] != 'b')
		|| (path[i - 2] != 'e') || (path[i - 1] != 'r'))
		error_map(4);
}
