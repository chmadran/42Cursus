/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:56:33 by chmadran          #+#    #+#             */
/*   Updated: 2023/04/24 13:41:49 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_utoa(unsigned int n);

int	ft_putnbr_unsigned_int(unsigned int nbr)
{
	char	*str;
	int		i;

	if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
	{
		str = ft_utoa(nbr);
		i = ft_putstr(str);
	}
	free(str);
	return (i);
}

int	ft_strlen_string_u(unsigned int nb)
{
	unsigned int	len;

	len = 0;
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_utoa(unsigned int n)
{
	char	*newchar;
	int		i;

	i = ft_strlen_string_u(n);
	newchar = malloc(sizeof(char) * (i + 1));
	if (!newchar)
		return (0);
	newchar[i--] = '\0';
	while (i >= 0)
	{
		newchar[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (newchar);
}
