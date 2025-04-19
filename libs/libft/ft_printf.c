/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschwell <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:40:30 by bschwell          #+#    #+#             */
/*   Updated: 2025/04/18 11:46:21 by bschwell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	long long int	i;

	i = 0;
	if (str == NULL)
	{
		return (ft_putstr("(null)"));
	}
	while (*str)
		i += ft_putchar(*str++);
	return (i);
}

int	ft_putnbr_base(int n, char *base)
{
	size_t	i;
	size_t	count;
	size_t	base_len;

	base_len = ft_strlen(base);
	i = (unsigned int) n;
	count = 0;
	if (i < base_len)
		count += ft_putchar(base[i % base_len]);
	else
	{
		count += ft_putnbr_base(i / base_len, base);
		count += ft_putnbr_base(i % base_len, base);
	}
	return (count);
}

static int	ft_parsefmt(const char conv, va_list *ap)
{
	if (conv == 'c')
		return (ft_putchar(va_arg(*ap, int)));
	if (conv == 's')
		return (ft_putstr(va_arg(*ap, char *)));
	if (conv == 'd' || conv == 'i')
		return (ft_putnbr(va_arg(*ap, int), 0));
	if (conv == 'u')
		return (ft_putnbr(va_arg(*ap, int), 1));
	if (conv == 'x')
		return (ft_putnbr_base(va_arg(*ap, int), "0123456789abcdef"));
	if (conv == 'X')
		return (ft_putnbr_base(va_arg(*ap, int), "0123456789ABCDEF"));
	if (conv == 'p')
		return (ft_putptr(va_arg(*ap, unsigned long)));
	if (conv == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			res;
	int			i;

	res = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			res += ft_parsefmt(format[i + 1], &args);
			i++;
		}
		else
		{
			res += write(1, &format[i], 1);
		}
		i++;
	}
	va_end(args);
	return (res);
}
