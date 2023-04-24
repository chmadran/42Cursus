/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:02:28 by chmadran          #+#    #+#             */
/*   Updated: 2022/11/16 16:11:52 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, const char *set)
{
	char	*newstr;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (!s1 || !set)
		return (0);
	j = ft_strlen(s1) - 1;
	while (s1[i] && ft_check_set(s1[i], set) == 1)
		i++;
	while (j > i && ft_check_set(s1[j], set) == 1)
		j--;
	newstr = malloc(sizeof(char) * (j - i + 2));
	if (!newstr)
		return (0);
	while (i <= j)
		newstr[k++] = s1[i++];
	newstr[k] = '\0';
	return (newstr);
}
