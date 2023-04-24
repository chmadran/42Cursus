/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:13:19 by chmadran          #+#    #+#             */
/*   Updated: 2022/11/11 13:41:24 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
	dest[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

/* 
#include <string.h>
#include <stdio.h>
#include <stddef.h>

int	main(void)
{
	printf("%ld\n", ft_strlcpy("hello", "wooorld", 15));
	// printf("%ld\n", strlcpy("hello", "wooorld", 15));
} */
