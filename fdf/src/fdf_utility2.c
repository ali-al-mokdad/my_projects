/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utility2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:51:41 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/09/07 14:09:53 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso_projection(t_iso *iso, t_vars *vars)
{
	int zoom = vars->zoom;
	iso->iso_x1 = (iso->x - iso->y) * zoom + 600;
	iso->iso_y1 = (iso->x + iso->y) * zoom - vars->zoom * zoom / 2 + 750;
}

void mlx_line(t_vars *vars, t_iso *iso, int color)
{
	int dx = abs(iso->iso_x2 - iso->iso_x1);
	int dy = abs(iso->iso_y2 - iso->iso_y1);
	int sx = (iso->iso_x1 < iso->iso_x2) ? 1 : -1;
	int sy = (iso->iso_y1 < iso->iso_y2) ? 1 : -1;
	int err = dx - dy;

	while (1)
	{
		my_mlx_pixel_put(vars, iso->iso_x1, iso->iso_y1, color);
		if (iso->iso_x1 == iso->iso_x2 && iso->iso_y1 == iso->iso_y2)
			break;
		int e2 = err * 2;
		if (e2 > -dy)
		{
			err -= dy;
			iso->iso_x1 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			iso->iso_y1 += sy;
		}
    }
}

int draw_map(t_vars *vars)
{
	t_iso *iso;
	int x, y;

	iso = calloc(1, sizeof(t_iso));
	if (!iso)
		return (-1);

	for (y = 0; y < vars->y; ++y)
	{
		for (x = 0; x < vars->x; ++x)
		{
			// Set the current point
			iso->x = x;
			iso->y = y;
			iso->z = vars->map[y][x];
			iso_projection(iso, vars);
			int start_x = iso->iso_x1;
			int start_y = iso->iso_y1;

			// Draw horizontal line
			if (x < vars->x - 1)
			{
				iso->x = x + 1;
				iso->y = y;
				iso->z = vars->map[y][x + 1];
				iso_projection(iso, vars);
				mlx_line(vars, &(t_iso){.iso_x1 = start_x, .iso_y1 = start_y,
										.iso_x2 = iso->iso_x1, .iso_y2 = iso->iso_y1}, 0xFFFFFF);
			}

			// Draw vertical line
			if (y < vars->y - 1)
			{
				iso->x = x;
				iso->y = y + 1;
				iso->z = vars->map[y + 1][x];
				iso_projection(iso, vars);
				mlx_line(vars, &(t_iso){.iso_x1 = start_x, .iso_y1 = start_y,
										.iso_x2 = iso->iso_x1, .iso_y2 = iso->iso_y1}, 0xFFFFFF);
			}
		}
	}

	free(iso);
	return (0);
}
