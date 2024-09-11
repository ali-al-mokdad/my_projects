/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:47:39 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/09/11 12:15:08 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	mlx_pixel_put(vars->mlx, vars->win, x, y, color);
}

int	handle_key_press(int Keycode, t_vars *vars)
{
	if (Keycode == XK_Escape)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free_structs(vars);
		exit(0);
	}
	if (Keycode == XK_equal)
	{
		if (vars->zoom < 20)
			vars->zoom += 1;
		mlx_clear_window(vars->mlx, vars->win);
		draw_map(vars);
	}
	if (Keycode == XK_minus)
	{
		if (vars->zoom >= 2)
			vars->zoom -= 1;
		else if (vars->zoom != 1 && vars->zoom > 0.9)
			vars->zoom *= 1;
		mlx_clear_window(vars->mlx, vars->win);
		draw_map(vars);
	}
	return (0);
}

int	handle_mouse_click(int button, int x, int y, t_vars *vars)
{
	if (button == Button1)
		printf("Mouse click at (%d, %d)\n", x, y);
	if (x == 0 && y == 500)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	handle_destroy_notify(void *param, t_vars *vars)
{
	(void)param;
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free_structs(vars);
	free(vars->mlx);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	*vars;

	if (argc != 2)
		exit (-1);
	vars = calloc(1, sizeof(t_vars));
	read_map(argv[1], vars);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1920, 1080, "fdf");
	vars->zoom = 1;
	mlx_hook(vars->win, KeyPress, KeyPressMask, handle_key_press, vars);
	mlx_hook(vars->win, ButtonPress, ButtonPressMask, handle_mouse_click, vars);
	mlx_hook(vars->win, DestroyNotify, StructureNotifyMask,
		handle_destroy_notify, vars);
	mlx_expose_hook(vars->win, draw_map, vars);
	mlx_loop(vars->mlx);
	return (0);
}
