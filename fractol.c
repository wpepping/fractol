/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:36:53 by wpepping          #+#    #+#             */
/*   Updated: 2024/07/12 15:35:31 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init(t_fractol *data)
{
	int	temp;

	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, X, Y, "fract-ol");
	data->image = mlx_new_image(data->mlx, X, Y);
	data->imgbuff = mlx_get_data_addr(data->image, &temp,
			&(data->lsize), &(data->endian));
	data->zoom = 1;
	data->offset_x = 0;
	data->offset_y = 0;
}

static void	init_events(t_fractol *data)
{
	mlx_key_hook(data->window, &handle_input, data);
	mlx_mouse_hook(data->window, &handle_zoom, data);
	mlx_hook(data->window, DestroyNotify, StructureNotifyMask,
		&handle_close, data);
}

static int	check_input(t_fractol *data, int argc, char *argv[])
{
	if (argc == 1 || (argc == 2 && ft_strncmp(argv[1], "-m", 3) == 0))
		data->function = &mandel;
	else if (argc == 4 && ft_strncmp(argv[1], "-j", 3) == 0
		&& atod(argv[2], &(data->julia_start.real))
		&& atod(argv[3], &(data->julia_start.imag)))
		data->function = &julia;
	else
		return (0);
	return (1);
}

static void	print_help(void)
{
	ft_putendl_fd("Usage: fractol [-m | -j <x> <y>]", 1);
	ft_putendl_fd("  -m     Mandelbrot", 1);
	ft_putendl_fd("  -j     Julia; x, y is the starting point", 1);
}

int	main(int argc, char *argv[])
{
	t_fractol	data;

	if (check_input(&data, argc, argv))
	{
		init(&data);
		crimage(data, data.function);
		mlx_put_image_to_window(data.mlx, data.window, data.image, 0, 0);
		init_events(&data);
		mlx_loop(data.mlx);
		mlx_destroy_window(data.mlx, data.window);
		mlx_destroy_image(data.mlx, data.image);
		mlx_destroy_display(data.mlx);
		free(data.mlx);
	}
	else
		print_help();
	return (0);
}
