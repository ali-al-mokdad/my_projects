/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_u3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:16:59 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/09/11 12:28:38 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map_rows(t_vars *vars)
{
	int	i;

	i = 0;
	if (vars->map)
	{
		while (i < vars->y)
		{
			if (vars->map[i])
				free(vars->map[i]);
			i++;
		}
		free(vars->map);
	}
}

void	free_structs(t_vars *vars)
{
	if (vars)
	{
		free_map_rows(vars);
		free(vars->mlx);
		free(vars);
	}
}

void	allocate_row_memory(t_vars *vars)
{
	vars->map[vars->y] = malloc(sizeof(int) * vars->x);
	if (!vars->map[vars->y])
	{
		perror("Error allocating memory for row");
		exit(EXIT_FAILURE);
	}
}
