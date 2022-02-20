/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysato <aysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 09:16:20 by aysato            #+#    #+#             */
/*   Updated: 2022/01/29 23:14:38 by aysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dst_copy;
	unsigned char	*src_copy;

	dst_copy = (unsigned char *)dst;
	src_copy = (unsigned char *)src;
	if (len == 0 || src == dst)
		return (dst);
	if (src_copy > dst_copy)
	{
		i = 0;
		while (i < len)
		{
			dst_copy[i] = src_copy[i];
			i++;
		}
	}
	else if (dst_copy > src_copy)
	{
		i = len;
		while (i--)
			dst_copy[i] = src_copy[i];
	}
	return (dst);
}
