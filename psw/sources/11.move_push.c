/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11.move_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:47:33 by chmadran          #+#    #+#             */
/*   Updated: 2023/04/24 13:51:48 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	move_push(t_list **src, t_list **dest)
{
	t_list	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = (*dest);
	(*dest) = (*src);
	(*src) = tmp;
}

void	move_pa(t_list **stackA, t_list **stackB)
{
	move_push(stackB, stackA);
	ft_putstr("pa\n");
}

void	move_pb(t_list **stackA, t_list **stackB)
{
	move_push(stackA, stackB);
	ft_putstr("pb\n");
}
