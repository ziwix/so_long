/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:53:07 by megadiou          #+#    #+#             */
/*   Updated: 2023/12/14 12:25:56 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

/************************/
/*		ft_printf.c		*/
/************************/

int		ft_fprintf(int output, const char *format, ...);
int		ft_printf(const char *format, ...);

/************************/
/*		ft_utils		*/
/************************/

int		ft_check_args(va_list args, char format, int output);
int		ft_start_printf(va_list args, const char *format, int output);

/************************/
/*		ft_length		*/
/************************/

int		ft_len_hexa(unsigned int num);
int		ft_len_u_ptr(unsigned long long num);
int		ft_decimal_len(int num);
int		ft_unsigned_len(unsigned int num);

/*********************/
/*		ft_hexa		 */
/*********************/

void	ft_putnbr_unsigned(unsigned int n, int output);
void	ft_putnbr_base16(unsigned int num, int upLow, int output);
void	ft_putptr(unsigned long long num, int output);

/****************************/
/*		ft_print_chars		*/
/****************************/

int		ft_print_char(va_list args, int output);
int		ft_print_string(va_list args, int output);
int		ft_print_percent(int output);

/**********************************/
/*        ft_print_numbers        */
/**********************************/

int		ft_print_int_decimal(va_list args, int output);
int		ft_print_unsigned_int(va_list args, int output);
int		ft_print_hexa(va_list args, char lowOrUp, int output);
int		ft_print_ptr(va_list args, int output);

#endif