/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mnk_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:03:51 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/22 18:09:08 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	setup_hooks(t_fractal *fract)
{
	mlx_put_image_to_window(fract->mlx_ptr, fract->window_ptr,
		fract->img.img, 0, 0);
	mlx_hook(fract->window_ptr, 17, 1L << 0,
		(int (*)(void *))exit_program, fract);
	mlx_key_hook(fract->window_ptr,
		(int (*)(int, void *))key_function, fract);
	mlx_mouse_hook(fract->window_ptr, mouse_press, fract);
	mlx_hook(fract->window_ptr, 6, PointerMotionMask, mouse_move, fract);
	mlx_hook(fract->window_ptr, 5, 1L << 3, mouse_release, fract);
	mlx_loop(fract->mlx_ptr);
}

int	key_function(int keycode, t_fractal *fract)
{
	if (keycode == 65307)
		exit_program(fract);
	if (keycode == 65361 && fract->index == 2)
		move_julia(fract, -0.003, -0.003);
	if (keycode == 65363 && fract->index == 2)
		move_julia(fract, 0.003, 0.003);
	if (keycode == 65362)
		change_iterations(fract, 1);
	if (keycode == 65364)
		change_iterations(fract, -1);
	return (0);
}

int	mouse_press(int button, int x, int y, t_fractal *fract)
{
	if (button == 1)
	{
		fract->mouse_press = 1;
		fract->last_x_move = x;
		fract->last_y_move = y;
	}
	else if (button == 4)
	{
		zoom(fract, 1);
	}
	else if (button == 5)
	{
		zoom(fract, 2);
	}
	return (0);
}

int	mouse_release(int button, int x, int y, t_fractal *fract)
{
	(void)x;
	(void)y;
	(void)fract;
	if (button == 1)
	{
		fract->mouse_press = 0;
	}
	return (0);
}

int	mouse_move(int x, int y, t_fractal *fract)
{
	static int	count = 0;

	if (!fract->mouse_press)
		return (0);
	if (count >= 3)
	{
		move_fractal(fract, x, y);
		redraw_fractal(fract);
		count = 0;
	}
	count++;
	return (0);
}
