/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.ft_sort3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:47:01 by chmadran          #+#    #+#             */
/*   Updated: 2023/04/24 13:51:13 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

static int	ft_highest_index(t_list *li)
{
	int	index;

	index = li->index;
	while (li)
	{
		if (li->index > index)
			index = li->index;
		li = li->next;
	}
	return (index);
}

void	ft_sort3(t_list **li)
{
	int	highest_index;

	if (ft_is_sorted(*li) == 0)
		return ;
	highest_index = ft_highest_index(*li);
	if ((*li)->index == highest_index)
		move_ra(li);
	else if ((*li)->next->index == highest_index)
		move_rra(li);
	if ((*li)->index > (*li)->next->index)
		move_sa(li);
}
