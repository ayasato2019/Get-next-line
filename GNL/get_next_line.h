/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysato <aysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 22:56:12 by aysato            #+#    #+#             */
/*   Updated: 2022/03/09 22:18:31 by aysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <errno.h>

char			*get_next_line(int fd);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			*ft_substr(char const *s, unsigned int start, size_t len);

#endif