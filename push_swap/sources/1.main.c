/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:46:32 by chmadran          #+#    #+#             */
/*   Updated: 2023/04/24 13:51:01 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	ft_is_sorted(t_list *li)
{
	while (li->next != NULL)
	{
		if (li->value > li->next->value)
			return (1);
		li = li->next;
	}
	return (0);
}

void	ft_sorting_algo(int size, t_list **stackA, t_list **stackB)
{
	if (size == 2 && ft_is_sorted(*stackA) == 1)
		move_sa(stackA);
	else if (size == 3 && ft_is_sorted(*stackA) == 1)
		ft_sort3(stackA);
	else if (size > 3 && ft_is_sorted(*stackA) == 1)
		ft_sort(stackA, stackB);
	else if (ft_is_sorted(*stackA) == 0)
		return ;
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size_stack;

	if (ac < 2)
		return (0);
	if (ft_check_arg(ac, av) == 1)
	{
		ft_error(&stack_a);
		return (0);
	}
	stack_b = NULL;
	stack_a = ft_initialise(ac, av);
	size_stack = ft_size_stack(stack_a);
	ft_index_stack(stack_a, size_stack + 1, INT_MIN);
	ft_sorting_algo(size_stack, &stack_a, &stack_b);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
}
