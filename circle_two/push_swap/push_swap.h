/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:06:19 by ecaliska          #+#    #+#             */
/*   Updated: 2023/11/18 21:23:07 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	sa(t_list *head);
void	sb(t_list *head);
void	ss(t_list *stack_a, t_list *stack_b);
void	ra(t_list **stack_a, int print);
void	rb(t_list **stack_b, int print);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **head, int print);
void	rrb(t_list **head, int print);
void	rrr(t_list **stack_a, t_list **stack_b);
void	pushmin(t_list **stack_a, t_list **stack_b);
void	sorttwo(t_list **stack_a);
void	sortthree(t_list **stack_a);
void	sortfour(t_list **stack_a, t_list **stack_b);
void	sortfive(t_list **stack_a, t_list **stack_b);
void	error_checker(int check, t_list **stack);
void	sorter(t_list **stack);
void	swap(int *a, int *b);
void	fill_list(t_list **stack_a, int arg_count, char **arg_vect);
t_list	*copy_list(t_list *stack);
void	smaller_five(t_list **stack_a, t_list **stack_b);
void	sorting_algorithm(t_list **stack_a, t_list **stack_b);
void	get_index(t_list *stack_a, t_list *sorted);
int		is_sorted(t_list *stack);
void	freeall(t_list **lst);
int		hasdouble(t_list *head);
int		getpos(t_list *stack, int nbr);

#endif