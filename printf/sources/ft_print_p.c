/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:01:53 by chmadran          #+#    #+#             */
/*   Updated: 2023/04/24 13:41:22 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_itoa_base(unsigned long n, char *base);
int		ft_putstr_p(char *str);
int		ft_len_hexa_p(unsigned long n);

int	ft_putnbr_void_pointer(void *nbr)
{
	char	*str;
	int		i;

	if (nbr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		str = ft_itoa_base((unsigned long)nbr, "0123456789abcdef");
		i = ft_putstr_p(str);
	}
	free(str);
	return (i);
}

char	*ft_itoa_base(unsigned long n, char *base)
{
	char	*res;
	int		i;

	i = ft_len_hexa_p(n);
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (0);
	res[i--] = '\0';
	while (i >= 0)
	{
		res[i] = base[n % 16];
		n = n / 16;
		i--;
	}
	return (res);
}

int	ft_putstr_p(char *str)
{
	int	i;

	i = 0;
	write(1, "0x", 2);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i + 2);
}

int	ft_len_hexa_p(unsigned long n)
{
	int	res;

	res = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 16;
		res++;
	}
	return (res);
}
