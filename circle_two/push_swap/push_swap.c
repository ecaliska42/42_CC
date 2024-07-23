/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:29:25 by ecaliska          #+#    #+#             */
/*   Updated: 2024/04/28 13:00:12 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	smaller_five(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize((*stack_a)) == 2)
		sorttwo(&(*stack_a));
	else if (ft_lstsize((*stack_a)) == 3)
		sortthree(&(*stack_a));
	else if (ft_lstsize((*stack_a)) == 4)
		sortfour(&(*stack_a), &(*stack_b));
	else if (ft_lstsize((*stack_a)) == 5)
		sortfive(&(*stack_a), &(*stack_b));
	freeall(&(*stack_a));
	exit(0);
}

void	sorting_algorithm(t_list **stack_a, t_list **stack_b)
{
	int					len;
	unsigned long long	raiser;

	raiser = 0;
	while (is_sorted(*stack_a) == 0)
	{
		len = ft_lstsize(*stack_a);
		while (len--)
		{
			if ((*stack_a)->content >> raiser & 1)
				ra(&(*stack_a), 1);
			else
				pb(&(*stack_a), &(*stack_b));
		}
		while (*stack_b)
			pa(&(*stack_a), &(*stack_b));
		raiser++;
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*temp;

	error_checker(ac, NULL);
	stack_a = NULL;
	stack_b = NULL;
	fill_list(&stack_a, ac - 1, av);
	error_checker(hasdouble(stack_a), &stack_a);
	if (ft_lstsize(stack_a) <= 5)
		smaller_five(&stack_a, &stack_b);
	temp = copy_list(stack_a);
	if (!temp)
	{
		freeall(&stack_a);
		return (-1);
	}
	sorter(&temp);
	get_index(stack_a, temp);
	sorting_algorithm(&stack_a, &stack_b);
	freeall(&temp);
	freeall(&stack_a);
	temp = NULL;
	stack_a = NULL;
	return (0);
}
