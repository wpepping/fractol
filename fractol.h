/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:50:56 by wpepping          #+#    #+#             */
/*   Updated: 2024/07/13 15:41:47 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include "minilibx/mlx.h"

# define X 640
# define Y 640
# define MAX_ITERATIONS 100
# define ZOOM_FACTOR 1.05
# define SCALE 2
# define R_SQ 4

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

typedef struct s_fractol
{
	void		*mlx;
	void		*window;
	void		*image;
	char		*imgbuff;
	int			endian;
	int			lsize;
	double		zoom;
	double		offset_x;
	double		offset_y;
	void		*function;
	t_complex	julia_start;
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

int			ft_strncmp(const char *s1, const char *s2, size_t n);
double		atod(char *str, double *res);
void		ft_putendl_fd(char *s, int fd);
int			handle_loop(void);
int			handle_input(int keycode, t_fractol *data);
int			handle_close(t_fractol *data);
int			handle_zoom(int button, int x, int y, t_fractol *data);
void		get_color(t_fractol *data, int c[3], char *result);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		crimage(t_fractol *data, void (*f)(t_fractol *f,
					t_complex c, char *r));
double		pix2val(t_fractol *data, int n, int xy);
double		c_real(t_complex c);
double		c_imag(t_complex c);
double		c_abs_square(t_complex c);
t_complex	c_square(t_complex c);
t_complex	c_add(t_complex c, t_complex d);
void		mandel(t_fractol *data, t_complex c, char *result);
void		julia(t_fractol *data, t_complex c, char *result);

#endif
