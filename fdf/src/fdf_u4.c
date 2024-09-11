/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_u4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:21:41 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/09/11 12:28:52 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso_projection(t_iso *iso, t_vars *vars)
{
	int	zoom;

	zoom = vars->zoom;
	iso->iso_x1 = (iso->x - iso->y) * zoom + 1920 / 2;
	iso->iso_y1 = (iso->x + iso->y) * zoom - iso->z * zoom / 2 - 1 / 1000000;
}

void	initialize_line(t_line *line, t_iso *iso)
{
	line->dx = abs(iso->iso_x2 - iso->iso_x1);
	line->dy = abs(iso->iso_y2 - iso->iso_y1);
	if (iso->iso_x1 < iso->iso_x2)
	{
		line->sx = 1;
	}
	else
	{
		line->sx = -1;
	}
	if (iso->iso_y1 < iso->iso_y2)
	{
		line->sy = 1;
	}
	else
	{
		line->sy = -1;
	}
	line->err = line->dx - line->dy;
}

void	draw_line_segment(t_vars *vars, t_iso *iso, t_line *line, int color)
{
	int	e2;

	while (1)
	{
		my_mlx_pixel_put(vars, iso->iso_x1, iso->iso_y1, color);
		if (iso->iso_x1 == iso->iso_x2 && iso->iso_y1 == iso->iso_y2)
			break ;
		e2 = line->err * 2;
		if (e2 > -line->dy)
		{
			line->err -= line->dy;
			iso->iso_x1 += line->sx;
		}
		if (e2 < line->dx)
		{
			line->err += line->dx;
			iso->iso_y1 += line->sy;
		}
	}
}

void	draw_line(t_vars *vars, t_iso *iso, int color)
{
	t_line	line;

	initialize_line(&line, iso);
	draw_line_segment(vars, iso, &line, color);
}
