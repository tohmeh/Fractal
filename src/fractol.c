/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:56:29 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/22 18:12:27 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_program(t_fractal *fract)
{
	mlx_destroy_image(fract->mlx_ptr, fract->img.img);
	mlx_destroy_window(fract->mlx_ptr, fract->window_ptr);
	mlx_destroy_display(fract->mlx_ptr);
	free(fract->mlx_ptr);
	exit (0);
}

void	handle_mandelbrot(t_fractal *fract)
{
	initialize_fractal(fract, WIDTH, HEIGHT, 1);
	draw_mandelbrot(&fract->img, fract, fract->max_iterations);
	setup_hooks(fract);
}

void	handle_julia(t_fractal *fract, char *real_str, char *im_str)
{
	if (!is_valid_number(real_str) || !is_valid_number(im_str))
	{
		ft_printf("input error\n");
		return ;
	}
	fract->img.c.im = string_to_double(im_str);
	fract->img.c.real = string_to_double(real_str);
	if (abs((int)fract->img.c.im) >= 3 || abs((int)fract->img.c.real) >= 3)
	{
		ft_printf("this c number is bigger than it should be preferable");
		ft_printf(" to have real and imaginary parts less than 3\n");
		return ;
	}
	initialize_fractal(fract, WIDTH, HEIGHT, 2);
	fract->x_min = -2.0;
	fract->x_max = 2.0;
	fract->y_min = -2.0;
	fract->y_max = 2.0;
	draw_julia_set(&fract->img, fract, fract->max_iterations);
	setup_hooks(fract);
}

void	print_usage_if_needed(int argc)
{
	if (argc == 1)
	{
		print_usage();
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_fractal	fract;

	print_usage_if_needed(argc);
	if (argc == 2 && ft_strncmp(argv[1], "1",
			ft_strlen(argv[1])) == 0 && ft_strlen(argv[1]) == 1)
		handle_mandelbrot(&fract);
	else if (argc == 4 && argv[1][0] == '2' && ft_strlen(argv[1]) == 1)
		handle_julia(&fract, argv[2], argv[3]);
	else
	{
		ft_printf("input error\n");
		return (0);
	}
	return (0);
}
