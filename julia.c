/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:36:33 by wpepping          #+#    #+#             */
/*   Updated: 2024/07/12 15:18:21 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_fractol data, t_complex z, char *result)
{
	double	temp;
	int		i;

	i = 0;
	while (c_real(z) * c_real(z) + c_imag(z) * c_imag(z) <= R_SQ
		&& i < MAX_ITERATIONS)
	{
		temp = c_real(z) * c_real(z) - c_imag(z) * c_imag(z)
			+ c_real(data.julia_start);
		z.imag = 2.0 * c_real(z) * c_imag(z) + c_imag(data.julia_start);
		z.real = temp;
		i++;
	}
	if (c_abs_square((t_complex){c_real(z), c_imag(z)}) <= R_SQ)
		get_color(data, (int []){230, 230, 255}, result);
	else if (i < 8)
		get_color(data, (int []){0, 0, 60}, result);
	else if (i > 80)
		get_color(data, (int []){255, 255, 0}, result);
	else
		get_color(data, (int []){2.5 * (i - 8), 2.5 * (i - 8),
			60 + (i - 8) * 2.5}, result);
}
