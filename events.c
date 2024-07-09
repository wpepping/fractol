/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:50:06 by wpepping          #+#    #+#             */
/*   Updated: 2024/07/09 20:41:18 by wpepping         ###   ########.fr       */
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
	int		dist_x;
	int		dist_y;
	double	direction;

	dist_x = X / 2 - x;
	dist_y = Y / 2 - y;
	if (button == 4)
	{
		direction = -1;
		data->zoom = data->zoom / ZOOM_FACTOR;
	}
	if (button == 5)
	{
		direction = 1;
		data->zoom = data->zoom * ZOOM_FACTOR;
	}
	data->offset_x += direction * dist_x / X / SCALE * ZOOM_FACTOR;
	data->offset_y += direction * dist_y / Y / SCALE * ZOOM_FACTOR;
	ft_image(*data, &mandel);
	mlx_put_image_to_window(data->mlx, data->window, data->image, 0, 0);
	return (0);
}
