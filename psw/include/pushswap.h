/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:47:46 by chmadran          #+#    #+#             */
/*   Updated: 2023/01/19 10:53:19 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>

typedef struct liste
{
	struct liste	*next;
	int				value;
	int				index;
	int				pos;
	int				tpos;
	int				cost_a;
	int				cost_b;

}	t_list;

/*---------- Functions that check the arguments--------------*/

int		ft_strcmp(char *s1, char *s2);
int		ft_is_number(char *av);
int		ft_check_doubles(char **av);
int		ft_check_arg(int ac, char **av);
long	ft_atoi(char *str);

/*---------- Functions that initialise the stacks-------------*/

void	ft_add_bottom(t_list **li, t_list *new);
t_list	*ft_first_element(int nb);
t_list	*ft_initialise(int ac, char **av);

/*----------Utils -------------*/

int		ft_turnpos(int n);
int		ft_size_stack(t_list *li);
void	ft_free_stack(t_list **li);
void	ft_putstr(char *str);
void	ft_error(t_list **li);
t_list	*ft_get_bottom(t_list *li);
t_list	*ft_get_before_bottom(t_list *li);

/*---------- Main--------------*/

int		ft_is_sorted(t_list *li);
//int		ft_highest_index(t_list *li);
void	ft_sorting_algo(int size, t_list **stackA, t_list **stackB);
void	ft_index_stack(t_list *li, int stackSize, int value);
void	ft_sort3(t_list **li);

/*---------- Functions that sort > 3 -----------*/

int		ft_assign_tpos(t_list **stackA, int indexB, int tpos, int tindex);
void	ft_assign_target_pos(t_list **stackA, t_list **stackB);
void	ft_sort(t_list **stackA, t_list **stackB);
void	ft_push_to_b(t_list **src, t_list **dest);
void	ft_assign_pos(t_list **li);

void	ft_move_cost(t_list **stackA, t_list **stackB);
void	ft_move_cheapest(t_list **stackA, t_list **stackB);
void	ft_move(t_list **stackA, t_list **stackB, int cost_a, int cost_b);

void	rev_rotate_both(t_list **stackA, t_list **stackB,
			int *cost_a, int *cost_b);
void	rotate_both(t_list **stackA, t_list **stackB, int *cost_a, int *cost_b);
void	rotate_stacka(t_list **stackA, int *costA);
void	rotate_stackb(t_list **stackB, int *costB);

void	ft_shift_stack(t_list **stackA);
int		ft_lowest_index(t_list **stackA);

/*---------- Functions that move--------------*/

void	move_swap(t_list *li);
void	move_sa(t_list **stackA);
void	move_sb(t_list **stackB);
void	move_ss(t_list **stackA, t_list **stackB);

void	move_rotate(t_list **li);
void	move_ra(t_list **stackA);
void	move_rb(t_list **stackB);
void	move_rr(t_list **stackA, t_list **stackB);

void	move_rrotate(t_list **li);
void	move_rra(t_list **stackA);
void	move_rrb(t_list **stackB);
void	move_rrr(t_list **stackA, t_list **stackB);

void	move_push(t_list **stack1, t_list **stack2);
void	move_pa(t_list **stackA, t_list **stackB);
void	move_pb(t_list **stackA, t_list **stackB);

#endif
