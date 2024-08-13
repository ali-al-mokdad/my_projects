/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:01:44 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/08/13 20:21:57 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*tinysort(t_stack_node *a)
{
	t_stack_node	*biggest;

	biggest = find_biggest(a);
	if (a->nbr == biggest->nbr)
		ra(&a);
	else if (a->next->nbr == biggest->nbr)
		rra(&a);
	if (a->nbr > a->next->nbr)
		sa(&a);
	return (a);
}

void	bring_on_top(t_stack_node **stack,
t_stack_node *desired_node, char stack_name)
{
	while (*stack != desired_node)
	{
		if (desired_node->above_median)
		{
			if (stack_name == 'a')
				ra(stack);
			else
				rb(stack);
		}
		else
		{
			if (stack_name == 'a')
				rra(stack);
			else
				rrb(stack);
		}
	}
}

t_stack_node	*push_swap_algo(t_stack_node *a, t_stack_node *b, int size_a)
{
	if (size_a-- > 3 && !sorted(a))
		pb(&a, &b);
	if (size_a-- > 3 && !sorted(a))
		pb(&a, &b);
	while (size_a-- > 3 && !sorted(a))
	{
		init_node_a(&a, &b);
		move_a_to_b(&a, &b);
	}
	a = tinysort(a);
	while (b)
	{
		init_node_b(&a, &b);
		move_b_to_a(&a, &b);
	}
	current_index(a);
	while (a->nbr != find_smallest(a)->nbr)
	{
		if (find_smallest(a)->above_median)
			ra(&a);
		else
			rra(&a);
	}
	return (a);
}
