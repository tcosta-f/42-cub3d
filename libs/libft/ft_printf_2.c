/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschwell <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:00:37 by bschwell          #+#    #+#             */
/*   Updated: 2025/04/18 11:47:39 by bschwell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int n, int uint)
{
	long int	i;
	size_t		count;

	if (!uint)
		i = n;
	else
		i = (unsigned int) n;
	count = 0;
	if (i < 0)
	{
		count += ft_putchar('-');
		i *= -1;
	}
	if (i < 10)
		count += ft_putchar((i % 10) + '0');
	else
	{
		count += ft_putnbr(i / 10, 0);
		count += ft_putnbr(i % 10, 0);
	}
	return (count);
}

static int	ft_putnbr_base_ptr(unsigned long ptr, char *base)
{
	size_t			count;
	size_t			base_len;

	base_len = ft_strlen(base);
	count = 0;
	if (ptr < base_len)
		count += ft_putchar(base[ptr % base_len]);
	else
	{
		count += ft_putnbr_base_ptr(ptr / base_len, base);
		count += ft_putnbr_base_ptr(ptr % base_len, base);
	}
	return (count);
}

int	ft_putptr(unsigned long ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
		count += ft_putstr("(nil)");
	else
	{
		count += ft_putstr("0x");
		count += ft_putnbr_base_ptr(ptr, "0123456789abcdef");
	}
	return (count);
}
