/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:30:42 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/21 17:39:10 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	absolute_value(t_complex number)
{
	return (sqrt(pow(number.real, 2) + pow(number.im, 2)));
}

t_complex	multiply_t_complex(t_complex a, t_complex b)
{
	t_complex	result;

	result.real = a.real * b.real - a.im * b.im;
	result.im = a.real * b.im + a.im * b.real;
	return (result);
}

t_complex	add_two_number(t_complex a, t_complex b)
{
	t_complex	result;

	result.real = a.real + b.real;
	result.im = a.im + b.im;
	return (result);
}
