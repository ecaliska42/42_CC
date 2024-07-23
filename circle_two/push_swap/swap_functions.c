/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:54:30 by ecaliska          #+#    #+#             */
/*   Updated: 2023/11/18 21:17:46 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *head)
{
	if (!head || ft_lstsize(head) < 2)
		return ;
	swap(&head->content, &head->next->content);
	write(1, "sa\n", 3);
}

void	sb(t_list *head)
{
	if (!head || ft_lstsize(head) < 2)
		return ;
	swap(&head->content, &head->next->content);
	write(1, "sb\n", 3);
}

static void	swpa(t_list *head)
{
	if (!head || ft_lstsize(head) < 2)
		return ;
	swap(&head->content, &head->next->content);
}

static void	swpb(t_list *head)
{
	if (!head || ft_lstsize(head) < 2)
		return ;
	swap(&head->content, &head->next->content);
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	swpa(stack_a);
	swpb(stack_b);
	write(1, "ss\n", 3);
}
