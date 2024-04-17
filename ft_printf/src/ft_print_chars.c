/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:39:49 by megadiou          #+#    #+#             */
/*   Updated: 2023/12/14 12:16:46 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(va_list args, int output)
{
	char	c;

	c = va_arg(args, int);
	ft_putchar_fd(c, output);
	return (1);
}

int	ft_print_string(va_list args, int output)
{
	char	*str;
	int		len;

	str = va_arg(args, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", output);
		return (6);
	}
	len = (int)ft_strlen(str);
	ft_putstr_fd(str, output);
	return (len);
}

int	ft_print_percent(int output)
{
	char	c;

	c = '%';
	ft_putchar_fd(c, output);
	return (1);
}
