/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:50:56 by wpepping          #+#    #+#             */
/*   Updated: 2024/07/09 19:26:39 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <complex.h>
# include <math.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include "mlx.h"
# include "mlx_int.h"
# include <unistd.h>

# define X 640
# define Y 640
# define MAX_ITERATIONS 100
# define ZOOM_FACTOR 1.05
# define SCALE 2

typedef struct s_fractol
{
	void	*mlx;
	void	*window;
	void	*image;
	char	*imgbuff;
	int		endian;
	double	zoom;
	double	offset_x;
	double	offset_y;
}	t_fractol;

typedef struct s_xy
{
	double	x;
	double	y;
	int		x_pix;
	int		y_pix;
	double	x_inc;
	double	y_inc;
	double	y_start;
}	t_xy;

int		handle_loop(void);
int		handle_input(int keycode, t_fractol *data);
int		handle_close(t_fractol *data);
int		handle_zoom(int button, int x, int y, t_fractol *data);
void	get_color(t_fractol data, int c[3], char *result);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_image(t_fractol data, void (*f)(t_fractol f,
			double complex c, char *r));
void	mandel(t_fractol data, double complex c, char *result);

#endif
