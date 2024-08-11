/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:56:11 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/08/11 14:57:55 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fix_index(t_stack_node *stack)
{
	t_stack_node	*current;
	int				i;

	i = 0;
	current = stack;
	while (current)
	{
		current->index = i;
		i++;
		current = current->next;
	}
}

void	push(t_stack_node **dest, t_stack_node	**src)
{
	(*src)->next = (*dest);
	fix_index(*dest);
	fix_index(*src);
}
