/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:10:57 by megadiou          #+#    #+#             */
/*   Updated: 2023/12/14 12:19:26 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsigned(unsigned int n, int output)
{
	char	c;

	c = '0';
	if (n > 9)
	{
		ft_putnbr_unsigned(n / 10, output);
		ft_putnbr_unsigned(n % 10, output);
	}
	else
	{
		c = n + '0';
		write(output, &c, 1);
	}
}

void	ft_putnbr_base16(unsigned int num, int upLow, int output)
{
	int	tmp;

	tmp = 0;
	if (num)
	{
		tmp = num % 16;
		ft_putnbr_base16(num / 16, upLow, output);
		if (tmp > 9)
			ft_putchar_fd(tmp + upLow, output);
		else
			ft_putchar_fd(tmp + 48, output);
	}
}

void	ft_putptr(unsigned long long num, int output)
{
	unsigned long long	tmp;

	tmp = 0;
	if (num)
	{
		tmp = num % 16;
		ft_putptr(num / 16, output);
		if (tmp > 9)
			ft_putchar_fd(tmp + 87, output);
		else
			ft_putchar_fd(tmp + 48, output);
	}
}
