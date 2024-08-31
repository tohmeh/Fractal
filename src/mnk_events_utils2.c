/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mnk_events_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:12:38 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/22 15:14:49 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_fractal(t_fractal *fract, int x, int y)
{
	double	x_range;
	double	y_range;
	double	x_shift;
	double	y_shift;

	x_range = fract->x_max - fract->x_min;
	y_range = fract->y_max - fract->y_min;
	x_shift = (x - fract->last_x_move) * x_range / WIDTH;
	y_shift = (y - fract->last_y_move) * y_range / HEIGHT;
	fract->x_min -= x_shift;
	fract->x_max -= x_shift;
	fract->y_min -= y_shift;
	fract->y_max -= y_shift;
	fract->last_x_move = x;
	fract->last_y_move = y;
}

void	redraw_fractal(t_fractal *fract)
{
	if (fract->index == 1)
		draw_mandelbrot(&fract->img, fract, fract->max_iterations);
	else
		draw_julia_set(&fract->img, fract, fract->max_iterations);
	mlx_put_image_to_window(fract->mlx_ptr,
		fract->window_ptr, fract->img.img, 0, 0);
}
