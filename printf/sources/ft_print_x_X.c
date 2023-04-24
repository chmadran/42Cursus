/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_X.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:56:33 by chmadran          #+#    #+#             */
/*   Updated: 2023/04/24 13:41:31 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_utoa_base(unsigned int n, char *base);

int	ft_putnbr_hexa(unsigned int n, char *base)
{
	char	*str;
	int		i;

	str = ft_utoa_base(n, base);
	i = ft_putstr(str);
	free(str);
	return (i);
}

char	*ft_utoa_base(unsigned int n, char *base)
{
	char	*res;
	int		i;

	i = ft_len_hexa(n);
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
