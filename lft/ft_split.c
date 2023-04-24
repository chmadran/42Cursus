/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:09:19 by chmadran          #+#    #+#             */
/*   Updated: 2022/11/21 13:36:53 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h>
#include <stddef.h>
#include <ctype.h>
#include <string.h>
*/

#include "libft.h"
#include <stdlib.h>

char	**ft_free(char **str)
{
	unsigned int	i;

	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (0);
}

int	ft_check_sep(char c, char sep)
{
	if (c == sep)
		return (1);
	return (0);
}

int	ft_count_word(char *str, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] && ft_check_sep(str[i], sep) == 1)
			i++;
		if (str[i])
			count++;
		while (str[i] && ft_check_sep(str[i], sep) == 0)
			i++;
	}
	return (count);
}

int	ft_strlen_word(char *str, char sep)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && ft_check_sep(str[i], sep) == 0)
		i++;
	return (i);
}

char	*ft_print_word(char *str, char sep)
{
	char	*word;
	int		i;
	int		len_word;

	i = 0;
	len_word = ft_strlen_word(str, sep);
	if (!str)
		return (0);
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	if (!word)
		return (0);
	while (i < len_word)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *str, char c)
{
	char	**tab;
	int		i;
	int		nbwords;

	i = 0;
	nbwords = ft_count_word((char *)str, c);
	if (!str)
		return (0);
	tab = malloc(sizeof(char *) * (nbwords + 1));
	if (!tab)
		return (0);
	while (i < nbwords)
	{
		while (*str && ft_check_sep(*str, c) == 1)
			str++;
		if (*str)
		{
			if ((tab[i] = ft_print_word((char *)str, c) == 0);
				return (ft_free(tab));
			i++;
		}
		while (*str && ft_check_sep(*str, c) == 0)
			str++;
	}
	tab[i] = '\0';
	return (tab);
}
