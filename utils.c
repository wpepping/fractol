/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:53:51 by wpepping          #+#    #+#             */
/*   Updated: 2024/07/11 19:00:09 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i += 1;
	}
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}

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

static int	get_sign(char **str)
{
	if (**str == '-')
	{
		(*str)++;
		return (-1);
	}
	return (1);
}

double	atod(char *str, double *res)
{
	int		dec;
	int		sign;

	*res = 0;
	sign = get_sign(&str);
	if ((*str < '0' || *str > '9') && (*str != '.' || *(str + 1) == '\0'))
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		*res = *res * 10;
		*res += *(str++) - '0';
	}
	if (*str == '\0')
		return (1);
	if (*(str++) != '.')
		return (0);
	dec = 1;
	while (*str >= '0' && *str <= '9')
		*res += 1.0 * (*(str++) - '0') / pow(10, dec++);
	*res *= sign;
	if (*str != '\0')
		return (0);
	return (1);
}

void	ft_putendl_fd(char *s, int fd)
{
	while (*s != '\0')
		write(fd, s++, 1);
	write(fd, "\n", 1);
}
