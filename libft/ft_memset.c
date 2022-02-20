/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysato <aysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 17:15:18 by aysato            #+#    #+#             */
/*   Updated: 2022/01/29 23:14:44 by aysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*cpy;
	unsigned char	ch;

	ch = c;
	cpy = (unsigned char *)b;
	while (len)
	{
		*cpy = ch;
		cpy++;
		len--;
	}
	return (b);
}
