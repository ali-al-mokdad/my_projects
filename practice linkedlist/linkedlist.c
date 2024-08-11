/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:10:49 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/07/31 14:20:28 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct s_node
{
	int				n;
	struct s_node	*next;
}	t_node;

int	main()
{
	t_node	*root;
	t_node	*current;

	root = malloc(sizeof(t_node));
	root->next = malloc(sizeof(t_node));
	root->next->next = malloc(sizeof(t_node));

	root->n = 42;
	root->next->n = 1337;
	root->next->next->n = 21;
	root->next->next->next = NULL;

	current = root;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}