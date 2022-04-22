/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ptr_pct_x_X.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysato <aysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:14:58 by aysato            #+#    #+#             */
/*   Updated: 2022/04/22 12:40:35 by aysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

ssize_t	ft_check_pointer(size_t num)
{
	write(1, "0x", 2);
	ft_check_base(num, 16, 0);
	if (num == 0)
		return (3);
	return (ft_check_length_pointer(num, 16) + 2);
}

ssize_t	ft_check_hex(unsigned int num, int x)
{
	ssize_t	minus;

	minus = 0;
	ft_check_base(num, 16, x);
	if (num == 0)
		return (1);
	return (ft_check_length(num, 16));
}

int	ft_check_percent(void)
{
	write(1, "%", 1);
	return (1);
}
