/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:50:38 by wpepping          #+#    #+#             */
/*   Updated: 2024/07/09 19:47:20 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandel(t_fractol data, double complex c, char *result)
{
	double complex	z;
	int				i;

	z = 0;
	i = -1;
	while (cabs(z) <= 2 && ++i < MAX_ITERATIONS)
		z = z * z + c;
	if (cabs(z) <= 2)
		get_color(data, (int []){0, 0, 0}, result);
	else if (i < 16)
		get_color(data, (int []){50, 100 + 100 * i / 10, 255}, result);
	else if (i > 35)
		get_color(data, (int []){255, 255, 0}, result);
	else
		get_color(data, (int []){255, 255, 255}, result);
}
