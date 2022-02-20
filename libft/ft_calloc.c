/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysato <aysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:46:13 by aysato            #+#    #+#             */
/*   Updated: 2022/01/30 21:02:55 by aysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*dst;

	if (count == 0 || size == 0)
	{
		dst = malloc(sizeof(char) * 1);
		if (dst == 0)
			return (0);
		ft_bzero(dst, size * count);
	}
	dst = malloc(count * size);
	if (!dst)
		return (NULL);
	ft_bzero(dst, size * count);
	return (dst);
}
