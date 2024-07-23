/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:56:09 by ecaliska          #+#    #+#             */
/*   Updated: 2023/11/18 21:16:11 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **stack_a, int print)
{
	t_list	*temp;
	t_list	*add;
	int		node;

	temp = *stack_a;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	node = temp->content;
	temp = *stack_a;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	free(temp->next);
	add = ft_lstnew(node);
	if (!add)
		exit (-1);
	temp->next = NULL;
	temp = *stack_a;
	ft_lstadd_front(&(*stack_a), add);
	if (print == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b, int print)
{
	t_list	*temp;
	t_list	*add;
	int		node;

	temp = *stack_b;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	node = temp->content;
	temp = *stack_b;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	free(temp->next);
	add = ft_lstnew(node);
	if (!add)
		exit (-1);
	temp->next = NULL;
	temp = *stack_b;
	ft_lstadd_front(&(*stack_b), add);
	if (print == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(&(*stack_a), -1);
	rrb(&(*stack_b), -1);
	write(1, "rrr\n", 4);
}
