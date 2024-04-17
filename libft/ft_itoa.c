/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:11:25 by megadiou          #+#    #+#             */
/*   Updated: 2023/11/07 15:29:56 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_power(int nb)
{
	int	pow;

	pow = 1;
	while (nb / 10 != 0)
	{
		nb /= 10;
		pow *= 10;
	}
	return (pow);
}

static char	*ft_putnbr(int nb, char *arr)
{
	int	pow;
	int	i;

	i = 0;
	pow = ft_find_power(nb);
	if (nb < 0)
	{
		arr[i] = '-';
		nb *= -1;
		i++;
	}
	while (pow >= 1)
	{
		arr[i] = (nb / pow) + 48;
		nb %= pow;
		pow /= 10;
		i++;
	}
	arr[i] = 0;
	return (arr);
}

int	ft_size(int nb)
{
	int	i;

	i = 1;
	if (nb < 0)
		i++;
	while (nb / 10 != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*arr;

	i = ft_size(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	arr = (char *)malloc(sizeof(char) * (i + 1));
	if (!arr)
		return (NULL);
	arr = ft_putnbr(n, arr);
	return (arr);
}
