/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_identify.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:28:46 by chmadran          #+#    #+#             */
/*   Updated: 2023/04/24 13:41:14 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_identify(const char *format, int i, va_list ap)
{
	if (format[i] == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (format[i] == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (format[i] == '%')
		return (ft_putchar(format[i]));
	else if (format[i] == 'd' || format[i] == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (format[i] == 'u')
		return (ft_putnbr_unsigned_int(va_arg(ap, unsigned int)));
	else if (format[i] == 'p')
		return (ft_putnbr_void_pointer(va_arg(ap, void *)));
	else if (format[i] == 'x')
		return (ft_putnbr_hexa(va_arg(ap, unsigned int), "0123456789abcdef"));
	else if (format[i] == 'X')
		return (ft_putnbr_hexa(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	return (0);
}
