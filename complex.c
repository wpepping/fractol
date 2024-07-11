/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:17:35 by wpepping          #+#    #+#             */
/*   Updated: 2024/07/11 13:06:11 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	c_real(t_complex c)
{
	return (c.real);
}

double	c_imag(t_complex c)
{
	return (c.imag);
}

double	c_abs_square(t_complex c)
{
	return (c.real * c.real + c.imag * c.imag);
}

t_complex	c_square(t_complex c)
{
	return ((t_complex){c.real * c.real - c.imag * c.imag,
		2 * c.real * c.imag});
}

t_complex	c_add(t_complex c, t_complex d)
{
	return ((t_complex){c.real + d.real, c.imag + d.imag});
}
