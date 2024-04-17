/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:48:43 by megadiou          #+#    #+#             */
/*   Updated: 2023/12/14 12:25:39 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fprintf(int output, const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	count = ft_start_printf(args, format, output);
	va_end(args);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	count = ft_start_printf(args, format, 1);
	va_end(args);
	return (count);
}
