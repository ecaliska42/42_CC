/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:09:21 by ecaliska          #+#    #+#             */
/*   Updated: 2023/11/22 16:07:14 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	error_checker(int check, t_list **stack)
{
	if (check == 1)
		exit(-1);
	else if (check == -1)
	{
		freeall(&(*stack));
		ft_putstr_fd("Error\n", 2);
		exit(-1);
	}
}

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sorter(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	while (temp->next != NULL)
	{
		if (temp->content > temp->next->content)
		{
			swap(&temp->content, &temp->next->content);
			temp = *stack;
		}
		else
			temp = temp->next;
	}
	temp = *stack;
}

void	fill_list(t_list **stack_a, int arg_count, char **arg_vect)
{
	t_list	*add_back;
	int		nb;
	int		i;

	i = 0;
	while (i < arg_count)
	{
		nb = ft_atoi(arg_vect [i + 1], &(*stack_a));
		add_back = ft_lstnew(nb);
		if (!add_back)
			freeall(&(*stack_a));
		ft_lstadd_back(&(*stack_a), add_back);
		i++;
	}
}

t_list	*copy_list(t_list *stack)
{
	t_list	*node;

	if (stack == NULL)
		return (NULL);
	else
	{
		node = malloc(sizeof(t_list));
		if (!node)
			return (NULL);
		node->content = stack->content;
		node->next = copy_list(stack->next);
	}
	return (node);
}
