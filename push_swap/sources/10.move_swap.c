/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10.move_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:47:25 by chmadran          #+#    #+#             */
/*   Updated: 2023/04/24 13:51:42 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	move_swap(t_list *li)
{
	int	tmp;

	tmp = li->value;
	li->value = li->next->value;
	li->next->value = tmp;
	tmp = li->index;
	li->index = li->next->index;
	li->next->index = tmp;
}

void	move_sa(t_list **stackA)
{
	move_swap(*stackA);
	ft_putstr("sa\n");
}

void	move_sb(t_list **stackB)
{
	move_swap(*stackB);
	ft_putstr("sb\n");
}

void	move_ss(t_list **stackA, t_list **stackB)
{
	move_swap(*stackA);
	move_swap(*stackB);
	ft_putstr("ss\n");
}
