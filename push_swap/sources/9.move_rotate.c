/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9.move_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:47:38 by chmadran          #+#    #+#             */
/*   Updated: 2023/04/24 13:51:38 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	move_rotate(t_list **li)
{
	t_list	*first;
	t_list	*last;

	first = *li;
	*li = (*li)->next;
	last = ft_get_bottom(*li);
	first->next = NULL;
	last->next = first;
}

void	move_ra(t_list **stackA)
{
	move_rotate(stackA);
	ft_putstr("ra\n");
}

void	move_rb(t_list **stackB)
{
	move_rotate(stackB);
	ft_putstr("rb\n");
}

void	move_rr(t_list **stackA, t_list **stackB)
{
	move_rotate(stackA);
	move_rotate(stackB);
	ft_putstr("rr\n");
}
