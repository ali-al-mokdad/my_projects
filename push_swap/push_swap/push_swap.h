/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:52:11 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/08/11 17:04:22 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define    PUSH_SWAP_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
}	t_stack_node;

void			push_swap(char *str);
int				main(int argc, char **argv);
int				*push_swap_atoi(const char *nptr, int *count);
int				ft_issigne(int c);
int				count_numbers(const char *nptr);
int				parse_number(const char **p, int *result, int *sign);
void			parse_numbers(const char *nptr, int *array);
int				check_double(int *all_numb, int count);
void			push_swapcases(int *all_numb, int count);
void			general_case(int *all_numb, int count);
void			case2(int *all_numb);
void			case3(int *all_numb);
void			init_stack_a(t_stack_node **a, int	*all_numb, int count);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **b, t_stack_node **a);
void			pa(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
void			push(t_stack_node **dest, t_stack_node	**src);
void			fix_index(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node	*stack);
void			rotate(t_stack_node **stack);
void			free_stack(t_stack_node *stack);
void			reverse(t_stack_node **stack);
void			init_stack_b(t_stack_node **b);

#endif