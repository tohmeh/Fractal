/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_fractal_struct.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:53:35 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/22 17:54:23 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialize_fractal(t_fractal *fract, int width, int height, int index)
{
	fract->mlx_ptr = mlx_init();
	if (fract->mlx_ptr == NULL)
		exit(1);
	fract->window_ptr = mlx_new_window(fract->mlx_ptr, width,
			height, "fractal");
	if (fract->window_ptr == NULL)
	{
		mlx_destroy_display(fract->mlx_ptr);
		free(fract->mlx_ptr);
		exit(1);
	}
	fract->img.img = mlx_new_image(fract->mlx_ptr, width, height);
	fract->img.addr = mlx_get_data_addr(fract->img.img,
			&fract->img.bits_per_pixel,
			&fract->img.line_length, &fract->img.endian);
	fract->x_min = DEFAULT_XMIN;
	fract->x_max = DEFAULT_XMAX;
	fract->y_min = DEFAULT_YMIN;
	fract->y_max = DEFAULT_YMAX;
	fract->zoom_effect = 1;
	fract->max_iterations = 50;
	fract->index = index;
	fract->last_x_move = 0;
	fract->last_y_move = 0;
	fract->mouse_press = 0;
}
