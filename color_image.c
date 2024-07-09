/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:38:33 by wpepping          #+#    #+#             */
/*   Updated: 2024/07/09 19:48:16 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_image(t_fractol data, void (*f)(t_fractol f, double complex c, char *r))
{
	t_xy	coor;
	char	color[4];

	coor.x_inc = 4.0 * data.zoom / X;
	coor.y_inc = 4.0 * data.zoom / Y;
	coor.x_pix = 0;
	coor.x = (-1.0 * SCALE + data.offset_x) * data.zoom;
	coor.y_start = (-1.0 * SCALE + data.offset_y) * data.zoom;
	while (coor.x_pix < X)
	{
		coor.y_pix = 0;
		coor.y = coor.y_start;
		while (coor.y_pix < Y)
		{
			(*f)(data, coor.x + coor.y * _Complex_I,
				color);
			ft_memcpy(data.imgbuff + ((coor.y_pix * X + coor.x_pix) * 4),
				color, 4);
			coor.y_pix++;
			coor.y += coor.y_inc;
		}
		coor.x_pix++;
		coor.x += coor.x_inc;
	}
	return (0);
}
