/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:36:53 by wpepping          #+#    #+#             */
/*   Updated: 2024/07/10 15:36:48 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	t_fractol	data;
	int			temp;

	data.mlx = mlx_init();
	data.window = mlx_new_window(data.mlx, X, Y, "fract-ol");
	data.image = mlx_new_image(data.mlx, X, Y);
	data.imgbuff = mlx_get_data_addr(data.image, &temp,
			&(data.lsize), &(data.endian));
	data.zoom = 1;
	data.offset_x = 0;
	data.offset_y = 0;
	ft_image(data, &mandel);
	mlx_put_image_to_window(data.mlx, data.window, data.image, 0, 0);
	mlx_loop_hook(data.mlx, &handle_loop, &data);
	mlx_key_hook(data.window, &handle_input, &data);
	mlx_mouse_hook(data.window, &handle_zoom, &data);
	mlx_hook(data.window, DestroyNotify, StructureNotifyMask,
		&handle_close, &data);
	mlx_loop(data.mlx);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
	return (0);
}
