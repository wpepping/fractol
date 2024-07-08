/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:36:53 by wpepping          #+#    #+#             */
/*   Updated: 2024/07/01 17:56:50 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color_image(void *mlx, void *window, int (*f)(double complex c))
{
	double	x;
	double	y;
	double	x_inc;
	double	y_inc;
	int		color;

	x_inc = 4.0 / X;
	y_inc = 4.0 / Y;
	x = -2;
	while (x < 2)
	{
		y = -2;
		while (y < 2)
		{
			color = (*f)(x + y * _Complex_I);
			mlx_pixel_put(mlx, window, (x + 2) * X / 4, (y + 2) * Y / 4, color);
			y += y_inc;
		}
		x += x_inc;
	}
	return (0);
}

int	main(void)
{
	t_fractol	data;

	data.mlx = mlx_init();
	data.window = mlx_new_window(data.mlx, X, Y, "fract-ol");
	mlx_loop_hook(data.mlx, &handle_loop, &data);
	mlx_key_hook(data.window, &handle_input, &data);
	mlx_hook(data.window, DestroyNotify, StructureNotifyMask,
		&handle_close, &data);
	color_image(data.mlx, data.window, &mandel);
	mlx_loop(data.mlx);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
	return (0);
}
