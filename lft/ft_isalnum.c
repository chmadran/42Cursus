/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8.ft_isalnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:20:28 by chmadran          #+#    #+#             */
/*   Updated: 2022/11/09 17:27:15 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (c >= 65 && c <= 90)
		return (1);
	else if (c >= 97 && c <= 122)
		return (1);
	else if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

/* int	main(void)
{
	printf("%d\n", ft_isalnum('a')); // resultat 1
	printf("%d\n", isalnum('a')); // resultat 8
	printf("%d\n", ft_isalnum(' '));
	printf("%d\n", isalnum(' '));
	printf("%d\n", ft_isalnum('1')); // resultat 1
	printf("%d\n", isalnum('1')); // resultat 8
} */
