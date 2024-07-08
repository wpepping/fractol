/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:50:06 by wpepping          #+#    #+#             */
/*   Updated: 2024/07/01 17:52:54 by wpepping         ###   ########.fr       */
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
