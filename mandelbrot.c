/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:50:38 by wpepping          #+#    #+#             */
/*   Updated: 2024/07/01 17:56:54 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandel(double complex c)
{
	double complex	z;
	int				i;
	int				brightness;

	z = 0;
	i = -1;
	while (cabs(z) <= 2 && ++i < MAX_ITERATIONS)
		z = z * z + c;
	if (cabs(z) <= 2)
		return (get_color(0, 0, 0));
	brightness = fmin(255, 255 * i / 40);
	return (get_color(brightness, brightness, brightness));
}
