/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysato <aysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:51:33 by aysato            #+#    #+#             */
/*   Updated: 2022/01/29 23:16:10 by aysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (0 < n)
	{
		if (*s1 != *s2 || (*s1 == '\0' || *s2 == '\0'))
			return (((unsigned char)*s1) - ((unsigned char)*s2));
		s1++;
		s2++;
		n--;
	}
	return (0);
}
