/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8.move_rrotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:47:22 by chmadran          #+#    #+#             */
/*   Updated: 2023/04/24 13:51:32 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	move_rrotate(t_list **li)
{
	t_list	*tmp;
	t_list	*last;
	t_list	*beforelast;

	last = ft_get_bottom(*li);
	beforelast = ft_get_before_bottom(*li);
	tmp = (*li);
	(*li) = last;
	(*li)->next = tmp;
	beforelast->next = NULL;
}

void	move_rra(t_list **stackA)
{
	move_rrotate(stackA);
	ft_putstr("rra\n");
}

void	move_rrb(t_list **stackB)
{
	move_rrotate(stackB);
	ft_putstr("rrb\n");
}

void	move_rrr(t_list **stackA, t_list **stackB)
{
	move_rrotate(stackA);
	move_rrotate(stackB);
	ft_putstr("rrr\n");
}
