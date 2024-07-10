/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:50:06 by wpepping          #+#    #+#             */
/*   Updated: 2024/07/10 15:51:56 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_loop(void)
{
	return (0);
}

int	handle_input(int keycode, t_fractol *data)
{
	if (keycode == XK_Escape)
		mlx_destroy_window(data->mlx, data->window);
	return (0);
}

int	handle_close(t_fractol *data)
{
	mlx_destroy_window(data->mlx, data->window);
	return (0);
}

int	handle_zoom(int button, int x, int y, t_fractol *data)
{
	double	x_real;
	double	y_real;

	x_real = pix2val(*data, x, 0);
	y_real = pix2val(*data, y, 1);
	if (button == 4)
		data->zoom = data->zoom / ZOOM_FACTOR;
	if (button == 5)
		data->zoom = data->zoom * ZOOM_FACTOR;
	data->offset_x = x_real + (1.0 - 2.0 * x / X) * SCALE * data->zoom;
	data->offset_y = y_real + (1.0 - 2.0 * y / Y) * SCALE * data->zoom;
	ft_image(*data, &mandel);
	mlx_put_image_to_window(data->mlx, data->window, data->image, 0, 0);
	return (0);
}
