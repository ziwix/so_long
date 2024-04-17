/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:27:05 by megadiou          #+#    #+#             */
/*   Updated: 2023/12/14 12:20:21 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int_decimal(va_list args, int output)
{
	int	num;
	int	count;

	num = va_arg(args, int);
	count = ft_decimal_len(num);
	ft_putnbr_fd(num, output);
	return (count);
}

int	ft_print_unsigned_int(va_list args, int output)
{
	unsigned int	u_num;
	int				count;

	u_num = va_arg(args, unsigned int);
	count = ft_unsigned_len(u_num);
	ft_putnbr_unsigned(u_num, output);
	return (count);
}

int	ft_print_hexa(va_list args, char format, int output)
{
	int	hexa_num;
	int	count;

	hexa_num = va_arg(args, int);
	count = ft_len_hexa(hexa_num);
	if (hexa_num == 0)
	{
		ft_putchar_fd('0', output);
		count++;
	}
	if (format == 'x')
		ft_putnbr_base16(hexa_num, 87, output);
	if (format == 'X')
		ft_putnbr_base16(hexa_num, 55, output);
	return (count);
}

int	ft_print_ptr(va_list args, int output)
{
	char	*ptr;
	int		count;

	ptr = va_arg(args, char *);
	if (!ptr)
	{
		ft_putstr_fd("(nil)", output);
		return (5);
	}
	count = ft_len_u_ptr(((unsigned long long)ptr));
	ft_putstr_fd("0x", output);
	count += 2;
	ft_putptr((unsigned long long)ptr, output);
	return (count);
}
