/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:56:33 by chmadran          #+#    #+#             */
/*   Updated: 2023/04/24 13:41:17 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_itoa(int n);

int	ft_putnbr(int nbr)
{
	char	*str;
	int		i;

	str = ft_itoa(nbr);
	i = ft_putstr(str);
	free(str);
	return (i);
}

int	ft_strlen_string(int nb)
{
	int	len;

	len = (nb < 0 || nb == 0);
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*newchar;
	long		num;
	int			i;
	int			neg;

	num = (n > 0) *(long)n - (n < 0) * (long) n;
	i = ft_strlen_string(n);
	newchar = malloc(sizeof(char) * i + 1);
	if (!newchar)
		return (0);
	neg = (n < 0);
	if (neg)
		newchar[0] = '-';
	newchar[i--] = '\0';
	while (i >= neg)
	{
		newchar[i] = num % 10 + '0';
		num = num / 10;
		i--;
	}
	return (newchar);
}
