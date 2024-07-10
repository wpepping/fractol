/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:50:56 by wpepping          #+#    #+#             */
/*   Updated: 2024/07/10 16:31:54 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/keysym.h>
# include "minilibx/mlx.h"
# include "minilibx/mlx_int.h"

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
	int		lsize;
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

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

int			handle_loop(void);
int			handle_input(int keycode, t_fractol *data);
int			handle_close(t_fractol *data);
int			handle_zoom(int button, int x, int y, t_fractol *data);
void		get_color(t_fractol data, int c[3], char *result);
void		*ft_memcpy(void *dest, const void *src, size_t n);
int			ft_image(t_fractol data, void (*f)(t_fractol f,
					t_complex c, char *r));
void		mandel(t_fractol data, t_complex c, char *result);
double		pix2val(t_fractol data, int n, int xy);
double		c_real(t_complex c);
double		c_imag(t_complex c);
double		c_abs(t_complex c);
t_complex	c_square(t_complex c);
t_complex	c_add(t_complex c, t_complex d);

#endif
