/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:53:51 by wpepping          #+#    #+#             */
/*   Updated: 2024/07/09 19:41:55 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*p;

	if (dest == NULL && src == NULL)
		return (dest);
	i = 0;
	p = dest;
	while (i < n)
	{
		*(p + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dest);
}

void	get_color(t_fractol data, int c[3], char *result)
{
	int	color;

	color = (c[0] * 256 * 256 + c[1] * 256 + c[2]);
	color = mlx_get_color_value(data.mlx, color);
	ft_memcpy(result, &color, 4);
}

