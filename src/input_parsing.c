/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:30:03 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/22 17:52:36 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	parse_integer_part(const char *str, int *i, BOOL *is_negative)
{
	double	result;

	result = 0.0;
	if (str[*i] == '-')
	{
		*is_negative = TRUE;
		(*i)++;
	}
	else if (str[*i] == '+')
		(*i)++;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		result = result * 10.0 + (str[*i] - '0');
		(*i)++;
	}
	return (result);
}

double	parse_fractional_part(const char *str, int i)
{
	double	fractional_part;
	double	divisor_for_fraction;

	fractional_part = 0.0;
	divisor_for_fraction = 1.0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		fractional_part = fractional_part * 10.0 + (str[i] - '0');
		divisor_for_fraction *= 10.0;
		i++;
	}
	return (fractional_part / divisor_for_fraction);
}

double	string_to_double(const char *str)
{
	BOOL	is_negative;
	double	result;
	int		i;

	is_negative = FALSE;
	i = 0;
	result = parse_integer_part(str, &i, &is_negative);
	if (str[i] == '.')
	{
		i++;
		result += parse_fractional_part(str, i);
	}
	if (is_negative)
		result = -result;
	return (result);
}

BOOL	is_valid_number(const char *str)
{
	BOOL	has_decimal;
	BOOL	has_digit;

	has_decimal = FALSE;
	has_digit = FALSE;
	while (*str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (ft_isdigit(*str))
			has_digit = TRUE;
		else if (*str == '.')
		{
			if (has_decimal)
				return (FALSE);
			has_decimal = TRUE;
		}
		else
			return (FALSE);
		str++;
	}
	return (has_digit);
}

void	print_usage(void)
{
	ft_printf("\nUsage: \n");
	ft_printf(COLOR_BRIGHT_YELLOW "./fractol 1 " COLOR_LIGHT_GREY);
	ft_printf("-to display the Mandelbrot set\n" COLOR_RESET);
	ft_printf(COLOR_BRIGHT_YELLOW "./fractol \"2 a b\" " COLOR_LIGHT_GREY);
	ft_printf("-to display the Julia set, where 'a' and 'b' are double ");
	ft_printf("numbers defining the real and imaginary parts ");
	ft_printf("of the complex number 'c'\n\n" COLOR_RESET);
	ft_printf("Controls:\n");
	ft_printf(COLOR_BRIGHT_BLUE " - Mouse press and drag: " COLOR_LIGHT_GREY);
	ft_printf("Move around the image\n");
	ft_printf(COLOR_BRIGHT_BLUE " - Mouse wheel: " COLOR_LIGHT_GREY);
	ft_printf("Zoom in/out\n");
	ft_printf(COLOR_BRIGHT_BLUE " - Up/Down arrows: " COLOR_LIGHT_GREY);
	ft_printf("Adjust image quality (higher quality reduces performance)\n");
	ft_printf(COLOR_BRIGHT_BLUE " - Left/Right arrows: " COLOR_LIGHT_GREY);
	ft_printf("Adjust the 'c' complex number ");
	ft_printf("(Julia set only)\n\n" COLOR_RESET);
	ft_printf("Examples:\n");
	ft_printf(COLOR_BRIGHT_MAGENTA "./fractol 1 " COLOR_LIGHT_GREY);
	ft_printf("-Displays the Mandelbrot set\n" COLOR_RESET);
	ft_printf(COLOR_BRIGHT_MAGENTA "./fractol 2 -0.7 0.27015" COLOR_LIGHT_GREY);
	ft_printf("-Displays the Julia set with 'c' = ");
	ft_printf("-0.7 + 0.27015i\n\n" COLOR_RESET);
}
