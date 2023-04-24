/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6.ft_isdigit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:17:21 by chmadran          #+#    #+#             */
/*   Updated: 2022/11/09 17:25:41 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

/* int	main(void)
{
	printf("%d\n", ft_isdigit('1')); // resultat 1
	printf("%d\n", isdigit('1')); // resultat 2048
	printf("%d\n", ft_isdigit('A'));
	printf("%d\n", isdigit('A'));
} */
