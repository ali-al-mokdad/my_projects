/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_next1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:14:25 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/08/13 19:00:58 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	general_case(int *all_numb, int count)
{
	t_stack_node	*a;
	t_stack_node	*b;
	t_stack_node	*temp;

	init_stack_a(&a, all_numb, count);
	init_stack_b(&b);
	a = push_swap_algo(a, b, count);
	free_stack(b);
	free_stack(a);
}

void	init_stack_a(t_stack_node **a, int	*all_numb, int count)
{
	int				i;
	t_stack_node	*current;
	t_stack_node	*new_node;

	*a = malloc(sizeof(t_stack_node));
	if (*a == NULL)
		exit (-1);
	(*a)->nbr = all_numb[0];
	(*a)->index = 0;
	(*a)->next = NULL;
	i = 1;
	current = *a;
	while (i < count)
	{
		new_node = malloc(sizeof(t_stack_node));
		if (new_node == NULL)
			exit (-1);
		new_node->nbr = all_numb[i];
		new_node->index = i;
		new_node->next = NULL;
		current->next = new_node;
		current = new_node;
		i++;
	}
}

void	init_stack_b(t_stack_node **b)
{
	*b = malloc(sizeof(t_stack_node));
	(*b)->next = NULL;
}

