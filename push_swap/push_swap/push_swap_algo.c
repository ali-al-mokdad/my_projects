/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 17:05:18 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/08/11 18:00:17 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo(t_stack_node **a, t_stack_node **b, int count)
{
	t_stack_node	*temp;
	t_stack_node	*current;

	pb(b, a);
	if (count > 3)
		pb(b, a);
	else
		sort_3(a, b);
	while (stack_size(a) != 3)
	{
		temp = check_cost_1(a, b);
		push_with_target_to_top(temp, b);
	}
	sort3(a, b);
	current = b;
	while (current)
	{
		temp = check_cost_2(a, temp->nbr);
		head_temp(a, temp);
		push_from_b(a, b);
	}
}
