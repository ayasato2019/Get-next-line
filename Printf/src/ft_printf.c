/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysato <aysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 05:55:21 by aysato            #+#    #+#             */
/*   Updated: 2022/04/22 12:40:11 by aysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

ssize_t	ft_check_format(int c, va_list args)
{
	ssize_t	length;

	length = 0;
	if (c == 'c')
		length = ft_output_char(va_arg(args, int));
	else if (c == 's')
		length = ft_check_string(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		length = ft_check_int(va_arg(args, int));
	else if (c == 'p')
		length = ft_check_pointer(va_arg(args, size_t));
	else if (c == 'u')
		length = ft_check_uint(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		length = ft_check_hex(va_arg(args, unsigned int), c);
	else if (c == '%')
		length = ft_check_percent();
	return (length);
}

ssize_t	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(arg, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == '\0')
			break ;
		if (format[i] == '%')
		{
			length = ft_check_overflow(length,
					ft_check_format(format[i + 1], arg));
			i++;
		}
		else
			length += ft_output_char(format[i]);
		i++;
	}
	va_end(arg);
	return (length);
}

int	ft_check_overflow(int length, size_t printf_length)
{
	if (printf_length >= INT_MAX || length + printf_length >= INT_MAX)
		return (-1);
	return (length + printf_length);
}
