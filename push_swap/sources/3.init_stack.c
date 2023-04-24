/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.init_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:46:57 by chmadran          #+#    #+#             */
/*   Updated: 2023/04/24 13:51:08 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	ft_add_bottom(t_list **li, t_list *new)
{
	t_list	*last;

	if (!new)
		return ;
	if (!*li)
	{
		*li = new;
		return ;
	}
	last = ft_get_bottom(*li);
	last->next = new;
}

t_list	*ft_new_element(int nb)
{
	t_list	*new_element;

	new_element = malloc(sizeof(t_list));
	new_element->value = nb;
	new_element->index = 0;
	new_element->pos = -1;
	new_element->tpos = -1;
	new_element->cost_a = -1;
	new_element->cost_b = -1;
	new_element->next = NULL;
	return (new_element);
}

t_list	*ft_initialise(int ac, char **av)
{
	long int	nb;
	int			i;
	t_list		*stack_a;

	i = 1;
	nb = 0;
	stack_a = NULL;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			ft_error(&stack_a);
		if (i == 1)
			stack_a = ft_new_element((int)nb);
		else
			ft_add_bottom(&stack_a, ft_new_element((int)nb));
		i++;
	}
	return (stack_a);
}

int	ft_size_stack(t_list *li)
{
	int	count;

	count = 0;
	if (!li)
		return (0);
	while (li)
	{
		li = li->next;
		count++;
	}
	return (count);
}

void	ft_index_stack(t_list *li, int stackSize, int value)
{
	t_list	*current;
	t_list	*highest;

	while (--stackSize > 0)
	{
		current = li;
		value = INT_MIN;
		highest = NULL;
		while (current)
		{
			if (current->value == INT_MIN && current->index == 0)
				current->index = 1;
			if (current->value > value && current->index == 0)
			{
				value = current->value;
				highest = current;
				current = li;
			}
			else
				current = current->next;
		}
		if (highest != NULL)
			highest->index = stackSize;
	}
}
