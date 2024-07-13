/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crimage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:38:33 by wpepping          #+#    #+#             */
/*   Updated: 2024/07/13 22:51:01 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_color(t_fractol *data, int c[3], char *result)
{
	int	color;

	color = (c[0] * 256 * 256 + c[1] * 256 + c[2]);
	color = mlx_get_color_value(data->mlx, color);
	ft_memcpy(result, &color, 4);
}

double	pix2val(t_fractol *data, double n, int xy)
{
	if (xy == 0)
		return ((n - (0.5 * X)) / X * SCALE * 2 * data->zoom
			- data->offset_x);
	return (((0.5 * Y) - n) / Y * SCALE * 2 * data->zoom
		- data->offset_y);
}

void	crimage(t_fractol *data, void (*f)(t_fractol *f, t_complex, char *r))
{
	t_xy	xy;

	xy.x_inc = 4.0 * data->zoom / X;
	xy.y_inc = 4.0 * data->zoom / Y;
	xy.x_pix = 0;
	xy.x = pix2val(data, 0, 0);
	xy.y_start = pix2val(data, 0, 1);
	while (xy.x_pix < X)
	{
		xy.y_pix = 0;
		xy.y = xy.y_start;
		while (xy.y_pix < Y)
		{
			(*f)(data, (t_complex){xy.x, xy.y},
				data->imgbuff + (xy.y_pix * data->lsize + xy.x_pix * 4));
			xy.y_pix++;
			xy.y -= xy.y_inc;
		}
		xy.x_pix++;
		xy.x += xy.x_inc;
	}
}
