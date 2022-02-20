/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysato <aysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 08:37:01 by aysato            #+#    #+#             */
/*   Updated: 2022/01/29 23:13:11 by aysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_transform_char(char *a, size_t nmb, unsigned int i)
{
	while (nmb > 0)
	{
		a[i] = 48 + (nmb % 10);
		nmb = nmb / 10;
		i--;
	}
	return (a);
}

static size_t	ft_degits(int n)
{
	size_t	count;

	count = 0;
	if (n <= 0)
		count = 1;
	while (n != 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char			*dest;
	size_t			size;
	unsigned int	nmb;
	int				neg;

	neg = 1;
	size = (size_t)ft_degits(n);
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!(dest))
		return (NULL);
	size -= 1;
	dest[size + 1] = '\0';
	if (n == 0)
		dest[0] = '0';
	nmb = n;
	if (n < 0)
	{
		neg *= -1;
		nmb *= -1;
		dest[0] = '-';
	}
	dest = ft_transform_char(dest, nmb, size);
	return (dest);
}
