/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7.move_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:47:19 by chmadran          #+#    #+#             */
/*   Updated: 2023/04/24 13:51:28 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	rev_rotate_both(t_list **stackA, t_list **stackB, int *cost_a,
			int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		move_rrr(stackA, stackB);
	}
}

void	rotate_both(t_list **stackA, t_list **stackB, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		move_rr(stackA, stackB);
	}
}

void	rotate_stacka(t_list **stackA, int *costA)
{
	while (*costA)
	{
		if (*costA > 0)
		{
			move_ra(stackA);
			(*costA)--;
		}
		else if (*costA < 0)
		{
			move_rra(stackA);
			(*costA)++;
		}
	}
}

void	rotate_stackb(t_list **stackB, int *costB)
{
	while (*costB)
	{
		if (*costB > 0)
		{
			move_rb(stackB);
			(*costB)--;
		}
		else if (*costB < 0)
		{
			move_rrb(stackB);
			(*costB)++;
		}
	}
}

void	ft_move(t_list **stackA, t_list **stackB, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		rev_rotate_both(stackA, stackB, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		rotate_both(stackA, stackB, &cost_a, &cost_b);
	rotate_stacka(stackA, &cost_a);
	rotate_stackb(stackB, &cost_b);
	move_pa(stackA, stackB);
}
