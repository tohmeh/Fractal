/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:02:25 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/22 14:48:23 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_mandelbrot(t_data *data, t_fractal *fract, int max_itrs)
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
		t_complex	c;
		int			itrs;

		for (j = 0; j < HEIGHT; j++)
		{
			c.real = fract->x_min + i * x_scale;
			c.im = fract->y_min + j * y_scale;
			itrs = belong_to_mandelbrot(c, max_itrs);
			if (itrs < max_itrs)
				ft_put_pixel(data, i, j,
					(0xA0E7FF - 0xE0F7FF) * itrs / HEIGHT + 0xE0F7FF);
			else
				ft_put_pixel(data, i, j, 0xA0FFCC);
		}
	}
}

int	belong_to_mandelbrot(t_complex c, int max_iterations)
{
	double		p;
	t_complex	z;
	t_var		var;
	t_squared	z_sq;

	p = sqrt((c.real - 0.25) * (c.real - 0.25) + c.im * c.im);
	if (c.real <= p - 2 * p * p + 0.25)
		return (max_iterations);
	if ((c.real + 1) * (c.real + 1) + c.im * c.im <= 0.0625)
		return (max_iterations);
	z.real = 0;
	z.im = 0;
	var.i = -1;
	while (++var.i < max_iterations)
	{
		z_sq.z_real_squared = z.real * z.real;
		z_sq.z_imag_squared = z.im * z.im;
		if (z_sq.z_real_squared + z_sq.z_imag_squared > 4.0)
			return (var.i);
		z.im = 2 * z.real * z.im + c.im;
		z.real = z_sq.z_real_squared - z_sq.z_imag_squared + c.real;
		if (c.im == 0 && z.im != 0)
			break ;
	}
	return (max_iterations);
}
