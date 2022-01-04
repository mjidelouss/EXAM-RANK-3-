/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 19:59:58 by aelousse          #+#    #+#             */
/*   Updated: 2022/01/04 20:02:56 by aelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int	ft_putchar(char c)
{
	return(write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	len = 0;

	if (!str)
		str = "(null)";
	while (*str)
		len += write(1, str++, 1);
	return (len);
}

int	ft_putnbr(long nb)
{
	int		len = 0;
	
	if (nb < 0)
	{
		nb = -nb;
		len += ft_putchar('-');
	}
	if (nb < 10)
	{
		len += ft_putchar(nb + '0');
	}
	else
	{
		len += ft_putnbr(nb / 10);
		len += ft_putnbr(nb % 10);
	}
	return (len);
}

int	ft_puthexa(unsigned long nb)
{
	char	base[16] = "0123456789abcdef";
	int		len = 0;

	if (nb >= 16)
	{
		len += ft_puthexa(nb / 16);
		len += ft_puthexa(nb % 16);
	}
	if (nb < 16)
		len += ft_putchar(base[nb]);
	return (len);
}

int	ft_printf(char *format, ...)
{
	int		i = 0;
	int		len = 0;
	va_list	ap;

	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'd' || format[i + 1] == 's' || format[i + 1] == 'x')
			{
				if (format[i + 1] == 'd')
					len += ft_putnbr(va_arg(ap, int));
				if (format[i + 1] == 's')
					len += ft_putstr(va_arg(ap, char *));
				if (format[i + 1] == 'x')
					len += ft_puthexa(va_arg(ap, unsigned long));
			}
			else
				len += ft_putchar(format[i + 1]);
			i++;
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (len);
}
