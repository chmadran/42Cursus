/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:19:08 by chmadran          #+#    #+#             */
/*   Updated: 2022/11/11 18:40:12 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s1 + i) != *(unsigned char *)(s2 + i))
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <stddef.h>
#include <string.h>

int	main(void)
{
	char	src[] = "123";
	char	dest[] = "123";

	printf("%d\n", ft_memcmp(dest, src, 100));
	printf("%d\n", memcmp(dest, src, 100));

	printf("%d\n", ft_memcmp(dest, src, 100));
	printf("%d\n", memcmp(dest, src, 100));
} */
