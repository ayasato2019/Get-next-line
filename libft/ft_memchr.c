/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysato <aysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:52:34 by aysato            #+#    #+#             */
/*   Updated: 2022/01/30 20:58:26 by aysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (s != (void *)0 || n != 0)
	{
		while (n > i)
		{
			if (*(unsigned char *)(s + i) == (unsigned char)c)
			{
				if (((unsigned char *)(s + i)) < 0)
					return (NULL);
				return ((void *)(s + i));
			}
			i++;
		}
		return (NULL);
	}
	return (NULL);
}
