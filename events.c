/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:50:06 by wpepping          #+#    #+#             */
/*   Updated: 2024/07/11 20:29:51 by wpepping         ###   ########.fr       */
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
	{
		mlx_loop_end(data->mlx);
	}
	if (keycode == XK_Right)
		data->offset_x -= 0.1 * data->zoom;
	if (keycode == XK_Left)
		data->offset_x += 0.1 * data->zoom;
	if (keycode == XK_Up)
		data->offset_y -= 0.1 * data->zoom;
	if (keycode == XK_Down)
		data->offset_y += 0.1 * data->zoom;
	if (keycode == XK_Right || keycode == XK_Left
		|| keycode == XK_Up || keycode == XK_Down)
	{
		crimage(*data, data->function);
		mlx_put_image_to_window(data->mlx, data->window, data->image, 0, 0);
	}
	return (0);
}

int	handle_close(t_fractol *data)
{
	mlx_loop_end(data->mlx);
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
	crimage(*data, data->function);
	mlx_put_image_to_window(data->mlx, data->window, data->image, 0, 0);
	return (0);
}
