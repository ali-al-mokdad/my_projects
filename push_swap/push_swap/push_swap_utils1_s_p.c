/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1_s_p.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:24:18 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/08/13 20:32:00 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack_node **a)
{
	int	temp;

	temp = (*a)->nbr;
	(*a)->nbr = (*a)->next->nbr;
	(*a)->next->nbr = temp;
	ft_printf("sa\n");
}

void	sb(t_stack_node **b)
{
	int	temp;

	temp = (*b)->nbr;
	(*b)->nbr = (*b)->next->nbr;
	(*b)->next->nbr = temp;
	ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	sa(a);
	sb(b);
	ft_printf("ss\n");
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	push(b, a);
	ft_printf("pa\n");
}

void	pb(t_stack_node **b, t_stack_node **a)
{
	push(a, b);
	ft_printf("pb\n");
}
