/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysato <aysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:36:00 by aysato            #+#    #+#             */
/*   Updated: 2022/04/22 11:38:45 by aysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	ft_check_length(ssize_t num, int base)
{
	size_t	length;

	length = 0;
	while (num != 0)
	{
		num = num / base;
		length++;
	}
	if (length == 0)
		return (1);
	return (length);
}

size_t	ft_check_length_pointer(size_t num, int base)
{
	size_t	length;

	length = 0;
	while (num != 0)
	{
		num = num / base;
		length++;
	}
	return (length);
}

void	ft_check_base(size_t num, int base, int x_X)
{
	size_t	over_num;
	char	dest;

	over_num = num % base;
	num = num / base;
	if (0 != num)
		ft_check_base(num, base, x_X);
	if (0 <= over_num && over_num <= 9)
		dest = '0' + over_num;
	else if (9 < over_num)
	{
		if (x_X == 'X')
			dest = 'A' + (over_num - 10);
		else
			dest = 'a' + (over_num - 10);
	}
	write(1, &dest, 1);
}
