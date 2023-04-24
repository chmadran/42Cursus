/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7.ft_isprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:18:48 by chmadran          #+#    #+#             */
/*   Updated: 2022/11/09 17:26:26 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/* int	main(void)
{
	printf("%d\n", ft_isprint(1));
	printf("%d\n", isprint(1));
	printf("%d\n", ft_isprint(33)); // resultat 1
	printf("%d\n", isprint(33)); // resultat 16384
} */
