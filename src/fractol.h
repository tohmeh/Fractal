/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:53:43 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/22 18:27:09 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <X11/Xlib.h>
# include "../LIBFT/include/LIBFT.h"

# define WIDTH 800
# define HEIGHT 600
# define MAX_ITER 1000

# define DEFAULT_XMIN -2
# define DEFAULT_XMAX 1
# define DEFAULT_YMIN -1.5
# define DEFAULT_YMAX 1.5

# define TRUE 1
# define FALSE 0
# define BOOL int

# define COLOR_RESET "\033[0m"
# define COLOR_BLUE "\033[34m"
# define COLOR_GREEN "\033[32m"
# define COLOR_YELLOW "\033[33m"
# define COLOR_RED "\033[31m"
# define COLOR_RESET "\033[0m"
# define COLOR_BRIGHT_BLUE "\033[94m"
# define COLOR_BRIGHT_GREEN "\033[92m"
# define COLOR_BRIGHT_YELLOW "\033[93m"
# define COLOR_BRIGHT_RED "\033[91m"
# define COLOR_BRIGHT_CYAN "\033[96m"
# define COLOR_BRIGHT_MAGENTA "\033[95m"
# define COLOR_BRIGHT_WHITE "\033[97m"
# define COLOR_DARK_GREY "\033[90m"
# define COLOR_LIGHT_GREY "\033[37m"

typedef struct t_complex{
	double	real;
	double	im;
}		t_complex;

typedef struct s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			x_zoom_factor;
	int			y_zoom_factor;
	t_complex	c;
}	t_data;

typedef struct t_fractal{
	void	*mlx_ptr;
	void	*window_ptr;
	t_data	img;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	double	zoom_effect;
	int		mouse_press;
	int		mouse_move;
	int		last_x_move;
	int		last_y_move;
	int		index;
	int		max_iterations;
}	t_fractal;

typedef struct variables
{
	int		i;
	int		j;
}	t_var;

typedef struct scales
{
	double	x_scale;
	double	y_scale;
}	t_scales;

typedef struct squared
{
	double		z_real_squared;
	double		z_imag_squared;
}	t_squared;
//complex 
double		absolute_value(t_complex number);
t_complex	multiply_t_complex(t_complex a, t_complex b);
t_complex	add_two_number(t_complex a, t_complex b);

//draw
void		ft_put_pixel(t_data *data, int x, int y, int color);

//main function utils
int			exit_program(t_fractal *fract);
void		handle_mandelbrot(t_fractal *fract);
void		handle_julia(t_fractal *fract, char *real_str, char *im_str);
void		print_usage_if_needed(int argc);

//initialise fractal struct
void		initialize_fractal(t_fractal *fract, int width, int hght, int idx);

//parsing input
double		parse_integer_part(const char *str, int *i, BOOL *is_negative);
double		parse_fractional_part(const char *str, int i);
double		string_to_double(const char *str);
BOOL		is_valid_number(const char *str);
void		print_usage(void);

//julia set 
int			belong_to_julia(t_complex z, t_complex c, int max_iterations);
int			get_color(int iteration, int max_iterations);
void		draw_julia_set(t_data *data, t_fractal *fract, int max_itrs);

//mandelbrot set 
void		draw_mandelbrot(t_data *data, t_fractal *fract, int max_itrs);
int			belong_to_mandelbrot(t_complex c, int max_iterations);

//mnk events 
void		setup_hooks(t_fractal *fract);
int			key_function(int keycode, t_fractal *fract);
int			mouse_press(int button, int x, int y, t_fractal *fract);
int			mouse_release(int button, int x, int y, t_fractal *fract);
int			mouse_move(int x, int y, t_fractal *fract);

//mnk events utils
void		calculate_zoom(t_fractal *fract, int indicator);
void		zoom(t_fractal *fract, int indicator);
void		move_julia(t_fractal *fract, double real_offset, double im_offset);
void		change_iterations(t_fractal *fract, int increment);
void		move_fractal(t_fractal *fract, int x, int y);
void		redraw_fractal(t_fractal *fract);

#endif
