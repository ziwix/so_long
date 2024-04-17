/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:03:30 by megadiou          #+#    #+#             */
/*   Updated: 2023/11/20 16:27:40 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_hexa(unsigned int num)
{
	int	i;

	i = 0;
	while (num != 0)
	{
		num /= 16;
		i++;
	}
	return (i);
}

int	ft_len_u_ptr(unsigned long long num)
{
	int	i;

	i = 0;
	while (num != 0)
	{
		num /= 16;
		i++;
	}
	return (i);
}

int	ft_decimal_len(int num)
{
	int	i;

	i = 0;
	if (num <= 0)
		i++;
	while (num != 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

int	ft_unsigned_len(unsigned int num)
{
	int	i;

	i = 0;
	if (num == 0)
		i++;
	while (num != 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}
