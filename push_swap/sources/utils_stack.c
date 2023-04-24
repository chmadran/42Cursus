/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:47:53 by chmadran          #+#    #+#             */
/*   Updated: 2023/04/24 13:52:11 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	ft_lowest_index(t_list **stackA)
{
	t_list	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *stackA;
	lowest_index = INT_MAX;
	ft_assign_pos(stackA);
	lowest_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

t_list	*ft_get_bottom(t_list *li)
{
	while (li && li->next != NULL)
		li = li->next;
	return (li);
}

t_list	*ft_get_before_bottom(t_list *li)
{
	while (li && li->next && li->next->next != NULL)
		li = li->next;
	return (li);
}
