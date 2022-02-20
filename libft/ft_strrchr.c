/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysato <aysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:47:39 by aysato            #+#    #+#             */
/*   Updated: 2022/01/29 23:16:26 by aysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*copy;
	char		c_char;

	copy = s;
	c_char = (char)c;
	while (*copy)
		copy++;
	if (c_char == '\0')
		return ((char *)copy);
	copy -= 1;
	while (copy >= s)
	{
		if (c_char == *copy)
			return ((char *)copy);
		copy--;
	}
	return (NULL);
}
