/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:50:38 by wpepping          #+#    #+#             */
/*   Updated: 2024/07/13 15:30:12 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandel(t_fractol *data, t_complex c, char *result)
{
	t_complex	z;
	int			i;

	z.real = 0;
	z.imag = 0;
	i = -1;
	while (c_abs_square(z) <= R_SQ && ++i < MAX_ITERATIONS)
		z = c_add(c_square(z), c);
	if (c_abs_square(z) <= R_SQ)
		get_color(data, (int []){0, 0, 0}, result);
	else if (i < 16)
		get_color(data, (int []){10 * i, 10 * i, 60 + i * 10}, result);
	else if (i > 35)
		get_color(data, (int []){255, 255, 0}, result);
	else
		get_color(data, (int []){255, 255, 255}, result);
}
