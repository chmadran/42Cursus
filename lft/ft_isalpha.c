/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.ft_isalpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:13:47 by chmadran          #+#    #+#             */
/*   Updated: 2022/11/09 17:24:04 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

/* int	main(void)
{
	printf("%d\n", ft_isalpha('A')); // resultat 1
	printf("%d\n\n", isalpha('A')); // resultat 1024
	printf("%d\n", ft_isalpha('1'));
	printf("%d\n\n", isalpha('1'));

} */
