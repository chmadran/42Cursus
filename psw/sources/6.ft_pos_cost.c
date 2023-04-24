/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6.ft_pos_cost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:47:14 by chmadran          #+#    #+#             */
/*   Updated: 2023/04/24 13:51:22 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	ft_assign_pos(t_list **li)
{
	t_list	*tmp;
	int		position;

	tmp = *li;
	position = 0;
	while (tmp)
	{
		tmp->pos = position;
		tmp = tmp->next;
		position++;
	}
}

int	ft_assign_tpos(t_list **stackA, int indexB, int tpos, int tindex)
{
	t_list		*tmp_a;

	tmp_a = *stackA;
	while (tmp_a)
	{
		if (tmp_a->index > indexB && tmp_a->index < tindex)
		{
			tindex = tmp_a->index;
			tpos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (tindex != INT_MAX)
		return (tpos);
	tmp_a = *stackA;
	while (tmp_a)
	{
		if (tmp_a->index < tindex)
		{
				tindex = tmp_a->index;
				tpos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (tpos);
}

void	ft_assign_target_pos(t_list **stackA, t_list **stackB)
{
	t_list	*tmp_b;
	int		target_pos;

	tmp_b = *stackB;
	target_pos = 0;
	ft_assign_pos(stackA);
	ft_assign_pos(stackB);
	while (tmp_b)
	{
		target_pos = ft_assign_tpos(stackA, tmp_b->index, target_pos, INT_MAX);
		tmp_b->tpos = target_pos;
		tmp_b = tmp_b->next;
	}
}

void	ft_move_cheapest(t_list **stackA, t_list **stackB)
{
	t_list	*tmp_b;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp_b = *stackB;
	cheapest = INT_MAX;
	while (tmp_b)
	{
		if (ft_turnpos(tmp_b->cost_a) + ft_turnpos(tmp_b->cost_b)
			< ft_turnpos(cheapest))
		{
			cheapest = (tmp_b->cost_a) + (tmp_b->cost_b);
			cost_a = tmp_b->cost_a;
			cost_b = tmp_b->cost_b;
		}
		tmp_b = tmp_b->next;
	}
	ft_move(stackA, stackB, cost_a, cost_b);
}

void	ft_move_cost(t_list **stackA, t_list **stackB)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stackA;
	tmp_b = *stackB;
	size_a = ft_size_stack(tmp_a);
	size_b = ft_size_stack(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->pos > (size_b / 2))
			tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
		tmp_b->cost_a = tmp_b->tpos;
		if (tmp_b->tpos > (size_a / 2))
			tmp_b->cost_a = (size_a - tmp_b->tpos) * -1;
		tmp_b = tmp_b->next;
	}
}
