/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:47:34 by ecaliska          #+#    #+#             */
/*   Updated: 2023/11/19 20:24:46 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushmin(t_list **stack_a, t_list **stack_b)
{
	int		min;
	t_list	*temp;
	int		pos;

	temp = *stack_a;
	min = temp->content;
	while (temp)
	{
		if (min > temp->content)
			min = temp->content;
		temp = temp->next;
	}
	pos = getpos(*stack_a, min);
	while (min != (*stack_a)->content)
	{
		if (pos <= (ft_lstsize(*stack_a) / 2))
			ra(&(*stack_a), 1);
		else
			rra(&(*stack_a), 1);
	}
	pb(&(*stack_a), &(*stack_b));
}

void	sorttwo(t_list **stack_a)
{
	int	a;
	int	b;

	if (is_sorted((*stack_a)) == 1)
		return ;
	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	if (a > b)
		ra(&(*stack_a), 1);
}

void	sortthree(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;

	if (is_sorted((*stack_a)) == 1)
		return ;
	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	c = (*stack_a)->next->next->content;
	if (a > b && b < c && a < c)
		sa((*stack_a));
	else if (a > b && b > c && a > c)
	{
		sa((*stack_a));
		rra(&(*stack_a), 1);
	}
	else if (a > b && b < c && a > c)
		ra(&(*stack_a), 1);
	else if (a < b && b > c && a < c)
	{
		sa((*stack_a));
		ra(&(*stack_a), 1);
	}
	else if (a < b && b > c && a > c)
		rra(&(*stack_a), 1);
}

void	sortfour(t_list **stack_a, t_list **stack_b)
{
	if (is_sorted((*stack_a)) == 1)
		return ;
	pushmin(&(*stack_a), &(*stack_b));
	sortthree(&(*stack_a));
	pa(&(*stack_a), &(*stack_b));
}

void	sortfive(t_list **stack_a, t_list **stack_b)
{
	if (is_sorted((*stack_a)) == 1)
		return ;
	pushmin(&(*stack_a), &(*stack_b));
	pushmin(&(*stack_a), &(*stack_b));
	sortthree(&(*stack_a));
	pa(&(*stack_a), &(*stack_b));
	pa(&(*stack_a), &(*stack_b));
}
