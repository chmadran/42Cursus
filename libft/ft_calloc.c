/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:02:28 by chmadran          #+#    #+#             */
/*   Updated: 2022/11/16 16:12:56 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*str;

	if (elementCount >= SIZE_MAX || elementSize >= SIZE_MAX)
		return (0);
	str = malloc(elementCount * elementSize);
	if (!str)
		return (0);
	ft_bzero(str, elementCount * elementSize);
	return (str);
}
