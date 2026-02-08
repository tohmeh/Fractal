/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:38:49 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/22 13:30:43 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define COLOR_SCALE 255

int	belong_to_julia(t_complex z, t_complex c, int max_iterations)
{
	double	z_real_squared;
	double	z_imag_squared;
	int		i;

	i = 0;
	while (i < max_iterations)
	{
		z_real_squared = z.real * z.real;
		z_imag_squared = z.im * z.im;
		if (z_real_squared + z_imag_squared > 4)
			return (i);
		z.im = 2 * z.real * z.im + c.im;
		z.real = z_real_squared - z_imag_squared + c.real;
		i++;
	}
	return (max_iterations);
}

int	get_color(int iteration, int max_iterations)
{
	double	t;
	int		red;
	int		green;
	int		blue;
	int		color;

	t = (double)iteration / (double)max_iterations;
	red = (int)(9 * (1 - t) * t * t * t * COLOR_SCALE);
	green = (int)(15 * (1 - t) * (1 - t) * t * t * COLOR_SCALE);
	blue = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * COLOR_SCALE);
	color = (red << 16) | (green << 8) | blue;
	return (color);
}

void	draw_julia_set(t_data *data, t_fractal *fract, int max_itrs)
{
	double	x_scale;
	double	y_scale;
	int		i;

	x_scale = (fract->x_max - fract->x_min) / WIDTH;
	y_scale = (fract->y_max - fract->y_min) / HEIGHT;
	#pragma omp parallel for schedule(dynamic, 4)
	for (i = 0; i < WIDTH; i++)
	{
		int			j;
		t_complex	z;
		int			itrs;

		for (j = 0; j < HEIGHT; j++)
		{
			z.real = fract->x_min + i * x_scale;
			z.im = fract->y_min + j * y_scale;
			itrs = belong_to_julia(z, data->c, max_itrs);
			if (itrs < max_itrs)
				ft_put_pixel(data, i, j, get_color(itrs, max_itrs));
			else
				ft_put_pixel(data, i, j, 0x0A67BC);
		}
	}
}
