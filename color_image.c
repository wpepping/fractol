/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:38:33 by wpepping          #+#    #+#             */
/*   Updated: 2024/07/10 16:21:45 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_image(t_fractol data, void (*f)(t_fractol f, t_complex, char *r))
{
	t_xy	xy;
	char	color[4];

	xy.x_inc = 4.0 * data.zoom / X;
	xy.y_inc = 4.0 * data.zoom / Y;
	xy.x_pix = 0;
	xy.x = pix2val(data, 0, 0);
	xy.y_start = pix2val(data, 0, 1);
	while (xy.x_pix < X)
	{
		xy.y_pix = 0;
		xy.y = xy.y_start;
		while (xy.y_pix < Y)
		{
			(*f)(data, (t_complex){xy.x, xy.y}, color);
			ft_memcpy(data.imgbuff + (xy.y_pix * data.lsize + xy.x_pix * 4),
				color, 4);
			xy.y_pix++;
			xy.y += xy.y_inc;
		}
		xy.x_pix++;
		xy.x += xy.x_inc;
	}
	return (0);
}
