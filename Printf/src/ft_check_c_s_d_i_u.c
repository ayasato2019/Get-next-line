/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_c_s_d_i_u.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysato <aysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 12:31:07 by aysato            #+#    #+#             */
/*   Updated: 2022/04/22 00:31:55 by aysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_output_char(int c)
{
	return (write(1, &c, sizeof(char)));
}

ssize_t	ft_check_string(char *str)
{
	ssize_t	length;

	length = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[length] != '\0')
	{
		write(1, &str[length], 1);
		length++;
	}
	return (length);
}

ssize_t	ft_check_int(int num)
{
	size_t			minus;

	minus = 0;
	if (num < 0)
	{
		minus = ft_check_length(num, 10);
		write(1, "-", 1);
		ft_check_base(num * -1UL, 10, 0);
		return (minus + 1);
	}
	ft_check_base(num, 10, 0);
	return (ft_check_length(num, 10));
}

ssize_t	ft_check_uint(unsigned int num)
{
	ft_check_base(num, 10, 0);
	return (ft_check_length(num, 10));
}
