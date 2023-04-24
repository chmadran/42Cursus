/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:59:28 by chmadran          #+#    #+#             */
/*   Updated: 2022/11/16 16:01:14 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dlen;
	size_t	slen;

	if (dst == 0 && size == 0)
		return (0);
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	i = 0;
	if (dlen >= size)
		return (slen + size);
	if (dlen < size - 1 && size > 0)
	{
		while (src[i] && dlen + i < size - 1)
		{
			dst[dlen + i] = src[i];
			i++;
		}
		dst[dlen + i] = '\0';
	}
	return (dlen + slen);
}
