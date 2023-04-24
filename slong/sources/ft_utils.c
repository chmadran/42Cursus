/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:49:47 by chmadran          #+#    #+#             */
/*   Updated: 2023/04/24 13:56:28 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

int	ft_my_strchr(char *s1, char *s2)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (s1[i])
	{
		while (s1[i + y] == s2[y] && s1[i + y] && s2[y])
			y++;
		if (!s1[i + y] && !s2[y])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strcat(char *buff, char *temp_buf)
{
	char	*temp;

	temp = ft_strjoin(buff, temp_buf);
	free (buff);
	return (temp);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
