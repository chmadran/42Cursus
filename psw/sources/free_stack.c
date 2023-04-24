/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:47:33 by chmadran          #+#    #+#             */
/*   Updated: 2023/04/24 13:51:54 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	ft_error(t_list **li)
{
	ft_free_stack(li);
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_free_stack(t_list **li)
{
	t_list	*tmp;

	while (*li != NULL)
	{
		tmp = (*li)->next;
		free(*li);
		*li = tmp;
	}
	*li = NULL;
}
