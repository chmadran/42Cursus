/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5.ft_isascii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:15:45 by chmadran          #+#    #+#             */
/*   Updated: 2022/11/09 17:24:49 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/* int	main(void)
{
	printf("%d\n", ft_isascii('A'));
	printf("%d\n", isascii('A'));
	printf("%d\n", ft_isascii(128));
	printf("%d\n", isascii(128));
} */
