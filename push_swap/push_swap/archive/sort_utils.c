/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:47:13 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/08/13 19:56:54 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

int	stack_size(t_stack_node *a)
{
	t_stack_node	*temp;
	int				size;

	size = 0;
	temp = a;
	while (a != NULL)
	{
		a = a->next;
		size++;
	}
	a = temp;
	return (size);
}

t_stack_node	*find_smallest(t_stack_node *stack)
{
	t_stack_node	*min;
	t_stack_node	*temp;

	min = stack;
	temp = stack;
	while (stack != NULL)
	{
		if (min->nbr > stack->nbr)
			min = stack;
		stack = stack->next;
	}
	stack = temp;
	return (min);
}

t_stack_node	*find_biggest(t_stack_node *stack)
{
	t_stack_node	*max;
	t_stack_node	*temp;

	max = stack;
	temp = stack;
	while (stack != NULL)
	{
		if (max->nbr < stack->nbr)
			max = stack;
		stack = stack->next;
	}
	stack = temp;
	return (max);
}

int	sorted(t_stack_node *a)
{
	while (a != NULL)
	{
		if (a->nbr > a->next->nbr)
			return (0);
		a = a->next;
	}
	return (1);
}

void	sort(t_stack_node *a, t_stack_node *b)
{
	int	size_a;

	size_a = stack_size(a);
	if (size_a == 2 || size_a == 3)
		a = tinysort(a);
	else
		a = push_swap_algo(a, b, size_a);
	free_stack(a);
}
