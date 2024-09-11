/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_u2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:48:44 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/09/11 12:28:29 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	process_map(t_vars *vars, int x, int y, t_iso *iso)
{
	iso->x = x;
	iso->y = y;
	iso->z = vars->map[y][x];
	iso_projection(iso, vars);
}

void	draw_map_lines(t_vars *vars, t_iso *iso, int x, int y)
{
	int	start_x;
	int	start_y;

	start_x = iso->iso_x1;
	start_y = iso->iso_y1;
	if (x < vars->x - 1)
	{
		iso->x = x + 1;
		iso->y = y;
		iso->z = vars->map[y][x + 1];
		iso_projection(iso, vars);
		draw_line(vars, &(t_iso){.iso_x1 = start_x, .iso_y1 = start_y,
			.iso_x2 = iso->iso_x1, .iso_y2 = iso->iso_y1}, 0xFFFFFF);
	}
	if (y < vars->y - 1)
	{
		iso->x = x;
		iso->y = y + 1;
		iso->z = vars->map[y + 1][x];
		iso_projection(iso, vars);
		draw_line(vars, &(t_iso){.iso_x1 = start_x, .iso_y1 = start_y,
			.iso_x2 = iso->iso_x1, .iso_y2 = iso->iso_y1}, 0xFFFFFF);
	}
}

void	process_rows(t_vars *vars, t_iso *iso, int y)
{
	int	x;

	x = 0;
	while (x < vars->x)
	{
		process_map(vars, x, y, iso);
		draw_map_lines(vars, iso, x, y);
		x++;
	}
}

int	draw_map(t_vars *vars)
{
	t_iso	*iso;
	int		y;

	iso = calloc(1, sizeof(t_iso));
	if (!iso)
		return (-1);
	y = 0;
	while (y < vars->y)
	{
		process_rows(vars, iso, y);
		y++;
	}
	free(iso);
	return (0);
}
