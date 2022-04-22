/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysato <aysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:23:03 by aysato            #+#    #+#             */
/*   Updated: 2022/04/22 11:40:21 by aysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include <libgen.h>
# include <ctype.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

ssize_t		ft_printf(const char *fomat, ...);
ssize_t		ft_check_fomat(int c, va_list args);
int			ft_output_char(int c);
int			ft_check_overflow(int lengs, size_t printf_length);

ssize_t		ft_check_string(char *str);
ssize_t		ft_putrstr(char *str);
ssize_t		ft_check_int(int n);
ssize_t		ft_check_uint(unsigned int num);
ssize_t		ft_check_hex(unsigned int num, int x);
ssize_t		ft_check_pointer(size_t num);
int			ft_check_percent(void);

void		ft_check_base(size_t num, int base, int x_X);
size_t		ft_check_length(ssize_t num, int base);
size_t		ft_check_length_pointer(size_t num, int base);

#endif