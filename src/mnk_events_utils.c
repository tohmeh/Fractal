/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mnk_events_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:05:07 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/22 15:33:13 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_zoom(t_fractal *fract, int indicator)
{
	double	x_center;
	double	y_center;
	double	x_range;
	double	y_range;

	x_center = (fract->x_min + fract->x_max) / 2.0;
	y_center = (fract->y_min + fract->y_max) / 2.0;
	x_range = (fract->x_max - fract->x_min);
	y_range = (fract->y_max - fract->y_min);
	if (indicator == 1)
	{
		x_range *= 0.95;
		y_range *= 0.95;
	}
	else if (indicator == 2)
	{
		x_range *= 1.05;
		y_range *= 1.05;
	}
	fract->x_min = x_center - x_range / 2.0;
	fract->x_max = x_center + x_range / 2.0;
	fract->y_min = y_center - y_range / 2.0;
	fract->y_max = y_center + y_range / 2.0;
}

void	zoom(t_fractal *fract, int indicator)
{
	calculate_zoom(fract, indicator);
	if (fract->index == 1)
		draw_mandelbrot(&fract->img, fract, fract->max_iterations);
	else
		draw_julia_set(&fract->img, fract, fract->max_iterations);
	mlx_put_image_to_window(fract->mlx_ptr,
		fract->window_ptr, fract->img.img, 0, 0);
}

void	move_julia(t_fractal *fract, double real_offset, double im_offset)
{
	fract->img.c.real += real_offset;
	fract->img.c.im += im_offset;
	draw_julia_set(&fract->img, fract, fract->max_iterations);
	mlx_put_image_to_window(fract->mlx_ptr, fract->window_ptr,
		fract->img.img, 0, 0);
}

void	change_iterations(t_fractal *fract, int increment)
{
	fract->max_iterations += increment;
	if (fract->index == 2)
		draw_julia_set(&fract->img, fract, fract->max_iterations);
	else if (fract->index == 1)
		draw_mandelbrot(&fract->img, fract, fract->max_iterations);
	mlx_put_image_to_window(fract->mlx_ptr, fract->window_ptr,
		fract->img.img, 0, 0);
}
