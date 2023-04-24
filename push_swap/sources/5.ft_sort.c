/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5.ft_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:47:14 by chmadran          #+#    #+#             */
/*   Updated: 2023/04/24 13:51:18 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	ft_push_to_b(t_list **stackA, t_list **stackB)
{
	int		i;
	int		pushed;
	int		stacksize;

	i = 0;
	pushed = 0;
	stacksize = ft_size_stack(*stackA);
	while (stacksize > 6 && i < stacksize && pushed < (stacksize / 2))
	{
		if ((*stackA)->index <= (stacksize / 2))
		{
			move_pb(stackA, stackB);
			pushed++;
		}
		else
			move_ra(stackA);
		i++;
	}
	while (stacksize - pushed > 3)
	{
		move_pb(stackA, stackB);
		pushed++;
	}
}

void	ft_shift_stack(t_list **stackA)
{
	int	lowestpos;
	int	sizestack;

	sizestack = ft_size_stack(*stackA);
	lowestpos = ft_lowest_index(stackA);
	if (lowestpos > (sizestack / 2))
	{
		while (lowestpos < sizestack)
		{
			move_rra(stackA);
			lowestpos++;
		}
	}
	else
	{
		while (lowestpos > 0)
		{
			move_ra(stackA);
			lowestpos--;
		}
	}
}

void	ft_sort(t_list **stackA, t_list **stackB)
{
	ft_push_to_b(stackA, stackB);
	ft_sort3(stackA);
	while (*stackB)
	{
		ft_assign_target_pos(stackA, stackB);
		ft_move_cost(stackA, stackB);
		ft_move_cheapest(stackA, stackB);
	}
	if (ft_is_sorted(*stackA) == 1)
		ft_shift_stack(stackA);
}
