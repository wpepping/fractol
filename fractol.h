/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:50:56 by wpepping          #+#    #+#             */
/*   Updated: 2024/07/01 17:54:08 by wpepping         ###   ########.fr       */
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

typedef struct s_fractol
{
	void	*mlx;
	void	*window;
}	t_fractol;

int	mandel(double complex c);
int	handle_loop(void);
int	handle_input(int keycode, t_fractol *data);
int	handle_close(t_fractol *data);
int	get_color(int r, int g, int b);

#endif
