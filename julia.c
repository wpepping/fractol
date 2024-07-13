/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:36:33 by wpepping          #+#    #+#             */
/*   Updated: 2024/07/13 15:30:19 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_fractol *data, t_complex z, char *result)
{
	int		i;

	i = 0;
	while (c_real(z) * c_real(z) + c_imag(z) * c_imag(z) <= R_SQ
		&& i < MAX_ITERATIONS)
	{
		z = c_add(c_square(z), data->julia_start);
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
